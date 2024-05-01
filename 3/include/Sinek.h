#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

// Sinek yapısı, Bocek yapısından kalıtım alacak
typedef struct SINEK {
    BOCEK base; // Bocek yapısından kalıtım
    // Sineğe özgü alanlar buraya eklenebilir
} SINEK;

// Sinek yapısına ait metodların tanımları
char* Sinek_gorunum();

#endif /* SINEK_H */
