#include <SFML/Graphics.hpp>
#include "command.hpp"

int main()
{
    // Create Main Display Window with original dimensions
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Asteroids");

    // Load Ship Sprite fro file
    sf::Texture shipTexture;
    if(!shipTexture.loadFromFile("sprites/ship.png"))
        return EXIT_FAILURE;

    sf::Sprite ship(shipTexture);
    ship.setScale(sf::Vector2f(0.25, 0.25));

    while (window.isOpen())
    {
        sf::Event event;
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
                    command = new RotateShipCommand(&ship, -7.5);
                    break;
                case sf::Keyboard::S:
                    /* decelerate */
                    break;
                case sf::Keyboard::D:
                    command = new RotateShipCommand(&ship, 7.5);
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
