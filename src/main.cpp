 #include <SFML/Graphics.hpp>
#include <iostream>

int main()
{


    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3.0.2 Test");
    window.setFramerateLimit(60);
            
std::cout<<"a";
   

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);
        
        window.display();
    }

    return 0;
}
