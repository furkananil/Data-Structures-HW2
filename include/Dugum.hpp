// Dugum.hpp
#ifndef DUGUM_HPP
#define DUGUM_HPP

class Dugum {
public:
    char deger; // Düğümün ASCII karakter değeri
    Dugum* sol; // Sol çocuk
    Dugum* sag; // Sağ çocuk
    Dugum(char deger);
};
#endif