//
// Created by roagen on 02.08.2021.
//

#include "Ball.h"




std::pair<float,float> Ball::getPos() {
    return this->pos;
}

float Ball::getRadius() const {
    return this->radius;
}

std::tuple<float,float,float> Ball::getColor() {
    return this->color;
}



Ball::Ball(std::pair<float,float> pos, float radius, std::tuple<float,float,float> color) {
    this->pos = pos;
    this->radius = radius;
    this->color = color;
}

Ball::Ball() {
    this->pos = std::make_pair(0.f,0.f);
    this->radius = 0.f;
    this->color = std::make_tuple(0.f,0.f,0.f);
}

void Ball::updateBall() {
    this->pos.first += this->vel.first;
    this->pos.second += this->vel.second;
}

void Ball::setVel(std::pair<float, float> vel) {
    this->vel = vel;
}

