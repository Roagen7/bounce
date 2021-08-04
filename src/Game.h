//
// Created by roagen on 02.08.2021.
//

#ifndef SFML_TEST_GAME_H
#define SFML_TEST_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Ball.h"
#include "Vec.h"
#include "Polygon.h"

class Game {
private:
    sf::RenderWindow* window{};
    sf::View view;
    sf::Event ev{};
    sf::VideoMode videoMode;
    sf::Color bg_color;
    sf::Vector2i mousePosWindow;
    std::vector<Ball> balls;
    Ball playerBall;
    Polygon hex;
    Polygon hex2;

    void initVariables();
    void initWindow();

    static sf::CircleShape getShape(Ball ball);
    static sf::VertexArray getShape(Vec v, Vec initPos);
    static sf::ConvexShape getShape(Polygon p);

public:
    Game();

    void updatePlayerBall();

    bool running();
    void updateMousePositions();
    void pollEvents();
    void update();
    void render();

};


#endif //SFML_TEST_GAME_H
