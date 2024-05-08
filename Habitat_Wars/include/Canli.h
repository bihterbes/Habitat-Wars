#ifndef CANLI_H
#define CANLI_H

typedef enum Bool{false, true} boolean;

typedef struct CANLI{
    int deger;
    char harf;
    int x;
    int y;
    boolean yasiyorMu;
    
    void (*canliYoket)(struct CANLI*);
    char* (*gorunum)();
    void (*oldur)(struct CANLI*);
}* Canli;

Canli CanliOlustur(int, char, int, int);
void CanliYoket(const Canli);
void Oldur(const Canli);

#endif