#include <SFML/Graphics.hpp>

int main()
{
    // Create Main Display Window with original dimensions
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Asteroids");

    // Load Ship Sprite fro file
    sf::Texture texture;
    if(!texture.loadFromFile("sprites/ship.png"))
        return EXIT_FAILURE;

    sf::Sprite sprite(texture);
    sprite.setScale(sf::Vector2f(0.25, 0.25));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::W:
                    /* move up */
                    break;
                case sf::Keyboard::A:
                    /* move left */
                    break;
                case sf::Keyboard::S:
                    /* move down */
                    break;
                case sf::Keyboard::D:
                    /* move right */
                    break;
                case sf::Keyboard::Space:
                    /* shoot */
                    break;
                
                default:
                    break;
                }
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
