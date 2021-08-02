//
// Created by roagen on 02.08.2021.
//

#include "Game.h"
#include <iostream>
void Game::initVariables(){
    this->window = nullptr;
    this->bg_color = sf::Color(0,0,0,255);
    this->videoMode.height = 800;
    this->videoMode.width = 800;
    view = sf::View(sf::FloatRect(0,0,1000,1000));
    this->b1 = Ball(std::make_pair(500.f,500.f),100.f, std::make_tuple(0.f,0.f,0.f));
    this->b1.setVel(std::make_pair(10,10));
}


void Game::initWindow(){
    this->window = new sf::RenderWindow(this->videoMode, "Caption",
                                        sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
    this->window->setView(this->view);

}

Game::Game(){
    //srand(time(NULL));

    this->initVariables();
    this->initWindow();

}

bool Game::running() {
    return this->window->isOpen();
}

void Game::updateMousePositions(){
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::pollEvents(){
    while(this->window->pollEvent(this->ev)){
        switch(this->ev.type){

            case sf::Event::Closed:
                this->window->close();
                break;

                case sf::Event::KeyPressed:
                    if(this->ev.key.code == sf::Keyboard::Escape){
                        this->window->close();
                    }
                    break;

            default:
                break;
        }
    }
}

void Game::update(){
    this->pollEvents();
    this->updateMousePositions();
    this->b1.updateBall();

}

void Game::render(){
    this->window->clear(this->bg_color);
    auto sh = sf::RectangleShape();
    sh.setSize(sf::Vector2f(20,20));
    sh.setPosition(50,50);
    sh.setFillColor(sf::Color::Green);


    auto z = Vec({3,4,5});
    std::cout << z << std::endl;

    this->window->draw(sh);
    this->window->draw(this->getShape(this->b1));
    this->window->display();
}

sf::CircleShape Game::getShape(Ball ball) {
    auto cs = sf::CircleShape();
    cs.setRadius(ball.getRadius());
    cs.setPosition(ball.getPos().first, ball.getPos().second);
    cs.setFillColor(sf::Color::Green);
    return cs;
}
