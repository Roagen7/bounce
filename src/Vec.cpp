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
