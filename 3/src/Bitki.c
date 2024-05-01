#include "Bitki.h"

// Bitki yapısının görünümünü döndüren fonksiyon
char* Bitki_gorunum() {
    return "B";
}

// Bitki yapısını başlatan fonksiyon
BITKI Bitki_olustur() {
    BITKI yeni_bitki;
    yeni_bitki.base.gorunum = Bitki_gorunum; // Fonksiyon işaretçisini ayarla
    // Bitkiye özgü başlatmalar burada yapılabilir
    return yeni_bitki;
}

