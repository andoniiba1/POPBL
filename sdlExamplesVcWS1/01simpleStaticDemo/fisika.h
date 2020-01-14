#ifndef FISIKA_H
#define FISIKA_H
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

POSIZIOA kotxepos;
POSIZIOA zentroa;
PLATAFORMAK bidea[32];

int fisika(void);
int bazterratxokea(int x, int y, int widht, int height, int fondoa);
void kotxeamarraztu(int aldea,int fondoa);
void bazterradatuak1(void);
void bazterradatuak2(void);
void bazterradatuak3(void);
#endif