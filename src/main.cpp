#include <iostream>
#include <fstream>
#include <string>
#include "BagliListe.hpp"
#include "Agac.hpp"
#include <iomanip>

void yazdirAgacBilgileri(BagliListe* agacListesi) {
    BagliListe::Node* currentNode = agacListesi->bas;

    while (currentNode != nullptr) {
        std::cout << "........   ";
        currentNode = currentNode->sonraki;
    }
    std::cout << "\n";
    // Ağacın adreslerini yazdır
    currentNode = agacListesi->bas;
    while (currentNode != nullptr) {
        std::cout << ". " << std::setw(5) << std::right << (reinterpret_cast<uintptr_t>(currentNode->agac->kok) & 0xFFFF) << ".   ";
        currentNode = currentNode->sonraki;
    }
    std::cout << "\n";
    currentNode = agacListesi->bas;
    while (currentNode != nullptr) {
        std::cout << "........   ";
        currentNode = currentNode->sonraki;
    }
    std::cout << "\n";
    // Ağacın değerlerini yazdır
    currentNode = agacListesi->bas;
    while (currentNode != nullptr) {
        std::cout << ". " << std::setw(5) << std::right << currentNode->agac->agacDegeriHesapla() << ".   ";
        currentNode = currentNode->sonraki;
    }
    std::cout << "\n";
    currentNode = agacListesi->bas;
    while (currentNode != nullptr) {
        std::cout << "........   ";
        currentNode = currentNode->sonraki;
    }
    std::cout << "\n";
    // Bir sonraki ağacın adreslerini yazdır
    currentNode = agacListesi->bas;
    while (currentNode != nullptr) {
        if (currentNode->sonraki != nullptr) {
            std::cout << ". " << std::setw(5) << std::right << (reinterpret_cast<uintptr_t>(currentNode->sonraki->agac->kok) & 0xFFFF) << ".   ";
        } else {
            std::cout << ".   Yok.";
        }
        currentNode = currentNode->sonraki;
    }
    std::cout << "\n";
    currentNode = agacListesi->bas;
    while (currentNode != nullptr) {
        std::cout << "........   ";
        currentNode = currentNode->sonraki;
    }
    std::cout << "\n";
}

int main() {
    BagliListe agacListesi;

    std::ifstream dosya("agaclar.txt");
    if (!dosya.is_open()) {
        std::cerr << "Dosya acilmadi!\n";
        return 1;
    }

    std::string satir;
    while (std::getline(dosya, satir)) {
        Agac* yeniAgac = new Agac();
        for (char karakter : satir) {
            yeniAgac->dugumEkle(karakter);
        }
        agacListesi.agacEkle(yeniAgac);
    }

    dosya.close();

    // Ağaç bilgilerini yazdırma
    yazdirAgacBilgileri(&agacListesi);

    return 0;
}