//
// Created by roagen on 02.08.2021.
//
#include <utility>
#include <string>
#include <tuple>


#ifndef SFML_TEST_BALL_H
#define SFML_TEST_BALL_H


typedef std::pair<float,float> vec2d;
typedef std::tuple<float,float,float> rgb;


class Ball {
private:
    vec2d pos, vel, acc;
    float radius;
    rgb color;
public:
    Ball(vec2d pos, float radius, rgb color);
    Ball();
    vec2d getPos();
    float getRadius() const;
    rgb getColor();
    void setVel(vec2d vel);

    void updateBall();

};


#endif //SFML_TEST_BALL_H
