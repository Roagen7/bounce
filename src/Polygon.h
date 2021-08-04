//
// Created by roagen on 04.08.2021.
//

#include <vector>
#include "Vec.h"

#ifndef SFML_TEST_POLYGON_H
#define SFML_TEST_POLYGON_H


class Polygon {
private:
    std::vector<Vec> vertices;
public:
    explicit Polygon(std::vector<Vec> vertices);
    Polygon();
    std::vector<Vec> getVerts();
    static std::vector<Vec> collisionSAT(Polygon& p1,  Polygon& p2);

};


#endif //SFML_TEST_POLYGON_H
