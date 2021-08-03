//
// Created by roagen on 02.08.2021.
//

#include "Ball.h"




Vec Ball::getPos() {
    return this->pos;
}

float Ball::getRadius() const {
    return this->radius;
}

rgb Ball::getColor() {
    return this->color;
}



Ball::Ball(Vec pos, float radius, std::tuple<float,float,float> color) {
    this->pos = pos;
    this->radius = radius;
    this->color = color;
}

Ball::Ball() {
    this->pos = Vec();
    this->radius = 0.f;
    this->color = std::make_tuple(0.f,0.f,0.f);
}

void Ball::updateBall(Vec scrSize, std::vector<Ball> &balls) {
    this->pos = this->pos + this->vel;
    //std::cout << scrSize[0] << std::endl;
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
        auto d = ball.getPos() - this->getPos();
        auto l = std::sqrt(Vec::dot(d,d));
        if(l <= ball.getRadius() + this->getRadius() && !(this->pos == ball.pos)){
            std::cout << "collision" << std::endl;
            std::cout << std::sqrt(Vec::dot(d,d)) << std::endl;
            this->vel.setV(0,this->vel[0] * -1);
            ball.vel.setV(0,ball.vel[0] * -1);
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

