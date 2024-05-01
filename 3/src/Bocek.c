#include "Bocek.h"

// Bocek yapısının görünümünü döndüren fonksiyon
char* Bocek_gorunum() {
    return "C";
}

// Bocek yapısını başlatan fonksiyon
BOCEK Bocek_olustur() {
    BOCEK yeni_bocek;
    yeni_bocek.base.gorunum = Bocek_gorunum; // Fonksiyon işaretçisini ayarla
    // Boceğe özgü başlatmalar burada yapılabilir
    return yeni_bocek;
}
