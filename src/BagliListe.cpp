#include "BagliListe.hpp"
#include <iostream>

void BagliListe::agacEkle(Agac* yeniAgac) {
    Node* yeniNode = new Node(yeniAgac);
    if (bas == nullptr) {
        bas = yeniNode;
    } else {
        Node* temp = bas;
        while (temp->sonraki != nullptr) {
            temp = temp->sonraki;
        }
        temp->sonraki = yeniNode;
    }
    uzunluk++;
}

void BagliListe::listeyiYazdir() {
    Node* temp = bas;
    while (temp != nullptr) {
        std::cout << "Agac: " << temp->agac->agacDegeriHesapla() << std::endl;
        temp = temp->sonraki;
    }
}

int BagliListe::size() const {
    return uzunluk;
}

Agac* BagliListe::getAgac(int index) const {
    if (index < 0 || index >= uzunluk) return nullptr;
    Node* temp = bas;
    for (int i = 0; i < index; ++i) {
        temp = temp->sonraki;
    }
    return temp->agac;
}