#include "pire.h"
#include <stdio.h>
#include <stdlib.h>

Pire PireOlustur(int deger, char harf, int x, int y) {
    Pire pire = (Pire)malloc(sizeof(struct PIRE));
    pire->super = BocekOlustur(deger, harf, x, y);
    
    pire->pireYoket = &PireYoket;
    pire->pireGorunum = &PireGorunum;
    pire->super->super->gorunum = &PireGorunum;
    return pire;
}

void PireYoket(const Pire pire) {
    if (pire != NULL) {
        pire->super->bocekYoket(pire->super);
        free(pire);
    }
}

char* PireGorunum(const Canli canli) {
    if (canli != NULL) {
        char* str = (char*)malloc(sizeof(char)*2);
        sprintf(str, "%c", canli->harf);
        return str;
    }
    
    return NULL;
}