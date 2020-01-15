#ifndef PROGRAM_H
#define PROGRAM_H
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"
#include "testua.h"
#include "irudiformak.h"
#include"hasierako pantailak.h"
#include "musika.h"

MARKO marko[4];

int program(void);
void aukeratu(int aukera);
int aukerak(char* aukera1, char* aukera2, char* aukera3);
void zuzenoker(int zuzena);
void txapapantaila(char* txapa);
void markodatuak(void);


#endif