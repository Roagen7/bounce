//
// Created by roagen on 02.08.2021.
//

#include "Ball.h"

#include <utility>




Vec Ball::getPos() {
    return this->pos;
}

float Ball::getRadius() const {
    return this->radius;
}

rgb Ball::getColor() {
    return this->color;
}



Ball::Ball(Vec pos, float radius, float mass,std::tuple<float,float,float> color) {
    this->pos = std::move(pos);
    this->radius = radius;
    this->radius =  mass; //radius mass 1:1s
    this->mass = mass;
    this->color = color;
}

Ball::Ball() {
    this->pos = Vec();
    this->radius = 0.f;
    this->color = std::make_tuple(0.f,0.f,0.f);
}

void Ball::updateBall(Vec scrSize, std::vector<Ball> &balls) {
    this->pos = this->pos + this->vel;
    if(this->vel.len() != 0){
        this->acc = this->vel * -1 * FRICTION_COEFF;
        this->vel = this->vel + this->acc;
    }
    std::cout << this->vel << " " << this->acc << std::endl;

    if(this->pos[0] + this->radius > scrSize[0]){
        this->vel.setV(0,this->vel[0]*-1);
        this->pos.setV(0,scrSize[0] - this->radius);
    }
    if(this->pos[1] + this->radius > scrSize[1]){
        this->vel.setV(1,this->vel[1] * -1);
        this->pos.setV(1,scrSize[1] - this->radius);
    }
    if(this->pos[1] - this->radius < 0){
        this->vel.setV(1,this->vel[1] * -1);
        this->pos.setV(1,this->radius);
    }
    if(this->pos[0] - this->radius < 0){
        this->vel.setV(0,this->vel[0] * -1);
        this->pos.setV(0,this->radius);
    }

    for(auto &ball : balls){
        auto l = (ball.getPos() - this->getPos()).len();

        if(l <= this->getRadius() + ball.getRadius()  && l != 0){
            //std::cout << "collision" << std::endl;
            Ball::collide(*this,ball);
            //std::cout << std::sqrt(Vec::dot(d,d)) << std::endl;
            //this->vel.setV(0,this->vel[0] * -1);
            //this->vel.setV(1,this->vel[1] * -1);
            //ball.vel.setV(0,ball.vel[0] * -1);
            //this->setVel(this->getVel() * -1);
            //.setVel(ball.getVel() * -1);




        }


        auto v2 = ball.getVel();

    }





}

void Ball::setVel(Vec vel) {
    this->vel = vel;
}

Vec Ball::getVel() {
    return this->vel;
}

void Ball::setPos(Vec pos) {
    this->pos = pos;
}

void Ball::collide(Ball &b1, Ball &b2) {
    /*
    auto tempVel = b1.getVel();
    b1.setVel(b2.getVel());
    b2.setVel(tempVel);
     */
    auto x1 = b1.getPos();
    auto x2 = b2.getPos();
    auto m1 = b1.getMass();
    auto m2 = b2.getMass();
    auto v1 = b1.getVel();
    auto v2 = b2.getVel();

    Vec v1p = v1 - (x1 - x2)  *  Vec::dot(v1-v2,x1-x2)   *  2 * m2 /(m1 + m2) / ((x2 - x1).len()*(x2-x1).len());
    Vec v2p = v2 - (x2 - x1)  *  Vec::dot(v2-v1,x2-x1)   *  2 * m1 /(m1 + m2) / ((x2 - x1).len()*(x2-x1).len())  ;
    b1.setVel(v1p);
    b2.setVel(v2p);
    b1.pos = b1.pos + b1.vel;
    b2.pos = b2.pos + b2.vel;

}

float Ball::getMass() const {
    return this->mass;
}

