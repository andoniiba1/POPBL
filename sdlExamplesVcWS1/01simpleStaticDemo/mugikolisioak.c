#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"

#include "mugikolisioak.h"

int chocacon(int x1, int y1, int widht1, int height1, int x2, int y2, int widht2, int height2) {
	int ukitzendu = 0;
	if ((x1<x2 + widht2 && x1 + widht1 > x2) && (y1<y2 + height2 && y1 + height1 > y2)) { ukitzendu = 1; }
	return ukitzendu;
}
void animaziofuntzioa(int* inertzia, int* kont, int* animazio, int* eskuina, int* ezker) {
	if (*animazio == 9)* animazio = 7;
	if (*inertzia > 0) { (*animazio)++; *kont = 30; }
	if (*animazio > 4 && *inertzia > 0)* animazio = 1;
	if (*inertzia < 0) {
		(*ezker)++;
		*kont = 30;
		*animazio = *ezker + 4;
	}
	if (*ezker > 4 && *inertzia < 0)* ezker = 1;


	(*kont)--;
	if (*kont < 0)
	{
		if (*eskuina == 1)* animazio = 1;
		else *animazio = 5;
	}
	if (*animazio == 7)* animazio = 9;
}
void mugimenduhorizontala(int* Vx, int* inertzia, int* eskuina) {
	ebentu = ebentuaJasoGertatuBada();
	if (ebentu == TECLA_RIGHT) {
		*Vx = 10;
		*inertzia = 3;
		*eskuina = 1;
	}
	if (ebentu == TECLA_LEFT) {
		*Vx = -10;
		*inertzia = -3;
		*eskuina = 0;
	}
	posberri.x = posberri.x + *Vx;
}
void posizioaaktualizatu(void) {
	int a;
	for (a = 1; a < 10; a++) {
		imagenak[a].x = posberri.x;
		imagenak[a].y = posberri.y;
	}
}
void inertziajaitsi(int* inertzia, int* Vx) {
	if (*inertzia < 0)(*inertzia)++;
	if (*inertzia > 0)(*inertzia)--;
	if (*inertzia == 0)* Vx = 0;
}