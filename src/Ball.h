//
// Created by roagen on 02.08.2021.
//
#include <utility>
#include <string>
#include <tuple>

#include "Vec.h"


#ifndef SFML_TEST_BALL_H
#define SFML_TEST_BALL_H


typedef std::pair<float,float> vec2d;
typedef std::tuple<float,float,float> rgb;


class Ball {
private:
    Vec pos, vel, acc;
    float radius;
    rgb color;
public:
    Ball(Vec pos, float radius, rgb color);
    Ball();
    Vec getPos();
    float getRadius() const;
    rgb getColor();
    void setVel(Vec vel);

    void updateBall();

};


#endif //SFML_TEST_BALL_H
