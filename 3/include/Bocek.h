#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

// Bocek yapısı, Canli yapısından kalıtım alacak
typedef struct BOCEK {
    CANLI base; // Canli yapısından kalıtım
    // Bocek'e özgü alanlar buraya eklenebilir
} BOCEK;

// Bocek yapısına ait metodların tanımları
char* Bocek_gorunum();

#endif
