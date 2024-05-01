#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

// Pire yapısı, Bocek yapısından kalıtım alacak
typedef struct PIRE {
    BOCEK base; // Bocek yapısından kalıtım
    // Pireye özgü alanlar buraya eklenebilir
} PIRE;

// Pire yapısına ait metodların tanımları
char* Pire_gorunum();

#endif /* PIRE_H */
