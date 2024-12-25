#include <iostream>
#include <fstream>
#include <string>
#include "BagliListe.hpp"
#include "Agac.hpp"
#include <iomanip>
#include <conio.h> // _getch() fonksiyonu için

const int MAX_DUGUM = 10;

void yazdirAgacBilgileri(BagliListe* agacListesi, int index, int sayfa);
void listeyiGez(BagliListe* agacListesi);

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
    yazdirAgacBilgileri(&agacListesi, 0, 0);

    // Listeyi gezme
    listeyiGez(&agacListesi);

    return 0;
}

void yazdirAgacBilgileri(BagliListe* agacListesi, int index, int sayfa) {
    BagliListe::Node* currentNode = agacListesi->bas;
    int currentIndex = 0;
    int baslangic = sayfa * MAX_DUGUM;
    int bitis = baslangic + MAX_DUGUM;

    while (currentNode != nullptr && currentIndex < bitis) {
        if (currentIndex >= baslangic) {
            std::cout << "........   ";
        }
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    // Ağacın adreslerini yazdır
    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr && currentIndex < bitis) {
        if (currentIndex >= baslangic) {
            std::cout << ". " << std::setw(5) << std::right << (reinterpret_cast<uintptr_t>(currentNode->agac->kok) & 0xFFFF) << ".   ";
        }
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr && currentIndex < bitis) {
        if (currentIndex >= baslangic) {
            std::cout << "........   ";
        }
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    // Ağacın değerlerini yazdır
    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr && currentIndex < bitis) {
        if (currentIndex >= baslangic) {
            std::cout << ". " << std::setw(5) << std::right << currentNode->agac->agacDegeriHesapla() << ".   ";
        }
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr && currentIndex < bitis) {
        if (currentIndex >= baslangic) {
            std::cout << "........   ";
        }
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    // Bir sonraki ağacın adreslerini yazdır
    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr && currentIndex < bitis) {
        if (currentIndex >= baslangic) {
            if (currentNode->sonraki != nullptr) {
                std::cout << ". " << std::setw(5) << std::right << (reinterpret_cast<uintptr_t>(currentNode->sonraki->agac->kok) & 0xFFFF) << ".   ";
            } else {
                std::cout << ".   Yok.";
            }
        }
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr && currentIndex < bitis) {
        if (currentIndex >= baslangic) {
            std::cout << "........   ";
        }
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    // Ok işaretlerini yazdır
    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr && currentIndex < bitis) {
        if (currentIndex >= baslangic) {
            if (currentIndex == index) {
                std::cout << "^^^^^^^^   ";
            } else {
                std::cout << "           ";
            }
        }
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";

    // Dikey ok işaretlerini yazdır
    currentNode = agacListesi->bas;
    currentIndex = 0;
    while (currentNode != nullptr && currentIndex < bitis) {
        if (currentIndex >= baslangic) {
            if (currentIndex == index) {
                std::cout << "||||||||   ";
            } else {
                std::cout << "           ";
            }
        }
        currentNode = currentNode->sonraki;
        currentIndex++;
    }
    std::cout << "\n";
}

void listeyiGez(BagliListe* agacListesi) {
    BagliListe::Node* currentNode = agacListesi->bas;
    BagliListe::Node* oncekiNode = nullptr;
    BagliListe::Node* sonDugum = nullptr;
    int index = 0;
    int sayfa = 0;

    // Son düğümü bul
    if (agacListesi->bas != nullptr) {
        sonDugum = agacListesi->bas;
        while (sonDugum->sonraki != nullptr) {
            sonDugum = sonDugum->sonraki;
        }
    }

    while (true) {
        system("cls"); // Ekranı temizle
        yazdirAgacBilgileri(agacListesi, index, sayfa);

        if (currentNode == nullptr) {
            std::cout << "Liste bos.\n";
            break;
        }

        std::cout << "Indeks: " << index << "\n";
        std::cout << "Adres: " << (reinterpret_cast<uintptr_t>(currentNode->agac->kok) & 0xFFFF) << "\n";
        std::cout << "Deger: " << currentNode->agac->agacDegeriHesapla() << "\n";

        // Seçili düğümün ağacını yazdır
        currentNode->agac->AGACYAZDIR();

        std::cout << "Secim (a: sola git, d: saga git, s: sil, w: aynala, q: cikis): ";
        char ch = _getch();
        std::cout << ch << "\n"; // Kullanıcının seçimini göster
        char enter = _getch();
        if (enter == '\r') {
            if (ch == 'd' || ch == 'D') {
                if (index < (sayfa + 1) * MAX_DUGUM - 1 && currentNode->sonraki != nullptr) {
                    oncekiNode = currentNode;
                    currentNode = currentNode->sonraki;
                    index++;
                } else if (index == (sayfa + 1) * MAX_DUGUM - 1 && currentNode->sonraki != nullptr) {
                    oncekiNode = currentNode;
                    currentNode = currentNode->sonraki;
                    index++;
                    sayfa++;
                }
            } else if (ch == 'a' || ch == 'A') {
                if (index > sayfa * MAX_DUGUM) {
                    currentNode = agacListesi->bas;
                    oncekiNode = nullptr;
                    for (int i = 0; i < index - 1; ++i) {
                        oncekiNode = currentNode;
                        currentNode = currentNode->sonraki;
                    }
                    index--;
                } else if (index == sayfa * MAX_DUGUM && sayfa > 0) {
                    currentNode = agacListesi->bas;
                    oncekiNode = nullptr;
                    for (int i = 0; i < index - 1; ++i) {
                        oncekiNode = currentNode;
                        currentNode = currentNode->sonraki;
                    }
                    index--;
                    sayfa--;
                }
            } else if (ch == 's' || ch == 'S') {
                if (agacListesi->bas == nullptr) {
                    std::cout << "Liste zaten bos!\n";
                    return;
                }

                BagliListe::Node* silinecekNode = currentNode;

                // Eğer sadece tek bir düğüm varsa
                if (currentNode == sonDugum && currentNode == agacListesi->bas) {
                    agacListesi->bas = nullptr;
                    sonDugum = nullptr;
                    currentNode = nullptr;
                    oncekiNode = nullptr;
                    index = 0;
                }
                // Eğer son düğüm siliniyorsa
                else if (currentNode == sonDugum) {
                    BagliListe::Node* temp = agacListesi->bas;
                    while (temp->sonraki != sonDugum) {
                        temp = temp->sonraki;
                    }
                    temp->sonraki = nullptr;
                    sonDugum = temp;
                    currentNode = temp;
                    index--;
                }
                // Ara düğüm siliniyorsa
                else {
                    if (oncekiNode != nullptr) {
                        oncekiNode->sonraki = currentNode->sonraki;
                        currentNode = currentNode->sonraki;
                    } else { // Eğer baş düğüm siliniyorsa
                        agacListesi->bas = currentNode->sonraki;
                        currentNode = agacListesi->bas;
                    }
                }

                // Bellek serbest bırakma
                delete silinecekNode->agac;
                delete silinecekNode;

                // Sayfa ayarlaması
                if (index < sayfa * MAX_DUGUM) {
                    sayfa--;
                }
                if (index < 0) {
                    index = 0;
                }

                // Liste boşsa, tüm referansları sıfırla
                if (agacListesi->bas == nullptr) {
                    currentNode = nullptr;
                    oncekiNode = nullptr;
                    sonDugum = nullptr;
                    std::cout << "Liste tamamen bosaltildi.\n";
                }
            } else if (ch == 'w' || ch == 'W') {
                currentNode->agac->ayna(currentNode->agac->getroot());
            } else if (ch == 'q' || ch == 'Q') {
                break;
            }
        }
    }
}