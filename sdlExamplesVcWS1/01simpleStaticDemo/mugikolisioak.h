#ifndef MUGIKOLISIOAK_H
#define MUGIKOLISIOAK_H
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"

int chocacon(int x1, int y1, int widht1, int height1, int x2, int y2, int widht2, int height2);//Bi laukik beraien x eta y-rekin(goiko ezkerreko puntua) eta beraien zabalera eta luzerarekin elkarren gainean dauden itzultzen du
void animaziofuntzioa(int* inertzia, int* kont, int* animazio, int* eskuina, int* ezker);//Animazioko zer irudi marraztu behar den esaten du
void mugimenduhorizontala(int* Vx, int* inertzia, int* eskuina);//Geziekin posizio berria kalkulatzen du horizontalean 
void posizioaaktualizatu(void);//Posizio berria animazioko irudiei ematen die
void inertziajaitsi(int* inertzia, int* Vx);//Inertsia jaisten du eta zerora iristean pertsonaia geldtiu

#endif