#ifndef BITKI_H
#define BITKI_H

#include "canli.h"

typedef struct BITKI{
    Canli super;
    
    void (*bitkiYoket)(struct BITKI*);
    char* (*bitkiGorunum)(struct CANLI*);
}* Bitki;

Bitki BitkiOlustur(int, char, int, int);
void BitkiYoket(const Bitki);
char* BitkiGorunum(const Canli);

#endif