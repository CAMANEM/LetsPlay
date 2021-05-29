//
// Created by marco on 5/25/21.
//

#include "Game.h"
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>

Game::Game(int squares, int score) {
    initWindow();
    initGame(squares, score);
}

void Game::initWindow(){
    videoMode = sf::VideoMode(1500, 900);
    window = new sf::RenderWindow(videoMode, "Billiarrd", sf::Style::Default);
    window->setFramerateLimit(60);
}

void Game::initGame(int squares, int score) {
    LeftGoal.setSize(sf::Vector2f(99.615384f, 221.333333333f));
    LeftGoal.setPosition(103.f, 290.83333333f);
    LeftGoal.setFillColor(sf::Color(50, 105, 50));
    RightGoal.setSize(sf::Vector2(99.615384f, 221.333333333f));
    RightGoal.setPosition(102.5f+(12*99.615384f), 290.83333333f);
    RightGoal.setFillColor(sf::Color(50, 105, 50));

    dragged = false;
    max_score = score;
    player_score = 0;
    rival_score = 0;
    black = new Ball(sf::Vector2f(750, 400), 9.f, sf::Color::Black);
    board = new Board(squares);
    move = false;
}

void Game::update(){
    float deltaTime = 0.f;
    deltaTime = clock.restart().asSeconds();

    pollEvents();
    black->update(*window, deltaTime);

    updateDirectionLine();
    updateGameLogic();

    updateAllCollisions();

}

void Game::pollEvents() {
    while (window->pollEvent(event)) {
        switch (event.type){
            case sf::Event::Closed:
                window->close();
                break;

            case sf::Event::MouseButtonPressed:

                    if (black->checkCollisionPoint(m_mouse) && !move){
                        draggedBall = black;
                        dragged = true;
                    }

//                }
                break;
            case sf::Event::MouseButtonReleased:
                if (dragged){
                    draggedBall->setVelocity(sf::Vector2f((draggedBall->getPosition().x - m_mouse.x),
                                                          (draggedBall->getPosition().y - m_mouse.y)));
                    dragged = false;
                    move = true;
                }
                break;

            case sf::Event::MouseMoved:
                m_mouse.x = event.mouseMove.x;
                m_mouse.y = event.mouseMove.y;
        }

    }
}

void Game::collisionCircleLine(Ball *circle, Line *line){
    sf::Vector2f p = sf::Vector2f(circle->getPosition());	//center of circle
    sf::Vector2f s = line->getPoints()[0].position;			//point at start of line
    sf::Vector2f e = line->getPoints()[1].position;			//point at ent of line
    sf::Vector2f ps = p - s;
    sf::Vector2f se = e - s;
    float lengthLine = (e.x - s.x) * (e.x - s.x) + (e.y - s.y) * (e.y - s.y);
    float t = ((ps.x * se.x) + (ps.y * se.y)) /	lengthLine; //point of normal on line
    sf::Vector2f st;
    st.x = s.x + t*se.x;
    st.y = s.y + t*se.y;

    sf::Vector2f distance = p - st;
    float distanceBetween = sqrtf((distance.x*distance.x) + (distance.y*distance.y));

    sf::Vector2f normal = distance / distanceBetween;
    float dotProductNormal = circle->getVelocity().x*normal.x +
                             circle->getVelocity().y*normal.y;

    sf::Vector2f tangential = sf::Vector2f(-normal.y, normal.x);
    float dotProductTangential = circle->getVelocity().x*tangential.x +
                                 circle->getVelocity().y * tangential.y;

    float overlap = distanceBetween - circle->getRadius();
    if (distanceBetween <= circle->getRadius())
    {
        if (t > -0.f && t < 1.f)
        {
            circle->setPosition(p.x - distance.x * overlap / distanceBetween,
                                p.y -distance.y * overlap / distanceBetween);
            circle->setVelocity(sf::Vector2f(-normal.x*dotProductNormal + tangential.x*dotProductTangential,
                                             -normal.y*dotProductNormal + tangential.y*dotProductTangential));

        }
    }
}

