 #include <SFML/Graphics.hpp>
#include <iostream>
#include "Karekter.h"
#include "Saha.h"
int main()
{


    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3.0.2 Test");
    window.setFramerateLimit(60);
    Saha arkadort("beyazdik.png");
    Saha arkadort2("beyazdik.png");
    Saha arkadort3("beyazdik.png");
    arkadort.Dortgen(100, 100, 16, 336);
    arkadort2.Dortgen(100, 436, 160, 16);
    arkadort3.Dortgen(260, 100, 16, 336);
    
          
// Karekter k1("kare.png");
  // Karekter Top("top.png");

    while (window.isOpen())
    {
        // float dt=k1.sat();
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        sf::RenderStates states;
        states.texture = &arkadort.Dosya;
       
   // k1.Gra(dt);
    //Top.Gra(dt);
    //Top.Sekme(sf::FloatRect({0.0f, 600.0f}, {800.0f, 1.0f}), dt);                 
// engel kontrolü
//k1.Hareket(dt);               // tuş hareketi

       
        window.clear(sf::Color::Black);
         window.draw(arkadort.Tile, states);
          window.draw(arkadort2.Tile, states);
          window.draw(arkadort3.Tile, states);
    //    window.draw(k1.Resim);
      //  window.draw(Top.Resim);
        window.display();
    }

    return 0;
}
