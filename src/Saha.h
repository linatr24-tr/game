#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Saha {
public:
    std::string Yol;
    sf::Texture Dosya;
    sf::Sprite Resim;
    sf::VertexArray Tile;
     float texW = 32.f;
        float texH = 32.f;
    

    Saha(const std::string& x) : Yol(x),Dosya(Yol),Resim(Dosya), Tile(sf::PrimitiveType::Triangles) {
        if (!Dosya.loadFromFile(Yol)) {
            // Hata yönetimi
        }
        Resim.setTexture(Dosya);
    }
    
    void Dortgen(float x, float y, float genislik, float yukseklik) {
        // Texture boyutları (32x32 varsayıyoruz)
       
        
        // İlk üçgen (sol üst, sağ üst, sol alt)
        sf::Vertex v1;
        v1.position = {x, y};
        v1.texCoords = {0.f, 0.f};
        Tile.append(v1);
        
        sf::Vertex v2;
        v2.position = {x + genislik, y};
        v2.texCoords = {texW, 0.f};
        Tile.append(v2);
        
        sf::Vertex v3;
        v3.position = {x, y + yukseklik};
        v3.texCoords = {0.f, texH};
        Tile.append(v3);
        
        // İkinci üçgen (sağ üst, sağ alt, sol alt)
        sf::Vertex v4;
        v4.position = {x + genislik, y};
        v4.texCoords = {texW, 0.f};
        Tile.append(v4);
        
        sf::Vertex v5;
        v5.position = {x + genislik, y + yukseklik};
        v5.texCoords = {texW, texH};
        Tile.append(v5);
        
        sf::Vertex v6;
        v6.position = {x, y + yukseklik};
        v6.texCoords = {0.f, texH};
        Tile.append(v6);
    }
    
    void Ciz(sf::RenderWindow& window) {
        sf::RenderStates states;
        states.texture = &Dosya;
        window.draw(Tile, states);
    }
    
    void Temizle() {
        Tile.clear();
    }
};