#ifndef IRATZARRI_H
#define IRATZARRI_H
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


int iratzarri(void);//Iratzatzeko funtzio nagusia puntuazioa itzultzen duena
void erreseteatu(int* aldia, int* lehena, int* geio, int* bigarrena, int* segunduak, int* x, int* y);//Ez duenean lortzen aldagaiak erreseatu
void krono10(int* lehena, int* bigarrena, int* geio, int* segunduak, int* aldia, int* errepikatu);//kornometroa aktualizatzen du
void etzaraesnatu(void);//Ez bazara esnatzen agertzen den pantaila
void zuriunebarra(int* y, int* aldia);//zuriune barrako klikak kontatu eta y handitu bkoitzean
void iratzarrikargatu(void);//Iratzartzeko irudiak kargatu
#endif