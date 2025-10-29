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
float gHizart=20.0f;
float gMax=800.0f;
Karekter(const std::string& y)
:Yol(y), Dosya(y), Resim(Dosya){
    
}

void altEngel(const sf::FloatRect& engel) {
    sf::FloatRect kBox = Resim.getGlobalBounds();

    // Çarpışma varsa
    if (kBox.intersects(engel)) {
        // Karakteri engelin üstüne koy
        Resim.setPosition(kBox.left, engel.top - kBox.height);

        // Yerçekimi hızını sıfırla, böylece karakter "havada kalır"
        gHiz = 0.0f;
    }
}
    void Hareket(float dt) {
        sf::Vector2f hareket(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            hareket.y -= hHiz * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            hareket.y += hHiz * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            hareket.x -= hHiz * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
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