//
// Created by roagen on 04.08.2021.
//

#include "Polygon.h"

Polygon::Polygon(std::vector<Vec> vertices) {
    this->vertices = vertices;
}

std::vector<Vec> Polygon::getVerts() {
    return this->vertices;
}

std::vector<Vec> Polygon::collisionSAT(Polygon& p1, Polygon& p2) {
    auto vert1 = p1.getVerts();
    std::vector<Vec>axis;
    for(int i = 0; i < vert1.size()-1; i++){
        auto v0 = vert1[i];
        auto v1 = vert1[i + 1];
//        std::cout << v0[0] << " " << v0[1] << std::endl;
//        std::cout << v1[0] << " " << v1[1] << std::endl;
        //std::cout << v1 - v0 << std::endl;

        axis.push_back((v1 - v0).normalize());

    }

    axis.push_back((vert1[vert1.size()-1] - vert1[0]).normalize());



    return axis;
}

Polygon::Polygon() = default;
