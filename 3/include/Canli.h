#ifndef CANLI_H
#define CANLI_H

#include <stdbool.h>

typedef enum {
    CANLI_DURUMU_CANLI,
    CANLI_DURUMU_OLU
} CANLI_DURUMU;

typedef struct CANLI {
    char* (*gorunum)(); // Gösterim fonksiyon gösterici
    int satir; // Canlının bulunduğu satır
    int sutun; // Canlının bulunduğu sütun
    CANLI_DURUMU canli_durumu; // Canlının yaşam durumu (CANLI veya OLU)
    int deger; // Canlının sayısal değeri
} CANLI;

// Canli yapısına ait metodların tanımları
char* Canli_gorunum();

#endif /* CANLI_H */
