#include <SFML/Graphics.hpp>
#include "command.hpp"
#include "ship.hpp"

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
    Sprite shipSprite(shipTexture);
    shipSprite.setOrigin(Vector2f(128.0, 128.0));
    shipSprite.setScale(Vector2f(0.1, 0.1));
    shipSprite.setPosition(Vector2f(512, 384));

    // Create/Start game clock
    Clock clock;
    Ship ship(shipSprite);

    while (window.isOpen())
    {
        Event event;
        float deltaTime = clock.restart().asSeconds();

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            ship.Rotate(ROTATE_SPEED, deltaTime);
        }
        else if(Keyboard::isKeyPressed(Keyboard::A))
        {
            ship.Rotate(-ROTATE_SPEED, deltaTime);
        }

        if(Keyboard::isKeyPressed(Keyboard::W))
        {
            ship.Accelerate(deltaTime);
        }
        else
        {
            ship.Decelerate();
        }

        ship.Move(deltaTime);

        // /*
        //  * Rotation
        //  */
        // Command *command = nullptr;
        // if (Keyboard::isKeyPressed(Keyboard::D))
        // {
        //     command = new RotateCommand(&ship, deltaTime, ROTATE_SPEED);
        // }
        // else if (Keyboard::isKeyPressed(Keyboard::A))
        // {
        //     command = new RotateCommand(&ship, deltaTime, -ROTATE_SPEED);
        // }

        // if (command)
        // {
        //     command->execute();
        //     delete command;
        // }

        // /*
        //  * Movement
        //  */
        // if(Keyboard::isKeyPressed(Keyboard::W))
        // {
        //     //Accelerate
        //     command = new MoveCommand(&ship, deltaTime, 50.f);
        // }

        // if(command)
        // {
        //     command->execute();
        //     delete command;
        // }

        window.clear(Color::Black);
        window.draw(shipSprite);
        window.display();
    }

    return 0;
}
