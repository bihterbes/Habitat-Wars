#include "habitat.h"
#include <stdio.h>
#include <stdlib.h>

Habitat HabitatOlustur(int x, int y) {
    Habitat habitat = (Habitat)malloc(sizeof(struct HABITAT));
    habitat->x = x;
    habitat->y = y;
    habitat->yerlesim = (Canli**)malloc(x*sizeof(Canli*));
    
    for (int i=0; i<x; i++) {
        habitat->yerlesim[i] = (Canli*)malloc(y*sizeof(Canli));
        
        for (int j=0; j<y; j++) {
            habitat->yerlesim[i][j] = NULL;
        }
    }
    
    habitat->habitatYoket = &HabitatYoket;
    habitat->habitatGorunum = &HabitatGorunum;
    habitat->canliEkle = &CanliEkle;
    habitat->canliSil = &CanliSil;
    habitat->canliOldur = &CanliOldur;
    habitat->canliYe = &CanliYe;
    habitat->sonCanli = &SonCanli;
    return habitat;
}

void HabitatYoket(const Habitat habitat) {
    if (habitat != NULL) {
        for (int i=0; i<habitat->x; i++) {
            for (int j=0; j<habitat->y; j++) {
                habitat->yerlesim[i][j] = NULL;
            }
            free(habitat->yerlesim[i]);
        }
        free(habitat->yerlesim);
        free(habitat);
    }
}

void HabitatGorunum(const Habitat habitat) {
    if (habitat != NULL) {
        for (int i=0; i<habitat->x; i++) {
            for (int j=0; j<habitat->y; j++) {
                if (habitat->yerlesim[i][j] != NULL && habitat->yerlesim[i][j]->yasiyorMu == true) {
                    printf("%s ", habitat->yerlesim[i][j]->gorunum(habitat->yerlesim[i][j]));
                } else {
                    printf("X ");
                    
                }
            }
            printf("\n");
        }
    }
}

void CanliEkle(const Habitat habitat, const Canli canli) {
    if (habitat != NULL && canli != NULL) {
        int x = canli->x;
        int y = canli->y;
        
        if (habitat->yerlesim[x][y] != NULL) {
            habitat->canliSil(habitat, x, y);
        }
        
        habitat->yerlesim[x][y] = canli;
    }
}

void CanliSil(Habitat habitat, int x, int y) {
    if (habitat != NULL) {
        if (habitat->yerlesim[x][y] != NULL) {
            habitat->yerlesim[x][y]->canliYoket(habitat->yerlesim[x][y]);
            habitat->yerlesim[x][y] = NULL;
        }
    }
}

void CanliOldur(Habitat habitat, int x, int y) {
    if (habitat != NULL) {
        if (habitat->yerlesim[x][y] != NULL) {
            habitat->yerlesim[x][y]->oldur(habitat->yerlesim[x][y]);
        }
    }
}

