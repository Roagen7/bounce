//
// Created by roagen on 02.08.2021.
//

#include "Game.h"
#include <iostream>
void Game::initVariables(){
    this->window = nullptr;
    this->bg_color = sf::Color(255,255,255);
    this->videoMode.height = 1000;
    this->videoMode.width = 1000;
    view = sf::View(sf::FloatRect(0,0,1000,1000));


    for(int i = 0; i  < 10; i++){
        auto pos = Vec({0.f,0.f});
        auto vel = Vec({0.f,0.f});

        pos.setV(0,rand()%1000);
        pos.setV(1,rand()%1000);
        vel.setV(0,rand()%10 - 5);
        vel.setV(1,rand()%10 - 5);

        auto b = Ball(pos, 20.f, 10.f, std::make_tuple(rand()%255,rand()%255,rand()%255));
        b.setVel(vel);
        this->balls.push_back(b);

    }

    playerBall = Ball(Vec({0,0}),10.f,5,std::make_tuple(255,255,255));
    playerBall.setVel(Vec({0,0}));

    /*
    this->b1 = Ball(Vec({420,500}),20.f,10, std::make_tuple(255.f,0.f,0.f));
    this->b1.setVel(Vec({0,0}));
    this->b2 = Ball(Vec({720,800}),100.f,40, std::make_tuple(0.f,255.f,0.f));
    this->b2.setVel(Vec({-2,-2}));
    this->balls.push_back(b1);
    this->balls.push_back(b2);
    */

}


void Game::initWindow(){
    this->window = new sf::RenderWindow(this->videoMode, "Caption",sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
    this->window->setView(this->view);
}

Game::Game(){
    srand(time(NULL));
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

    sf::Vector2f z;
    z.x = this->videoMode.width;
    z.y = this->videoMode.height;

    auto newPos = Vec({0,0});




    if(this->mousePosWindow.x < this->videoMode.width && this->mousePosWindow.y < this->videoMode.height && this->mousePosWindow.x > 0 && this->mousePosWindow.y > 0){
        //std::cout << this->mousePosWindow.x << " " << this->mousePosWindow.y << std::endl;
        //std::cout << this->videoMode.width << " " << this->videoMode.height << std::endl;
        newPos.setV(0,this->mousePosWindow.x);
        newPos.setV(1,this->mousePosWindow.y);

        playerBall.setVel(newPos - playerBall.getPos());
        playerBall.setPos(newPos);

    }




    this->balls.push_back(playerBall);
    for(auto &ball : this->balls){
        ball.updateBall(Vec({z.x,z.y}), this->balls);
    }
    this->balls.pop_back();

}

void Game::render(){
    this->window->clear(this->bg_color);
    auto sh = sf::RectangleShape();

    //std::cout << Vec({12,5}).normalize()<<std::endl;

    /*
    sh.setSize(sf::Vector2f(20,20));
    sh.setPosition(50,50);
    sh.setFillColor(sf::Color::Green);
    */

    for(auto b1 : this->balls){
        this->window->draw(this->getShape(b1));
        /*
        this->window->draw(this->getShape(b1.getVel(), b1.getPos()));


        auto bop = b1.getVel().splitAlongDir(Vec({-1,0}));
        this->window->draw(this->getShape(bop.first,b1.getPos()));
        this->window->draw(this->getShape(bop.second,b1.getPos()));
        */
    }
    this->window->draw(this->getShape(this->playerBall));
    this->window->display();
   // this->window->draw(sh);


}


// visualize ball
sf::CircleShape Game::getShape(Ball ball) {
    auto cs = sf::CircleShape();
    cs.setRadius(ball.getRadius());
    cs.setPosition(ball.getPos()[0] - ball.getRadius(),ball.getPos()[1] - ball.getRadius());
    auto clr = sf::Color(std::get<0>(ball.getColor()), std::get<1>(ball.getColor()), std::get<2>(ball.getColor()));
    cs.setFillColor(clr);
    return cs;
}


// visualize 2d vector with origin at initPos
sf::VertexArray Game::getShape(Vec v, Vec initPos) {
    auto vx = sf::VertexArray(sf::LineStrip,2);
    vx[0].position = sf::Vector2f(initPos[0],initPos[1]);
    vx[1].position = sf::Vector2f((v * 10 + initPos)[0], (v * 10 + initPos)[1]);
    vx[0].color = sf::Color::White;
    vx[1].color = sf::Color::White;
    return vx;
}

void Game::updatePlayerBall() {

}
