#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"

#include "oinarri.h"
int oinarri(void) {
	int puntuazioa = 0, irudizenbakia = 0, a = 0, kont = 0,inertzia=0,kont2=0,animazio=0,eskuina=0,ezker=0,Vx=0;
	srand(time(NULL));
	while (irudizenbakia < 3) {
		if (rand() % 2) { konsejoa[irudizenbakia].id = irudiaKargatu(".\\img\\ONDO.bmp"); }
		else { konsejoa[irudizenbakia].id = irudiaKargatu(".\\img\\GAIZKI.bmp"); }

		irudizenbakia++;
	}
	posberri.x = 500;
	posberri.y = 500;
	irudiakargaposizioan(0, 0, 0, ".\\img\\oinarri.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 1, ".\\img\\xlgeldi.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 2, ".\\img\\xlkorrika1.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 3, ".\\img\\xlkorrika2.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 4, ".\\img\\xlkorrika3.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 5, ".\\img\\xlgeldiezker.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 6, ".\\img\\xlkorrika1ezker.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 9, ".\\img\\xlkorrika2ezker.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 8, ".\\img\\xlkorrika3ezker.bmp");
	while (pantailak == JOKOA && kont < 30) {

		while (irudizenbakia < 3) {
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
				kont++;
			}
			if (konsejoa[irudizenbakia].y > 580) {
				konsejoa[irudizenbakia].erortzen = 0;
				konsejoa[irudizenbakia].behea = 1;
			}
			konsejoa[irudizenbakia].y = konsejoa[irudizenbakia].y + 5;
			pantailaGarbitu();
			irudibatMarraztu(imagenak[0].id);
			irudiaMugitu(konsejoa[irudizenbakia].id, konsejoa[irudizenbakia].x, konsejoa[irudizenbakia].y);
			konsejoakmarraztu(3);
			mugimenduhorizontala(&Vx, &inertzia, &eskuina);
			
			animaziofuntzioa(&inertzia, &kont2, &animazio, &eskuina, &ezker);
			
			posizioaaktualizatu();

			ebentu = ebentuaJasoGertatuBada();
			itxi();

			if (chocacon(imagenak[animazio].x, imagenak[animazio].y, 80, 130, konsejoa[irudizenbakia].x, konsejoa[irudizenbakia].y, 200, 150) == 1) {
				konsejoa[irudizenbakia].erortzen = 0;
				konsejoa[irudizenbakia].behea = 1;
				if (konsejoa[irudizenbakia].aprobatu == 1) {
					puntuazioa++;
					soinua(".\\sound\\ondo.wav",1);
				}
				else {
					puntuazioa--;
					soinua(".\\sound\\gaizki.wav",10);
				}
			}


			irudiaMugitu(imagenak[animazio].id, imagenak[animazio].x, imagenak[animazio].y);
			
			irudibatMarraztu(imagenak[animazio].id);
			pantailaBerriztu();

			if (inertzia < 0)inertzia++;
			if (inertzia > 0)inertzia--;
			if (inertzia == 0)Vx = 0;
			irudizenbakia++;
			a = 0;
		}
		irudizenbakia = 0;
		SDL_Delay(30);


	}
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
void konsejoakmarraztu(int kopurua) {
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