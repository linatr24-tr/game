#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Karekter{
public:
std::string Yol;
sf::Texture Dosya;
sf::Sprite Resim;
sf::Clock Saat;
float gHiz=0;
float hHiz=5;
float gHizart=0.2f;
float gMax=7.0f;
Karekter(const std::string& y)
:Yol(y), Dosya(y), Resim(Dosya){
    
}
void Hareket(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        Resim.move({0,-1}); 
    }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        Resim.move({0,+1}); 
    }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            Resim.move({-1,0}); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            Resim.move({+1,0}); 
        }
}
void Tp(const float x,const float y){
    Resim.setPosition({x,y});
}
void Gra(){
float dt=Saat.restart().asSeconds();
 gHiz += gHizart * dt;
if (gHiz>gMax){
    gHiz=gMax;
}
float y=gHiz*dt;
Resim.move({0,y});
}
};