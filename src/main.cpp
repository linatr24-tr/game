 #include <SFML/Graphics.hpp>
#include <iostream>
#include "Karekter.h"
int main()
{


    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3.0.2 Test");
    window.setFramerateLimit(60);
            sf::Texture texture("kare.png");
            if (!texture.loadFromFile("kare.png")) {
        std::cerr << "Hata: kare.png yüklenemedi!" << std::endl;
        return -1; // Programı sonlandır
    }
            sf::Sprite sprite(texture);

   

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
