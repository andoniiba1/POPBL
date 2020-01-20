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

void menua(void);//Menua kargatzeko
void kredituak(void);//kredituak karfatzeko
void instrukzioak(void);//instrukzioetako irudia ipini
void ezkerbotoibukle(void);//Ezkerreko botioari klik egin arte pantaila berean mantentzeko
void historia(char* historia);//Testua idazteko pantaila
void puntuazioa(int puntu);
void itxi(void);//Eskapeari edo x-ari ematean detektatzeko
void puntuaziotestua(int puntuak, char* bikain, char* ondo, char* gaizki, char* desastre);//Emandako puntuen arabera esaldi ezberdina idazten duen pantaila erakutsi
void botoipantailak(void);//Instrukzioetan klikatzen duzun pantailara eraman
void generaleraitzuli(void);//instrukziotara itzultzeko
void menuraitzuli(void);//menura itzultzeko
void instrukziobakoitza(int jokoinstrukzioa, char* izena);//Joko bakoitzeko instrukzioak pantailaratu eta nahi gezian klik eginda instrukzio generaletara itzuli
void botoidatuak(void);//Instruzioetako botoien posizioen datuak
void fletxabuklehurrengoa(void);//Eskuinean behean agertzen den geziari eman arteko buklea
void egunpantaila(int eguna);//eguneko zenbakia azaltzen duen pantaila
#endif