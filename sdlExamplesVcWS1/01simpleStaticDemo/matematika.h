#ifndef MATEMATIKA_H
#define MATEMATIKA_H
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


int matematika(void);//Matamatikako funtzio nagusia
int harrapatu(int x, int gora, int aldatu,int *puntuazioa);//Maisuak ikusi zaituen edo ez itzuli
int mateaktualizatu(int gora, int puntuazioa, int aldatu, char* kronometroa);//Mateko pantaila aktualizatzen du
void krono20(int* bigarrena, int* lehena, int* segunduak, int* geio2, int* geio, int* mantendu);//Kronometroko aldagaiak aktualizatu
void buelta(int* aldatu, int* puntuazioa, int gora,char* kronometroa, int* rebote, int* azelerazio, int* geldidenbora, int* geldi, int* egon);//maisuaren buelta egiten du
void segi(int aldatu, int x, int y, int gora, char* kronometroa, int* puntuazioa);//maisua mugitzea eragiten du
void maisumugimendua(int aldatu, int geldi, int* x, int azelerazio);//maisuaren posizioa aktualizatzen du
int matepuntuazioa(int puntuazioa);//puntuazioa kalkulatu eta itzultzen du
#endif