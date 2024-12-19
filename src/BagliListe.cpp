#include "BagliListe.hpp"
#include <iostream>
#include <iomanip>

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
}

void BagliListe::listeyiYazdir() {
    yazdir(bas);
}

void BagliListe::yazdir(Node* node) {
    if (node == nullptr) return;

    std::cout << "Adres: " << node << "\n";
    std::cout << "Deger: " << node->agac->agacDegeriHesapla() <<"\n";
    std::cout << "Sonraki: " << node->sonraki << "\n\n";

    yazdir(node->sonraki);
}
