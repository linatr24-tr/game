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
float sekmeK=0.8f;
Karekter(const std::string& y)
:Yol(y), Dosya(y), Resim(Dosya){
    
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
void Sekme(const sf::FloatRect& engel, float dt) {
    sf::FloatRect Top = Resim.getGlobalBounds();
    
    auto kesisim = Top.findIntersection(engel);
    
    if (kesisim.has_value()) {
        // Topun alt kenarı engelin üst kenarına çarptıysa
        if (Top.position.y + Top.size.y > engel.position.y && 
            Top.position.y < engel.position.y) {
            
            // Topu engelin üstüne yerleştir
            Resim.setPosition({
                Resim.getPosition().x, 
                engel.position.y - Top.size.y
            });
            
            // Hızı ters çevir ve azalt (sekme)
            gHiz = -gHiz * sekmeK;
            
            // Sekme hareketini uygula (yukarı doğru)
            Resim.move({0, gHiz * dt});
        }
    }
}
};