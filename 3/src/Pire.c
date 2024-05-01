#include "Pire.h"

// Pire yapısının görünümünü döndüren fonksiyon
char* Pire_gorunum() {
    return "P";
}

// Pire yapısını başlatan fonksiyon
PIRE Pire_olustur() {
    PIRE yeni_pire;
    yeni_pire.base.base.gorunum = Pire_gorunum; // Fonksiyon işaretçisini ayarla
    // Pireye özgü başlatmalar burada yapılabilir
    return yeni_pire;
}