void CanliYe(Habitat habitat) {
    Canli kalanCanli = NULL;
    for (int i = 0; i<habitat->x; i++) {
        int k = 1;
        Canli komsu = NULL;
        for (int j = 0; j<habitat->y; j++) {
            Canli canli = habitat->yerlesim[i][j];
            
            if (kalanCanli != NULL) {
                canli = kalanCanli;
                k--;
            }
            
            if (k < habitat->y) {
                if (habitat->yerlesim[i][k]->yasiyorMu == false){
                    if (habitat->yerlesim[i][k+1] != NULL){
                        komsu = habitat->yerlesim[i][k+1];
                        k++;
                    }
                } else {
                    komsu = habitat->yerlesim[i][k];
                }
            }
            
            if (canli != NULL && canli->yasiyorMu == true) {
                if (komsu != NULL && komsu->yasiyorMu == true) {
                    if (canli->harf == 'B' && komsu->harf == 'P') {
                        habitat->canliOldur(habitat, komsu->x, komsu->y);
                    } else if (canli->harf == 'P' && komsu->harf == 'B') {
                        habitat->canliOldur(habitat, canli->x, canli->y);
                    }
                    
                    if (canli->harf == 'B' && komsu->harf == 'S') {
                        habitat->canliOldur(habitat, komsu->x, komsu->y);
                    } else if (canli->harf == 'S' && komsu->harf == 'B') {
                        habitat->canliOldur(habitat, canli->x, canli->y);
                    }
                    
                    if (canli->harf == 'C' && komsu->harf == 'B') {
                        habitat->canliOldur(habitat, komsu->x, komsu->y);
                    } else if (canli->harf == 'B' && komsu->harf == 'C') {
                        habitat->canliOldur(habitat, canli->x, canli->y);
                    }
                    
                    if (canli->harf == 'C' && komsu->harf == 'P') {
                        habitat->canliOldur(habitat, komsu->x, komsu->y);
                    } else if (canli->harf == 'P' && komsu->harf == 'C') {
                        habitat->canliOldur(habitat, canli->x, canli->y);
                    }
                    
                    if (canli->harf == 'S' && komsu->harf == 'P') {
                        habitat->canliOldur(habitat, komsu->x, komsu->y);
                    } else if (canli->harf == 'P' && komsu->harf == 'S') {
                        habitat->canliOldur(habitat, canli->x, canli->y);
                    }
                    
                    if (canli->harf == 'S' && komsu->harf == 'C') {
                        habitat->canliOldur(habitat, komsu->x, komsu->y);
                    } else if (canli->harf == 'C' && komsu->harf == 'S') {
                        habitat->canliOldur(habitat, canli->x, canli->y);
                    }
                    
                    boolean komsuYakinMi = false;
                    if (komsu->x >= canli->x) {
                        if (komsu->x > canli->x){
                            komsuYakinMi = true;
                        } else {
                            if (komsu->y > canli->y) {
                                komsuYakinMi = true;
                            }
                        }
                    }
                    
                    if (canli->harf == 'B' && komsu->harf == 'B') {
                        if (canli->deger > komsu->deger || (canli->deger == komsu->deger && komsuYakinMi == true)) {
                            habitat->canliOldur(habitat, komsu->x, komsu->y);
                        } else {
                            habitat->canliOldur(habitat, canli->x, canli->y);
                        }
                    } else if (canli->harf == 'C' && komsu->harf == 'C') {
                        if (canli->deger > komsu->deger || (canli->deger == komsu->deger && komsuYakinMi == true)) {
                            habitat->canliOldur(habitat, komsu->x, komsu->y);
                        } else {
                            habitat->canliOldur(habitat, canli->x, canli->y);
                        }
                    } else if (canli->harf == 'S' && komsu->harf == 'S') {
                        if (canli->deger > komsu->deger || (canli->deger == komsu->deger && komsuYakinMi == true)) {
                            habitat->canliOldur(habitat, komsu->x, komsu->y);
                        } else {
                            habitat->canliOldur(habitat, canli->x, canli->y);
                        }
                    } else if (canli->harf == 'P' && komsu->harf == 'P') {
                        if (canli->deger > komsu->deger || (canli->deger == komsu->deger && komsuYakinMi == true)) {
                            habitat->canliOldur(habitat, komsu->x, komsu->y);
                        } else {
                            habitat->canliOldur(habitat, canli->x, canli->y);
                        }
                    }
                    
                    if (canli->yasiyorMu == true) {
                        j--;
                    } else {
                        j = k-1;
                        kalanCanli = NULL;
                    }
                    k++;
                }
                
                if (k == habitat->y) {
                    habitat->habitatGorunum(habitat);
                    printf("\n");
                    system("cls");
                    
                    k = 1;
                    if (canli->yasiyorMu == true) {
                        kalanCanli = canli;
                    }
                    if (komsu != NULL && komsu->yasiyorMu == true) {
                        kalanCanli = komsu;
                    }
                    
                    break;
                }
            }
            
            habitat->habitatGorunum(habitat);
            printf("\n");
            system("cls");
        }
    }
    
    habitat->habitatGorunum(habitat);
}

void SonCanli(Habitat habitat) {
    Canli kalanCanli = NULL;
    
    for (int i = 0; i < habitat->x; i++) {
        for (int j = 0; j < habitat->y; j++) {
            Canli canli = habitat->yerlesim[i][j];
            if (canli != NULL && canli->yasiyorMu == true) {
                kalanCanli = canli;
            }
        }
    }
    
    if (kalanCanli != NULL) {
        printf("\nKazanan: %s : (%d,%d)\n", kalanCanli->gorunum(kalanCanli), kalanCanli->x, kalanCanli->y);
    }
}