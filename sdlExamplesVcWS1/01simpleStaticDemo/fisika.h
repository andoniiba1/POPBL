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
#include "mugikolisioak.h"
#include "hasierako pantailak.h"

POSIZIOA kotxepos;
POSIZIOA zentroa;
PLATAFORMAK bidea[32];

int fisika(void);//Fisikako funtzio nagusia
int bazterratxokea(int x, int y, int widht, int height, int fondoa);//Kotxea baztera jo duen itzultzen du
void kotxeamarraztu(int aldea,int fondoa);//Kotxea marrazten du beti
void bazterradatuak1(void);//1.pantailako hitboxak
void bazterradatuak2(void);//2.pantailako hitboxak
void bazterradatuak3(void);//3.pantailako hitboxak
void fisikakargatu(void);//Fisikako irudiak kargatzen ditu
int direkzioaaldatu(int aldea);//Kotxea direkzioz aldatzen du
void kotzeamugitu(int aldea, int* soinudenbora);//Geziaekin kotxea aurrera eta atzera mugitzn du
void kotxezentroaajustatu(int aldea);//Direkzioz aldatzean hitboxa ajustatzen du
void fondoaaldatu(int* fondoa, int* amaitu);//Pantailaren bukaerara iristean hurrengora`pasatzen du
int fisikapuntuazioa(int txoke, int puntuazioa);//Puntuazioa kalkulatu eta itzultzen du
void errepidetikatera(int* amaitu, int* txoke, int fondoa);//Bazterra jotzean jokoa bukatzen du
#endif