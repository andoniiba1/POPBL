#ifndef HASIERAKOPANTAILAK_H
#define HASIERAKOPANTAILAK_H
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

MARKO botoia[7];
INSTRUKZIOPANTAILAK instrukziopantailak;

void menua(void);
void kredituak(void);
void instrukzioak(void);
void ezkerbotoibukle(void);
void historia(char* historia);
void puntuazioa(int puntu);
void itxi(void);
void puntuaziotestua(int puntuak, char* bikain, char* ondo, char* gaizki, char* desastre);
void botoipantailak(void);
void generaleraitzuli(void);
void instrukziobakoitza(int jokoinstrukzioa, char* izena);
void botoidatuak(void);
#endif