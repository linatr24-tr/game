 #include <SFML/Graphics.hpp>
#include <iostream>
#include "Karekter.h"
#include "Saha.h"
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
Karekter k1("kare.png");
   Karekter Top("top.png");

    while (window.isOpen())
    {
        float dt=k1.sat();
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
    k1.Gra(dt);
    Top.Gra(dt);
    Top.Sekme(sf::FloatRect({0.0f, 600.0f}, {800.0f, 1.0f}), dt);                 
// engel kontrolü
k1.Hareket(dt);               // tuş hareketi

       
        window.clear(sf::Color::White);
        window.draw(k1.Resim);
        window.draw(Top.Resim);
        window.display();
    }

    return 0;
}
