#include <iostream>
#include <fstream>
#include <string>
#include "BagliListe.hpp"
#include "Agac.hpp"

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

    std::cout << "Agac Listesi:\n\n";
    agacListesi.listeyiYazdir();

    return 0;
}
