// Test.c
#include <stdio.h>
#include <stdlib.h>
#include "habitat.h"

int main() {
     // Habitatı dosyadan oku
    HABITAT* habitat = habitat_oku("Veri.txt");
    if (habitat == NULL) {
        fprintf(stderr, "Habitat okunamadı.\n");
        return 1;
    }

    // Habitatı ekrana bas
    habitat_goster(habitat);

    // Habitat için ayrılan belleği temizle
    habitat_temizle(habitat);

    return 0;
}
