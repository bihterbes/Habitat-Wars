#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bitki.h"
#include "bocek.h"
#include "pire.h"
#include "sinek.h"
#include "habitat.h"

void habitatOlustur(FILE *dosya) {
    char satir[1002];
    int satirSayisi = 0;
    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        if(strcmp(satir, "\n") == 0){
            break;
        }
        satirSayisi++;
    }
    
    rewind(dosya);
    
    fgets(satir, sizeof(satir), dosya);
    char *ptr = strtok(satir, " ");
    int sutunSayisi = 0;
    while (ptr != NULL) {
        sutunSayisi++;
        ptr = strtok(NULL, " \n");
    }
    rewind(dosya);
    
    Habitat habitat = HabitatOlustur(satirSayisi, sutunSayisi);

    int bitkiI = 0;
    int bocekI = 0;
    int sinekI = 0;
    int pireI = 0;
    Bitki* bitkiYerlesim = (Bitki*)malloc((satirSayisi*sutunSayisi)*sizeof(Bitki));
    Bocek* bocekYerlesim = (Bocek*)malloc((satirSayisi*sutunSayisi)*sizeof(Bocek));
    Sinek* sinekYerlesim = (Sinek*)malloc((satirSayisi*sutunSayisi)*sizeof(Sinek));
    Pire* pireYerlesim = (Pire*)malloc((satirSayisi*sutunSayisi)*sizeof(Pire));
    int veri = 0;
    int x = 0;
    int y = 0;
    while (fscanf(dosya, "%d", &veri) != EOF) {
        if(y == sutunSayisi) {
            x++;
            y = 0;
        }
        
        if (veri >= 1 && veri <= 9) {
            Bitki bitki = BitkiOlustur(veri, 'B', x, y);
            habitat->canliEkle(habitat, bitki->super);
            bitkiYerlesim[bitkiI++] = bitki;
        } else if (veri >= 10 && veri <= 20) {
            Bocek bocek = BocekOlustur(veri, 'C', x, y);
            habitat->canliEkle(habitat, bocek->super);
            bocekYerlesim[bocekI++] = bocek;
        } else if (veri >= 21 && veri <= 50) {
            Sinek sinek = SinekOlustur(veri, 'S', x, y);
            habitat->canliEkle(habitat, sinek->super->super);
            sinekYerlesim[sinekI++] = sinek;
        } else if (veri >= 51 && veri <= 99) {
            Pire pire = PireOlustur(veri, 'P', x, y);
            habitat->canliEkle(habitat, pire->super->super);
            pireYerlesim[pireI++] = pire;
        }
        
        y++;
    }
    
    printf("\n");
    habitat->habitatGorunum(habitat);
    printf("\nCanlilarin birbirini yemesi icin bir tusa basin: ");
    getch();
    printf("\n");
    habitat->canliYe(habitat);
    habitat->sonCanli(habitat);
    
    for (int i=0; i<bitkiI; i++) {
        bitkiYerlesim[i]->bitkiYoket(bitkiYerlesim[i]);
    }
    for (int i=0; i<bocekI; i++) {
        bocekYerlesim[i]->bocekYoket(bocekYerlesim[i]);
    }
    for (int i=0; i<sinekI; i++) {
        sinekYerlesim[i]->sinekYoket(sinekYerlesim[i]);
    }
    for (int i=0; i<pireI; i++) {
        pireYerlesim[i]->pireYoket(pireYerlesim[i]);
    }
    free(bitkiYerlesim);
    free(bocekYerlesim);
    free(sinekYerlesim);
    free(pireYerlesim);
    habitat->habitatYoket(habitat);
}

int main() {
    FILE *dosya = fopen("./doc/Veri.txt", "r");
    
    if (dosya == NULL) {
        printf("Hata: Dosya açılamadı.\n");
        exit(EXIT_FAILURE);
    }
    
    habitatOlustur(dosya);
    
    fclose(dosya);

    return 0;
}