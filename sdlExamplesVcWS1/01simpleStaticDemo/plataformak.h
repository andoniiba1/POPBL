#ifndef PLATAFORMAK_H
#define PLATAFORMAK_H
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"
#include "testua.h"
#include "irudiformak.h"
#include "musika.h"

POSIZIOA posberri;
PLATAFORMAK plataform[32];

int plataformak(void);
void plataformdatuak(void);
int plataformatxokea(int x, int y, int widht, int height);
int chocacon(int x1, int y1, int widht1, int height1, int x2, int y2, int widht2, int height2);
void posizioaaktualizatu(void);
void posizioamantendu(void);
void erorketa(int* salto, int* t,int *aldaketa);
void animaziofuntzioa(int* inertzia, int* kont, int* animazio, int* eskuina, int* ezker);
void mugimenduhorizontala(int* Vx, int* inertzia, int* eskuina);

#endif