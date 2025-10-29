#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Karekter{
public:
std::string Yol;
sf::Texture Dosya;
sf::Sprite Resim;
sf::Clock Saat;
float gHiz=0.0f;
float hHiz=200.0f;
float gHizart=10.0f;
float gMax=200.0f;
Karekter(const std::string& y)
:Yol(y), Dosya(y), Resim(Dosya){
    
}
    void Hareket(float dt) {
        sf::Vector2f hareket(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            hareket.y -= hHiz * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            hareket.y += hHiz * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            hareket.x -= hHiz * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            hareket.x += hHiz * dt;

        Resim.move(hareket);
    }

void Tp(const float x,const float y){
    Resim.setPosition({x,y});
}
void Gra(float dt){
 gHiz += gHizart * dt;
if (gHiz>gMax){
    gHiz=gMax;
}
float y=gHiz*dt;
Resim.move({0,y});
}
float sat(){
     return Saat.restart().asSeconds();
}
};