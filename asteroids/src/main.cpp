#include <SFML/Graphics.hpp>
#include "command.hpp"

#define ROTATE_SPEED 180.f

using namespace sf;
int main()
{
    // Create Main Display Window with original dimensions
    RenderWindow window(VideoMode(1024, 768), "Asteroids");

    // Load Ship Sprite from file
    Texture shipTexture;
    if (!shipTexture.loadFromFile("sprites/ship.png"))
        return EXIT_FAILURE;

    // Create, rescale, and center sprite
    Sprite ship(shipTexture);
    ship.setOrigin(Vector2f(128.0, 128.0));
    ship.setScale(Vector2f(0.1, 0.1));
    ship.setPosition(Vector2f(512, 384));

    // Create/Start game clock
    Clock clock;

    while (window.isOpen())
    {
        Event event;
        Time deltaTime = clock.restart();

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        /*
         * Rotation
         */
        Command *command = nullptr;
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            command = new RotateCommand(&ship, deltaTime, ROTATE_SPEED);
        }
        else if (Keyboard::isKeyPressed(Keyboard::A))
        {
            command = new RotateCommand(&ship, deltaTime, -ROTATE_SPEED);
        }

        if (command)
        {
            command->execute();
            delete command;
        }

        /*
         * Movement
         */
        if(Keyboard::isKeyPressed(Keyboard::W))
        {
            //Accelerate
            command = new MoveCommand(&ship, deltaTime, 50.f);
        }

        if(command)
        {
            command->execute();
            delete command;
        }

        window.clear(Color::Black);
        window.draw(ship);
        window.display();
    }

    return 0;
}
