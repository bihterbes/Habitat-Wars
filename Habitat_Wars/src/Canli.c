#include "canli.h"
#include <stdio.h>
#include <stdlib.h>

Canli CanliOlustur(int deger, char harf, int x, int y) {
    Canli canli = (Canli)malloc(sizeof(struct CANLI));
    canli->deger = deger;
    canli->harf = harf;
    canli->x = x;
    canli->y = y;
    canli->yasiyorMu = true;
    
    canli->canliYoket = &CanliYoket;
    canli->oldur = &Oldur;
    return canli;
}

void CanliYoket(const Canli canli) {
    if (canli != NULL) {
        free(canli);
    }
}

void Oldur(const Canli canli) {
    if (canli != NULL) {
        canli->yasiyorMu = false;
    }
}