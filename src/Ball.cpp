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

void Ball::updateBall() {
    this->pos = this->pos + this->vel;
}

void Ball::setVel(Vec vel) {
    this->vel = vel;
}

