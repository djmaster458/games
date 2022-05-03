#include <SFML/Graphics.hpp>
#include "command.hpp"

int main()
{
    // Create Main Display Window with original dimensions
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Asteroids");

    // Load Ship Sprite from file
    sf::Texture shipTexture;
    if(!shipTexture.loadFromFile("sprites/ship.png"))
        return EXIT_FAILURE;

    //Create and rescale sprite
    //Move to center
    sf::Sprite ship(shipTexture);
    ship.setOrigin(sf::Vector2f(128.0, 128.0));
    ship.setScale(sf::Vector2f(0.05, 0.05));
    ship.setPosition(sf::Vector2f(512, 384));

    //Create game clock
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        sf::Time deltaTime = clock.restart();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if(event.type == sf::Event::KeyPressed)
            {
                Command *command = nullptr;
                switch (event.key.code)
                {
                case sf::Keyboard::W:
                    /* accelerate */
                    break;
                case sf::Keyboard::A:
                    command = new RotateShipCommand(&ship, deltaTime, -360.0);
                    break;
                case sf::Keyboard::S:
                    /* decelerate */
                    break;
                case sf::Keyboard::D:
                    //command = new RotateShipCommand(&ship, deltaTime, 360.0);
                    ship.rotate(deltaTime.asSeconds() * 360.0);
                    break;
                case sf::Keyboard::Space:
                    /* shoot */
                    break;
                
                default:
                    break;
                }

                if(command)
                {
                    command->execute();
                    delete command;
                }   
            }
        }

        window.clear();
        window.draw(ship);
        window.display();
    }

    return 0;
}
