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

int program(void);//Programeko funtzio nagusia puntuazioa itzultzen duena
void aukeratu(int aukera);//Aukeratutako markoa kolorez aldatzen du
int aukerak(char* aukera1, char* aukera2, char* aukera3);//Hiru aukerak agertzen diren pantaila kargatu
void zuzenoker(int zuzena);//zuzena edo okerra den arabera testu ezberdina idazten du
void txapapantaila(char* txapa);//Emandako testua idazten du irakaslearen fondoarekin
void markodatuak(void);// Markoen posizioen datuak ematen ditu
void markoerantzunak(char* aukera1, char* aukera2, char* aukera3);//Markoak eta erantzun posibleak pantailaratu


#endif