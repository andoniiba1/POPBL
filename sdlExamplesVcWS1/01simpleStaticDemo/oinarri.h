#ifndef OINARRI_H
#define OINARRI_H
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
#include "hasierako pantailak.h"
#include"mugikolisioak.h"

KONSEJOAK konsejoa[5];
POSIZIOA posberri;

int oinarri(void);//Oinarriko funtzio nagusia
int mugihorizontal(int x);//Horizontalki mugitzea baimentzen du
void notakmarraztu(int kopurua);//Notak marrazten ditu beti
void notakharrapatu(int animazio, int irudizenbakia, int* puntuazioa);//Notak harrapatu dituzula 
void notaksortu(int irudizenbakia, int* kont);//Notak pantailaren goian sortzen ditu
void oinarrikargatu();//Oinarriko irudiak karkatzen ditu
int oinarripuntuazioa(int puntuazioa);//Puntuazioa kalkulatu eta itzultzen du
void notaklurrera(int irudizenbakia);//Notak lurra ukitzea detektatzen du

#endif