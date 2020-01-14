#ifndef IRUDIFORMAK_H
#define IRUDIFORMAK_H
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"




void irudiakargaposizioan(int x, int y, int irudizenbakia, char* irudiizena);
void markoamarraztu(int xhasiera, int yhasiera, int xbukaera, int ybukaera, int lodiera, int gorri, int berde, int urdin);
void laukizuzenamarraztu(int x1, int y1, int x2, int y2, int gorri, int berde, int urdin);
void irudiakpantailaratu(int x, int y, int irudizenbakia, char* irudiizena);
#endif