//
// Created by roagen on 02.08.2021.
//
#pragma once

#include <vector>
#include <iostream>
#include <math.h>

#ifndef SFML_TEST_VEC_H
#define SFML_TEST_VEC_H


class Vec {
private:
    std::vector<float> v;
public:
    explicit Vec(std::vector<float> v);
    Vec();

    friend Vec operator+ (Vec v1, Vec v2);
    friend Vec operator- (Vec v1, Vec v2);
    friend Vec operator/ (Vec v, float d);
    friend Vec operator* (Vec v, float d);
    friend bool operator==(Vec v1, Vec v2);
    friend std::ostream& operator<<(std::ostream& os, const Vec& v1);
    float operator[](int index);

    std::vector<float> getV();
    void setV(int index, float value);
    Vec normalize();
    float len();
    std::pair<Vec,Vec> splitAlongDir(Vec dir);

    static float dot(Vec v1, Vec v2);
    //static Vec cross(Vec v1, Vec v2);




};


#endif //SFML_TEST_VEC_H
