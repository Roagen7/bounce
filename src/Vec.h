//
// Created by roagen on 02.08.2021.
//
#pragma once

#include <vector>
#include <iostream>

#ifndef SFML_TEST_VEC_H
#define SFML_TEST_VEC_H

typedef std::pair<float,float> vec2d;

class Vec {
private:
    std::vector<float> v;
public:
    Vec(std::vector<float> v);
    Vec();

    friend Vec operator+ (Vec v1, Vec v2);
    friend std::ostream& operator<<(std::ostream& os, const Vec& v1);
    float operator[](int index);


};


#endif //SFML_TEST_VEC_H
