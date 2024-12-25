#ifndef AGAC_HPP
#define AGAC_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

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
    int height(Agac::Dugum *root);
    Dugum* getroot();
    void yazdirLevel(int n);
    void gosterLevel(Dugum*p, int level, int d);
    void AGACYAZDIR();
    void ayna(Dugum* dugum);
private:
    int hesapla(Dugum* dugum, bool solVarmi);
};
#endif