//
// Created by roagen on 02.08.2021.
//

#include "Vec.h"

Vec::Vec(std::vector<float> v) {
    this->v = v;
}
Vec::Vec(){

}

Vec operator+(Vec v1, Vec v2) {

    auto out = Vec();
    for(int i = 0; i < v1.v.size(); i++){
        float x = v1[i];
        float y = v2[i];
        out.v.push_back(x+y);
    }
    return out;

}

Vec operator-(Vec v1, Vec v2) {

    auto out = Vec();
    for(int i = 0; i < v1.v.size(); i++){
        float x = v1[i];
        float y = v2[i];
        out.v.push_back(x-y);
    }
    return out;

}




std::ostream &operator<<(std::ostream &os, const Vec& v) {

    std::string s;
    for(auto x : v.v){
        s += "[";
        s += std::to_string(x);
        s += "]\n";
    }
    std::cout << s << std::endl;
    os << s;
    return os;

}

float Vec::operator[](int index) {
    return this->v[index];
}

float Vec::dot(Vec v1, Vec v2) {
    float s = 0;
    for(int i = 0; i < v1.getV().size(); i++){
        auto x = v1[i];
        auto y = v2[i];
        s +=  x * y;
    }

    return s;
}

Vec operator/(Vec v, float d) {
    for(int i = 0; i < v.getV().size(); i++){
        v.setV(i,v[i]/d);
    }
    return v;
}

Vec operator*(Vec v, float d) {
    for(int i = 0; i < v.getV().size(); i++){
        v.setV(i,v[i]*d);
    }
    return v;
}

Vec Vec::normalize() {
    return *this / std::sqrt(Vec::dot(*this,*this));
}

std::vector<float> Vec::getV() {
    return this->v;
}

void Vec::setV(int index, float value) {
    this->v[index] = value;
}

//dir is a unit vector
std::pair<Vec, Vec> Vec::splitAlongDir(Vec dir) {
    dir = dir.normalize();
    auto v_par = dir*Vec::dot(dir,*this);
    auto v_perp = *this - v_par;
    return std::make_pair(v_par,v_perp);
}

bool operator==(Vec v1, Vec v2) {
    for(int i = 0; i < v1.getV().size(); i++){
        float x,y;
        x = v1.getV()[i];
        y = v2.getV()[i];
        if(x != y){
            return false;
        }
    }
    return true;
}


