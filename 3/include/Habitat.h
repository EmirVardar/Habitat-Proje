#ifndef HABITAT_H
#define HABITAT_H

#include "Canli.h"

// Habitat yapısını tanımlayın
typedef struct {
    int satir_sayisi;
    int sutun_sayisi;
    CANLI*** icerik; // CANLI işaretçilerinin işaretçileri
} HABITAT;

// Habitat fonksiyonlarının prototipleri
HABITAT* habitat_oku(const char* dosya_adi);
void habitat_goster(HABITAT* habitat);
void habitat_simulasyonu_baslat(HABITAT* habitat);
void habitat_temizle(HABITAT* habitat);

#endif /* HABITAT_H */
