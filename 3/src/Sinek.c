#include "Sinek.h"

// Sinek yapısının görünümünü döndüren fonksiyon
char* Sinek_gorunum() {
    return "S";
}

// Sinek yapısını başlatan fonksiyon
SINEK Sinek_olustur() {
    SINEK yeni_sinek;
    yeni_sinek.base.base.gorunum = Sinek_gorunum; // Fonksiyon işaretçisini ayarla
    // Sineğe özgü başlatmalar burada yapılabilir
    return yeni_sinek;
}
