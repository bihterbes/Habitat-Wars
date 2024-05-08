#include "bitki.h"
#include <stdio.h>
#include <stdlib.h>

Bitki BitkiOlustur(int deger, char harf, int x, int y) {
    Bitki bitki = (Bitki)malloc(sizeof(struct BITKI));
    bitki->super = CanliOlustur(deger, harf, x, y);
    
    bitki->bitkiYoket = &BitkiYoket;
    bitki->bitkiGorunum = &BitkiGorunum;
    bitki->super->gorunum = &BitkiGorunum;
    return bitki;
}

void BitkiYoket(const Bitki bitki) {
    if (bitki != NULL) {
        bitki->super->canliYoket(bitki->super);
        free(bitki);
    }
}

char* BitkiGorunum(const Canli canli) {
    if (canli != NULL) {
        char* str = (char*)malloc(sizeof(char)*2);
        sprintf(str, "%c", canli->harf);
        return str;
    }
    
    return NULL;
}