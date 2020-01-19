#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"
#include<time.h>
#include<stdlib.h>

#include "oinarri.h"
int oinarri(void) {
	int puntuazioa = 0, irudizenbakia = 0, a = 0, kont = 0,inertzia=0,kont2=0,animazio=0,eskuina=0,ezker=0,Vx=0;
	srand((int)time(NULL));
	posberri.x = 500;
	posberri.y = 500;
	oinarrikargatu();
	while (pantailak == JOKOA && kont < 30) {

		while (irudizenbakia < 3) {
			notaksortu(irudizenbakia,&kont);
			notaklurrera(irudizenbakia);
			konsejoa[irudizenbakia].y = konsejoa[irudizenbakia].y + 5;
			pantailaGarbitu();
			irudibatMarraztu(imagenak[0].id);
			irudiaMugitu(konsejoa[irudizenbakia].id, konsejoa[irudizenbakia].x, konsejoa[irudizenbakia].y);
			notakmarraztu(3);
			mugimenduhorizontala(&Vx, &inertzia, &eskuina);
			
			animaziofuntzioa(&inertzia, &kont2, &animazio, &eskuina, &ezker);
			
			posizioaaktualizatu();

			ebentu = ebentuaJasoGertatuBada();
			itxi();

			notakharrapatu(animazio,irudizenbakia,&puntuazioa);


			irudiaMugitu(imagenak[animazio].id, imagenak[animazio].x, imagenak[animazio].y);
			
			irudibatMarraztu(imagenak[animazio].id);
			pantailaBerriztu();

			inertziajaitsi(&inertzia, &Vx);
			irudizenbakia++;
			a = 0;
		}
		irudizenbakia = 0;
		SDL_Delay(30);


	}
	puntuazioa=oinarripuntuazioa(puntuazioa);
	
	return puntuazioa;
}
void notakmarraztu(int kopurua) {
	int a = 0;
	while (a < kopurua) {
		irudibatMarraztu(konsejoa[a].id);
		a++;
	}
}
int mugihorizontal(int x) {
	int posberri;
	posberri = x;
	if (ebentu == TECLA_RIGHT) {
		posberri = posberri + 15;
	}
	if (ebentu == TECLA_LEFT) {
		posberri = posberri - 15;
	}
	return posberri;
}
int oinarripuntuazioa(int puntuazioa) {
	if (puntuazioa > 10)puntuazioa = 3;
	else {
		if (puntuazioa > 5)puntuazioa = 2;
		else {
			if (puntuazioa > 0)puntuazioa = 1;
			else puntuazioa = 0;
		}
	}
	return puntuazioa;
}
void oinarrikargatu() {
	int irudizenbakia = 0;
	while (irudizenbakia < 3) {
		if (rand() % 2) {
			konsejoa[irudizenbakia].id = irudiaKargatu(".\\img\\ONDO.bmp");
			konsejoa[irudizenbakia].aprobatu = 1;
		}
		else {
			konsejoa[irudizenbakia].id = irudiaKargatu(".\\img\\GAIZKI.bmp");
			konsejoa[irudizenbakia].aprobatu = 0;
		}

		irudizenbakia++;
	}

	irudiakargaposizioan(0, 0, 0, ".\\img\\oinarri.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 1, ".\\img\\xlgeldi.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 2, ".\\img\\xlkorrika1.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 3, ".\\img\\xlkorrika2.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 4, ".\\img\\xlkorrika3.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 5, ".\\img\\xlgeldiezker.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 6, ".\\img\\xlkorrika1ezker.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 9, ".\\img\\xlkorrika2ezker.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 8, ".\\img\\xlkorrika3ezker.bmp");
}
void notaksortu(int irudizenbakia,int *kont) {
	if (konsejoa[irudizenbakia].erortzen == 0) {


		konsejoa[irudizenbakia].x = rand() % 930;
		if (konsejoa[irudizenbakia].behea != 1) {

			konsejoa[irudizenbakia].y = -irudizenbakia * 240;
		}
		else {
			if (rand() % 2 == 0) {
				konsejoa[irudizenbakia].id = irudiaKargatu(".\\img\\ONDO.bmp");
				konsejoa[irudizenbakia].aprobatu = 1;
			}
			else {
				konsejoa[irudizenbakia].id = irudiaKargatu(".\\img\\GAIZKI.bmp");
				konsejoa[irudizenbakia].aprobatu = 0;
			}
			konsejoa[irudizenbakia].y = 0;
		}
		konsejoa[irudizenbakia].erortzen = 1;
		(*kont)++;
	}
}
void notakharrapatu(int animazio,int irudizenbakia,int *puntuazioa) {
	if (chocacon(imagenak[animazio].x, imagenak[animazio].y, 80, 130, konsejoa[irudizenbakia].x, konsejoa[irudizenbakia].y, 200, 150) == 1) {
		konsejoa[irudizenbakia].erortzen = 0;
		konsejoa[irudizenbakia].behea = 1;
		if (konsejoa[irudizenbakia].aprobatu == 1) {
			(*puntuazioa)++;
			soinua(".\\sound\\ondo.wav", 1);
		}
		else {
			(*puntuazioa)--;
			soinua(".\\sound\\gaizki.wav", 10);
		}
	}
}
void notaklurrera(int irudizenbakia) {
	if (konsejoa[irudizenbakia].y > 580) {
		konsejoa[irudizenbakia].erortzen = 0;
		konsejoa[irudizenbakia].behea = 1;
	}
}