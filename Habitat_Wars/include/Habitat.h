#ifndef HABITAT_H
#define HABITAT_H

#include "canli.h"

typedef struct HABITAT{
    Canli** yerlesim;
    int x;
    int y;
    
    void (*habitatYoket)(struct HABITAT*);
    void (*habitatGorunum)(struct HABITAT*);
    void (*canliEkle)(struct HABITAT*, struct CANLI*);
    void (*canliSil)(struct HABITAT*, int, int);
    void (*canliOldur)(struct HABITAT*, int, int);
    void (*canliYe)(struct HABITAT*);
    void (*sonCanli)(struct HABITAT*);
}* Habitat;

Habitat HabitatOlustur(int, int);
void HabitatYoket(const Habitat);
void HabitatGorunum(const Habitat);
void CanliEkle(Habitat, Canli);
void CanliSil(Habitat, int, int);
void CanliOldur(Habitat, int, int);
void CanliYe(Habitat);
void SonCanli(Habitat);

#endif