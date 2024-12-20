#ifndef AGAC_HPP
#define AGAC_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Agac {
public:
    struct Dugum {
        char deger;
        Dugum* sol;
        Dugum* sag;

        Dugum(char deger) : deger(deger), sol(nullptr), sag(nullptr) {}
    };

    Dugum* kok;

    Agac() : kok(nullptr) {}

    void dugumEkle(char deger);
    int agacDegeriHesapla();
};

#endif // AGAC_HPP