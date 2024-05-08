#ifndef SINEK_H
#define SINEK_H

#include "bocek.h"

typedef struct SINEK{
    Bocek super;
    
    void (*sinekYoket)(struct SINEK*);
    char* (*sinekGorunum)(struct CANLI*);
}* Sinek;

Sinek SinekOlustur(int, char, int, int);
void SinekYoket(const Sinek);
char* SinekGorunum(const Canli);

#endif