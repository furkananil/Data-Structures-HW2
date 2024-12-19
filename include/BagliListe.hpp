// BagliListe.hpp
#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP

#include "Agac.hpp"

class BagliListe {
public:
    struct Node {
        Agac* agac; // Ağaç pointerı
        Node* sonraki; // Sonraki liste elemanı

        // Constructor
        Node(Agac* agac) : agac(agac), sonraki(nullptr) {}
    };

    Node* bas; // Listenin başlangıcı

    // Constructor
    BagliListe() : bas(nullptr) {}

    // Listeye yeni ağaç ekleme
    void agacEkle(Agac* yeniAgac);

    // Listeyi yazdırma
    void listeyiYazdir();

private:
    void yazdir(Node* node); // Recursive yazdırma fonksiyonu
};

#endif