//void Game::collisionCircles(Ball* ball1, Ball* ball2){
//    sf::Vector2f distance = ball1->getPosition() - ball2->getPosition();
//    float distanceBetween = (sqrtf((distance.x*distance.x) + (distance.y*distance.y)));
//    if (ball1 != ball2)
//    {
//        if (distanceBetween < (ball1->getRadius()+ball2->getRadius()))
//        {
//
//            float overlap = (distanceBetween - ball1->getRadius() - ball2->getRadius()) / 2.f;
//            float moveX = (overlap * (ball1->getPosition().x - ball2->getPosition().x) / distanceBetween);
//            float moveY = (overlap * (ball1->getPosition().y - ball2->getPosition().y) / distanceBetween);
//            ball1->setPosition(ball1->getPosition().x - moveX, ball1->getPosition().y - moveY);
//            ball2->setPosition(ball2->getPosition().x +  moveX, ball2->getPosition().y + moveY);
//
//            sf::Vector2f normal;
//            normal.x = distance.x / distanceBetween;
//            normal.y = distance.y / distanceBetween;
//
//            sf::Vector2f tangential;
//            tangential.x = -normal.y;
//            tangential.y =  normal.x;
//
//            float dotProductTangential1 = ball1->getVelocity().x*tangential.x +
//                                          ball1->getVelocity().y*tangential.y;
//            float dotProductTangential2 = ball2->getVelocity().x*tangential.x +
//                                          ball2->getVelocity().y*tangential.y;
//
//            float dotProductNormal1 = ball1->getVelocity().x*normal.x + ball1->getVelocity().y*normal.y;
//            float dotProductNormal2 = ball2->getVelocity().x*normal.x + ball2->getVelocity().y*normal.y;
//
//            float m1 = (2.f*ball2->getMass()*dotProductNormal2 +
//                        dotProductNormal1*(ball1->getMass() - ball2->getMass())) /
//                       (ball1->getMass()+ball2->getMass());
//            /*fixed high acceleration (m2 ~ ball1.mas - ball2.mas)*/
//            float m2 = (2.f*ball1->getMass()*dotProductNormal1 +
//                        dotProductNormal2*(ball2->getMass() - ball1->getMass())) /
//                       (ball1->getMass()+ball2->getMass());
//            ball1->setVelocity(dotProductTangential1*tangential + m1*normal);
//            ball2->setVelocity(dotProductTangential2*tangential + m2*normal);
//
//        }
//    }
//}

void Game::updateGameLogic(){

    if (move && draggedBall->getVelocity() == sf::Vector2f(0.f, 0.f))
    {
        move = false;
        float a = draggedBall->getPosition().x;
        float b = draggedBall->getPosition().y;
        if((103.0 < a && a < 205.0) && (291 < b && b < 512)){
            black->setPosition(750.f, 300.f);
            rival_score = rival_score + 1;
            if(rival_score == max_score){
                window->close();
            }
        } else if ((102.5f+(12*99.615384f) < a && a < 102.5f+(13*99.615384f)) && (290.83333333f < b && b < 512.16666666666666f)) {
            black->setPosition(750.f, 500.f);
            player_score = player_score + 1;
            if(player_score == max_score){
                window->close();
            }
        }
    }

}

void Game::updateAllCollisions(){
    for (Line line : board->getBorderLines()){
        collisionCircleLine(black, &line);
    }
}

void Game::updateDirectionLine()
{

    if (dragged)
    {
        sf::Vector2f distance = (m_mouse - draggedBall->getPosition());
        float distanceBetween = sqrt(distance.x*distance.x + distance.y*distance.y);
        sf::Vector2f invert = distance / distanceBetween;
        sf::Color directionColor = sf::Color(255, (255 - ((int)distanceBetween/2)%255), 0);
        if (distanceBetween > 510) { directionColor = sf::Color::Red; }
        direction = new Line(draggedBall->getPosition().x, draggedBall->getPosition().y,
                             draggedBall->getPosition().x - distanceBetween * invert.x,
                             draggedBall->getPosition().y - distanceBetween * invert.y, directionColor);
    }
}

void Game::render(){
    window->clear(sf::Color(75, 103, 163));
    window->draw(LeftGoal);
    window->draw(RightGoal);

    board->render(window);
    window->draw(*black);

    if (dragged)
    {
        window->draw(*direction);
    }
    window->display();
}