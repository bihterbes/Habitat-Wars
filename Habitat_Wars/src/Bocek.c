#include "bocek.h"
#include <stdio.h>
#include <stdlib.h>

Bocek BocekOlustur(int deger, char harf, int x, int y) {
    Bocek bocek = (Bocek)malloc(sizeof(struct BOCEK));
    bocek->super = CanliOlustur(deger, harf, x, y);
    
    bocek->bocekYoket = &BocekYoket;
    bocek->bocekGorunum = &BocekGorunum;
    bocek->super->gorunum = &BocekGorunum;
    return bocek;
}

void BocekYoket(const Bocek bocek) {
    if (bocek != NULL) {
        bocek->super->canliYoket(bocek->super);
        free(bocek);
    }
}

char* BocekGorunum(const Canli canli) {
    if (canli != NULL) {
        char* str = (char*)malloc(sizeof(char)*2);
        sprintf(str, "%c", canli->harf);
        return str;
    }
    
    return NULL;
}