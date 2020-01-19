#ifndef REDES_H
#define REDES_H
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"
#include "irudiformak.h"
#include "musika.h"
#include "hasierako pantailak.h"

void redeskargatu(void);//Redeseko irudiak kargatu
void besteirudiakmantendu(int irudizenbakia);//irudi bat mugitzen(irudizenbakia duena) besteak marrazten segitzen du
int enkajatu(int irudizenbakia, int x, int y);// Irudizenbakia duen irudia x etx y baten jartzen du inguruan askatuta
void irudimugimendua(int irudizenbakia);//Klik eginda irudiak mugitzen dituzu
void redesmarkoak(void);//Hiru marko pintatzen ditu
int redespuntuazioa(void);//Redesetik ateratzekoan puntuazioa itzultzen du
int redes(void);//Redeseko funtzio nagusia puntuazioa itzltzen duena

#endif