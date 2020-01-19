#ifndef PLATAFORMAK_H
#define PLATAFORMAK_H
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


PLATAFORMAK plataform[32];

int plataformak(void);//plataformen funtzio nagusia
void plataformdatuak(void);//plataforma bakoitzaren hitboxa
int plataformatxokea(int x, int y, int widht, int height);//plataformaren bat ukitzen al duen
void posizioaaktualizatu(void);//kalkulatu ondoren posizio berrira mugitzeko irudiak
void posizioamantendu(void);//aurreko kalkuluan zuen posizioa mantentzeko irudietan
void erorketa(int* salto, float* t,int *aldaketa);//plataformak albotik jotzen dituenean erortzen segitzeko
void plataformakkargatu(void);//plataformetako irudia eta animazioak kargatu
void jauzia(int* Vy, int* salto);//jauzia egin
void ibaia(int *animazio, int* hondoratu, float* t, int* Vy, int* hil); //uretara erortzea detektatu
void inertziajaitsi(int* inertzia, int* Vx);//inertzia jaitsi eta gelditu
void grabitatea(int *hondoratu, int* Vy, int AzeY, float* t, int* aldaketa);//grabitataren eragina kalkulatu
int plataformapuntuazioa(int puntuazioa, int hil);//plataformetako puntuazioa kalkulatzen du eta itzuli
int plataformamaitu(int animazio);//Plataformen jokoa bukatu den itzultzen du
void ibiltzesoinua(int* soinudenbora, int inertzia, int salto);//iblitzeko soinua erreproduzitzen du

#endif