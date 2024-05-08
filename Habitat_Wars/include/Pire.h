#ifndef PIRE_H
#define PIRE_H

#include "bocek.h"

typedef struct PIRE{
    Bocek super;
    
    void (*pireYoket)(struct PIRE*);
    char* (*pireGorunum)(struct CANLI*);
}* Pire;

Pire PireOlustur(int, char, int, int);
void PireYoket(const Pire);
char* PireGorunum(const Canli);

#endif