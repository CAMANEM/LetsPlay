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
    backtracking.reset();
    backtracking.setObstacles(board->getyPos(), board->getxPos(), squares);
    move = false;
}

void Game::update(){
    float deltaTime = 0.f;
    deltaTime = clock.restart().asSeconds();

    pollEvents();
    black->update(*window, deltaTime);

    board->A_Star(isPlayerTurn, x_ball_position, y_ball_position);


    updateDirectionLine();
    updateGameLogic();

    updateAllCollisions();

    if(!isPlayerTurn && secondFlag){
        backtracking.reset();
        backtracking.road(y_ball_position, x_ball_position);
        secondFlag = false;
    }

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
    sf::Vector2f p = sf::Vector2f(circle->getPosition());
    sf::Vector2f s = line->getPoints()[0].position;
    sf::Vector2f e = line->getPoints()[1].position;
    sf::Vector2f ps = p - s;
    sf::Vector2f se = e - s;
    float lengthLine = (e.x - s.x) * (e.x - s.x) + (e.y - s.y) * (e.y - s.y);
    float t = ((ps.x * se.x) + (ps.y * se.y)) /	lengthLine;
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



void Game::checkBallSquare(float x, float y) {
    int x_square = 0;
    int y_square = 0;

    while(103+(99.615384f*x_square)<x){
        x_square++;
    }
    while(70+(73.7777777f*y_square)<y){
        y_square++;
    }


    x_ball_position = x_square-1;
    y_ball_position = y_square-1;
}

void Game::updateGameLogic(){



    if (move && draggedBall->getVelocity() == sf::Vector2f(0.f, 0.f))
    {
        //aqui tengo que cambiar los turnos

        move = false;
        float a = draggedBall->getPosition().x;
        float b = draggedBall->getPosition().y;

        checkBallSquare(a, b);
        isPlayerTurn = !isPlayerTurn;
        if(!secondFlag){
            secondFlag = true;
        }

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

    if (!isPlayerTurn){
        Pathnode* start = backtracking.path.getHead();
        for (start; start->getNext() != nullptr; start =  start->getNext()) {

            int w = start->getY();
            int x = start->getX();
            int y = start->getNext()->getY();
            int z = start->getNext()->getX();

            if ((y == 4 and z ==11)or (y == 3 and z ==12)or(y == 5 and z ==12)or(y == 2 and z ==12)or(y == 6 and z ==12)  or (w == 4 and x ==11)or (w == 3 and x ==12)or(w == 5 and x ==12)or (w == 2 and x ==12)or(w == 6 and x ==12)){
                break;
            }

//            if(w==0){
//                w = 1;
//            }
//            if(x==0){
//                x = 1;
//            }
//            if(y==0){
//                y = 1;
//            }
//            if(z==0){
//                z = 1;
//            }
            sf::Vertex line_toDraw[] = {
                    sf::Vertex(sf::Vector2f(w * 99.615384f + 73.7777777f / 2 + 116.5f,
                                            x * 73.7777777f + 99.615384f / 2 + 55.5f)),
                    sf::Vertex(sf::Vector2f(y * 99.615384f + 73.7777777f / 2 + 116.5f,
                                            z * 73.7777777f + 99.615384f / 2 + 55.5f))
//                sf::Vertex(sf::Vector2f(start->getY() * 73.7777777f + 99.615384f / 2 + 55.5f,
//                                        start->getX() * 99.615384f + 73.7777777f / 2 + 116.5f)),
//                sf::Vertex(sf::Vector2f(start->getNext()->getY() * 73.7777777f + 99.615384f / 2 + 55.5f,
//                                        start->getNext()->getX() * 99.615384f + 73.7777777f / 2 + 116.5f))
            };
            window->draw(line_toDraw, 2, sf::Lines);


        //start = start->getNext();

        }

    }

    if (dragged)
    {
        window->draw(*direction);
    }



    window->display();
}