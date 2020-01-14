#ifndef TESTUA_H
#define TESTUA_H
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"

#define ESNATUONA "Zorionak, nahikoa kostatu bazaizu ere lortu duzu azkenean esnatzea. Egia esan ez nuen horren urruti iritsiko zinenik espero. Baina hau eguneko lehen oztopoa besterik ez da izan. Orain beste eginkizun gogor bat datorkizu, 11. eraikinera garaiz iristea. Izan ere, bertara iristeko bidea beste edozein baina gogorragoa da. Hobe duzu bidean ez galdu eta garaiz iritsi zure lehenengo klasera."
#define ESNATUBERANDU "Kostata baina azkenean esnatu zara. Egia esan nik uste baina gehiago iraun duzu. Baina oraindik klaseetara iristeko 11. eraikinera iritsi behar duzu. Eta ez badirudi ere hau ez da lan erraza. Hobe duzu azkar ibili, berandu iritsiko zara bestela."
#define ESNATUOSOBERANDU "Inoiz baina gehiago kostata baina zure etxeko guztiak esnatu ondoren jaiki zara. Badirudi gauetan ezingo zarela hainbeste lol partida ibili. Baina gauza batzuk sakrifikatu egin behar izaten dira bizitza honetan."
#define EZESNATU "Bueno azkenean eguneroko moduan ez zara esnatu. Zer egingo diogu ba, bihar agian. Banekien ez zinela informatiko baten kontrola hartzeko prest baina ahalegindu beharra genuen. Azken finean froga eta errore metodologia da egokiena ezta?"

char str[50][100];
void parrafoaidatzi(int hasierax, int hasieray, int karakterlineako, char* testua,int r, int g, int b);
int lerrotanbanatu(int lerroluzeramax, char* testua);
int hitzluzera(int posizioa, char* str);
#endif