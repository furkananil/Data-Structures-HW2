// Agac.hpp
#ifndef AGAC_HPP
#define AGAC_HPP

#include "Dugum.hpp"

class Agac {
public:
    Dugum* kok; // Ağacın kök düğümü

    // Constructor
    Agac() : kok(nullptr) {}

    // Ağaca düğüm ekleme fonksiyonu
    void dugumEkle(char deger);

    // Ağacın toplam değerini hesaplama
    int agacDegeriHesapla();

private:
    int hesapla(Dugum* dugum, bool solVarmi); // Recursive hesaplama fonksiyonu
};

#endif