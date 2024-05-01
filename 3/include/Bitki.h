#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

// Bitki yapısı, Canli yapısından kalıtım alacak
typedef struct BITKI {
    CANLI base; // Canli yapısından kalıtım
    // Bitkiye özgü alanlar buraya eklenebilir
} BITKI;

// Bitki yapısına ait metodların tanımları
char* Bitki_gorunum();

#endif
