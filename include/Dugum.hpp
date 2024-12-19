// Dugum.hpp
#ifndef DUGUM_HPP
#define DUGUM_HPP

class Dugum {
public:
    char deger; // Düğümün ASCII karakter değeri
    Dugum* sol; // Sol çocuk
    Dugum* sag; // Sağ çocuk

    // Constructor
    Dugum(char deger) : deger(deger), sol(nullptr), sag(nullptr) {}
};

#endif