#include "sinek.h"
#include <stdio.h>
#include <stdlib.h>

Sinek SinekOlustur(int deger, char harf, int x, int y) {
    Sinek sinek = (Sinek)malloc(sizeof(struct SINEK));
    sinek->super = BocekOlustur(deger, harf, x, y);
    
    sinek->sinekYoket = &SinekYoket;
    sinek->sinekGorunum = &SinekGorunum;
    sinek->super->super->gorunum = &SinekGorunum;
    return sinek;
}

void SinekYoket(const Sinek sinek) {
    if (sinek != NULL) {
        sinek->super->bocekYoket(sinek->super);
        free(sinek);
    }
}

char* SinekGorunum(const Canli canli) {
    if (canli != NULL) {
        char* str = (char*)malloc(sizeof(char)*2);
        sprintf(str, "%c", canli->harf);
        return str;
    }
    
    return NULL;
}