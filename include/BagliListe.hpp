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
    BagliListe() : bas(nullptr), uzunluk(0) {}

    // Listeye yeni ağaç ekleme
    void agacEkle(Agac* yeniAgac);

    // Listeyi yazdırma
    void listeyiYazdir();

    // Liste uzunluğunu döndürme
    int size() const;

    // Belirli bir indeksteki ağacı döndürme
    Agac* getAgac(int index) const;

private:
    int uzunluk;
};

#endif // BAGLILISTE_HPP