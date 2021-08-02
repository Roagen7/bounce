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


class Game {
private:
    sf::RenderWindow* window{};
    sf::View view;
    sf::Event ev{};
    sf::VideoMode videoMode;
    sf::Color bg_color;
    sf::Vector2i mousePosWindow;
    Ball b1;


    void initVariables();
    void initWindow();

    sf::CircleShape getShape(Ball ball);


public:
    Game();

    bool running();
    void updateMousePositions();
    void pollEvents();
    void update();
    void render();

};


#endif //SFML_TEST_GAME_H
