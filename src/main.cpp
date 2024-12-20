#include <iostream>
#include <fstream>
#include <string>
#include "BagliListe.hpp"
#include "Agac.hpp"
#include <iomanip>
#include <conio.h> // _getch() fonksiyonu için

void yazdirAgacBilgileri(BagliListe* agacListesi, int index) { 
    BagliListe::Node* currentNode = agacListesi->bas;
    int currentIndex = 0;

    while (currentNode != nullptr) {
        std::cout << "........   ";
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    currentNode = agacListesi->bas;
    currentIndex = 0;
    // Ağacın adreslerini yazdır
    while (currentNode != nullptr) {
        std::cout << ". " << std::setw(5) << std::right << (reinterpret_cast<uintptr_t>(currentNode->agac->kok) & 0xFFFF) << ".   ";
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr) {
        std::cout << "........   ";
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    // Ağacın değerlerini yazdır
    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr) {
        std::cout << ". " << std::setw(5) << std::right << currentNode->agac->agacDegeriHesapla() << ".   ";
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr) {
        std::cout << "........   ";
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    // Bir sonraki ağacın adreslerini yazdır
    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr) {
        if (currentNode->sonraki != nullptr) {
            std::cout << ". " << std::setw(5) << std::right << (reinterpret_cast<uintptr_t>(currentNode->sonraki->agac->kok) & 0xFFFF) << ".   ";
        } else {
            std::cout << ".   Yok.";
        }
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr) {
        std::cout << "........   ";
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    // Ok işaretlerini yazdır
    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr) {
        if (currentIndex == index) {
            std::cout << "^^^^^^^^";
        } else {
            std::cout << "           ";
        }
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";
    // cubuk işaretlerini yazdır
    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr) {
        if (currentIndex == index) {
            std::cout << "||||||||";
        } else {
            std::cout << "           ";
        }
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";
}

void listeyiGez(BagliListe* agacListesi) {
    BagliListe::Node* currentNode = agacListesi->bas;
    int index = 0;

    while (true) {
        system("cls"); // Ekranı temizle
        yazdirAgacBilgileri(agacListesi, index);

        std::cout << "Indeks: " << index << "\n";
        std::cout << "Adres: " << (reinterpret_cast<uintptr_t>(currentNode->agac->kok) & 0xFFFF) << "\n";
        std::cout << "Deger: " << currentNode->agac->agacDegeriHesapla() << "\n";

        std::cout << "secim...: ";
        char ch = _getch();
        std::cout << ch << "\n"; // Kullanıcının seçimini göster

        if (ch == 'd' || ch == 'D') {
            char enter = _getch();
            if (enter == '\r' && currentNode->sonraki != nullptr) {
                currentNode = currentNode->sonraki;
                index++;
            }
        } else if (ch == 'a' || ch == 'A') {
            char enter = _getch();
            if (enter == '\r' && index > 0) {
                currentNode = agacListesi->bas;
                for (int i = 0; i < index - 1; ++i) {
                    currentNode = currentNode->sonraki;
                }
                index--;
            }
        } else if (ch == 'q' || ch == 'Q') {
            break;
        }
    }
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
    yazdirAgacBilgileri(&agacListesi, 0);

    // Listeyi gezme
    listeyiGez(&agacListesi);

    return 0;
}