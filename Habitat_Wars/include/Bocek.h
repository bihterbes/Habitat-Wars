#ifndef BOCEK_H
#define BOCEK_H

#include "canli.h"

typedef struct BOCEK{
    Canli super;
    
    void (*bocekYoket)(struct BOCEK*);
    char* (*bocekGorunum)(struct CANLI*);
}* Bocek;

Bocek BocekOlustur(int, char, int, int);
void BocekYoket(const Bocek);
char* BocekGorunum(const Canli);

#endif