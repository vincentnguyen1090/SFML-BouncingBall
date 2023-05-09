//
// Created by vince on 5/2/2023.
//

#include "BouncingBall.h"

BouncingBall::BouncingBall()
{
    sf::RenderWindow window(sf::VideoMode(1024, 720, 32), "Test");
    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Green);
    circle.setRadius(50.f);
    circle.setPosition(1024/2, 720/2);


    //speed of x and y
    float velocityX = 0.5f, velocityY = 0.5f;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        circle.move(velocityX, velocityY);
        //keeps circle within bounds of x-axis
        if (circle.getPosition().x + circle.getRadius() * 2 > window.getSize().x || circle.getPosition().x < 0)
        {
            velocityX = -velocityX;
        }
        //keeps circle withing bounds of y-axis
        if(circle.getPosition().y + circle.getRadius() * 2 > window.getSize().y || circle.getPosition().y < 0)
        {
            velocityY = -velocityY;
        }
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
}
