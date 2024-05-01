#include "Habitat.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Pire.h"
#include "Sinek.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dosyadan habitat okuma fonksiyonu
HABITAT* habitat_oku(const char* dosya_adi) {
    FILE* dosya = fopen(dosya_adi, "r");
    if (!dosya) {
        perror("Dosya açılamadı");
        return NULL;
    }

    int satir_sayisi = 0;
    int sutun_sayisi = 0;
    char satir[1024];
    int sayi;

    // Dosyadan satır oku ve en geniş sütun sayısını bul
    while (fgets(satir, sizeof(satir), dosya)) {
        int sutun = 0;
        char* token = strtok(satir, " \n");
        while (token != NULL) {
            sutun++;
            token = strtok(NULL, " \n");
        }
        if (sutun > sutun_sayisi) {
            sutun_sayisi = sutun;
        }
        satir_sayisi++;
    }

    // Dosyanın başına dön
    fseek(dosya, 0, SEEK_SET);

    // Habitat için bellek tahsis et
    HABITAT* habitat = malloc(sizeof(HABITAT));
    habitat->satir_sayisi = satir_sayisi;
    habitat->sutun_sayisi = sutun_sayisi;
    habitat->icerik = malloc(satir_sayisi * sizeof(CANLI**));

    for (int i = 0; i < satir_sayisi; i++) {
        habitat->icerik[i] = malloc(sutun_sayisi * sizeof(CANLI*));
        for (int j = 0; j < sutun_sayisi; j++) {
            habitat->icerik[i][j] = NULL; // Başlangıçta tüm hücreleri NULL ile doldur
        }
    }

    // Dosyadan sayıları oku ve CANLI nesnelerini oluştur
    int satir_index = 0;
    while (fgets(satir, sizeof(satir), dosya) && satir_index < satir_sayisi) {
        int sutun_index = 0;
        char* token = strtok(satir, " \n");
        while (token != NULL && sutun_index < sutun_sayisi) {
            sayi = atoi(token);
            CANLI* canli = malloc(sizeof(CANLI));
            canli->deger = sayi; // Sayısal değeri ata
            canli->satir = satir_index;
            canli->sutun = sutun_index;
            canli->canli_durumu = CANLI_DURUMU_CANLI;

            // Sayısal değere göre görünüm fonksiyonunu ata
            if (sayi >= 1 && sayi <= 9) {
                canli->gorunum = Bitki_gorunum;
            } else if (sayi >= 10 && sayi <= 20) {
                canli->gorunum = Bocek_gorunum;
            } else if (sayi >= 21 && sayi <= 50) {
                canli->gorunum = Sinek_gorunum;
            } else if (sayi >= 51 && sayi <= 99) {
                canli->gorunum = Pire_gorunum;
            } else {
                // Geçersiz değerler için NULL ataması yap
                free(canli);
                canli = NULL;
            }

            habitat->icerik[satir_index][sutun_index] = canli;
            sutun_index++;
            token = strtok(NULL, " \n");
        }
        satir_index++;
    }

    fclose(dosya);
    return habitat;
}

void habitat_goster(HABITAT* habitat) {
    for (int i = 0; i < habitat->satir_sayisi; i++) {
        for (int j = 0; j < habitat->sutun_sayisi; j++) {
            CANLI* canli = habitat->icerik[i][j];
            if (canli != NULL) {
                // Canlı türüne göre görünüm fonksiyonunu çağır
                char* gorunum = NULL;
                if (canli->deger >= 1 && canli->deger <= 9) {
                    gorunum = Bitki_gorunum();
                } else if (canli->deger >= 10 && canli->deger <= 20) {
                    gorunum = Bocek_gorunum();
                } else if (canli->deger >= 21 && canli->deger <= 50) {
                    gorunum = Sinek_gorunum();
                } else if (canli->deger >= 51 && canli->deger <= 99) {
                    gorunum = Pire_gorunum();
                }
                
                if (gorunum != NULL) {
                    printf("%s ", gorunum);
                } else {
                    printf("? ");
                }
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
}


// Habitat simülasyonunu başlatma fonksiyonu
void habitat_simulasyonu_baslat(HABITAT* habitat) {
    // Simülasyon mantığınızı burada yazabilirsiniz
}

// Habitat için ayrılan belleği temizleme fonksiyonu
void habitat_temizle(HABITAT* habitat) {
    for (int i = 0; i < habitat->satir_sayisi; i++) {
        for (int j = 0; j < habitat->sutun_sayisi; j++) {
            // Burada canlıların belleğini temizleyebilirsiniz
            // Örneğin: free(habitat->icerik[i][j]);
        }
        free(habitat->icerik[i]);
    }
    free(habitat->icerik);
    free(habitat);
}
