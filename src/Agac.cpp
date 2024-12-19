#include "Agac.hpp"
#include <iostream>

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