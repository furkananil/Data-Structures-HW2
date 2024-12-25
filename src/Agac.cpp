#include <iostream>
#include <algorithm>
#include <cmath>
#include "Agac.hpp"


void Agac::dugumEkle(char deger) {
    if (kok == nullptr) {
        kok = new Dugum(deger);
    } else {
        Dugum* temp = kok;
        while (true) {
            if (deger < temp->deger) {
                if (temp->sol == nullptr) {
                    temp->sol = new Dugum(deger);
                    break;
                } else {
                    temp = temp->sol;
                }
            } else {
                if (temp->sag == nullptr) {
                    temp->sag = new Dugum(deger);
                    break;
                } else {
                    temp = temp->sag;
                }
            }
        }
    }
}

Agac::Dugum* Agac::getroot() {
    return kok; 
}

int Agac::agacDegeriHesapla() {
    return hesapla(kok,false);
}

int Agac::hesapla(Dugum* dugum, bool solVarmi = false) {
    if (dugum == nullptr) return 0;

    int deger = static_cast<int>(dugum->deger);

    if (solVarmi) {
        deger *= 2;
    }
    deger += hesapla(dugum->sol, true);
    deger += hesapla(dugum->sag, false);

    return deger;
}

int Agac::height(Agac::Dugum* root) {
    if (root == nullptr)
        return -1;

    int solHeight = height(root->sol);
    int sagHeight = height(root->sag);

    return std::max(solHeight, sagHeight) + 1;
}

void Agac::yazdirLevel(int n) {
    Agac::Dugum* temp = getroot();
    int val = pow(2, height(kok) - n + 1);
    std::cout << std::setw(val) << "";
    gosterLevel(temp, n, val);
}

void Agac::gosterLevel(Agac::Dugum* p, int level, int d) {
    int disp = 2 * d;
    if (level == 0) {
        if (p == NULL) {
            std::cout << " 1 ";
            std::cout << std::setw(disp - 3) << "";
            return;
        } else {
            int result = ((p->deger <= 1) ? 1 : log10(p->deger) + 1);
            std::cout << " " << p->deger << " ";
            std::cout << std::setw(disp - result - 2) << "";
        }
    } else {
        if (p == NULL && level >= 1) {
            gosterLevel(NULL, level - 1, d);
            gosterLevel(NULL, level - 1, d);
        } else {
            gosterLevel(p->sol, level - 1, d);
            gosterLevel(p->sag, level - 1, d);
        }
    }
}

void Agac::AGACYAZDIR() {
    int i = 0;
    while (i <= height(getroot())) {
        yazdirLevel(i);
        i++;
        std::cout << std::endl;
        if (i <= height(getroot())) {
            std::cout << std::endl << std::endl << std::endl;
        }
    }
}

void Agac::ayna(Dugum* dugum) {
    if (dugum == nullptr) return;

    // Sol ve sağ çocukları değiştir
    Dugum* temp = dugum->sol;
    dugum->sol = dugum->sag;
    dugum->sag = temp;

    // Alt ağaçları aynala
    ayna(dugum->sol);
    ayna(dugum->sag);
}
