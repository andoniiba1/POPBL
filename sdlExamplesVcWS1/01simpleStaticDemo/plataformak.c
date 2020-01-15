#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"

#include "plataformak.h"

int plataformak(void) {
	
	int animazio = 1, kont = 0, ezker = 0, Vy = 0, AzeY = 3, Vx = 0,  inertzia = 0,  eskuina = 1,salto=0,amaiera=0, hondoratu=0, aldaketa=0,puntuazioa=800,hil=0,soinudenbora=0;
	float t = 0;
	posberri.x = 5;
	posberri.y = 525;


	irudiakargaposizioan(0, 0, 0, ".\\img\\Plataformak.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 1, ".\\img\\geldi.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 2, ".\\img\\korrika1.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 3, ".\\img\\korrika2.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 4, ".\\img\\korrika3.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 5, ".\\img\\geldiezker.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 6, ".\\img\\korrika1ezker.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 9, ".\\img\\korrika2ezker.bmp");
	irudiakargaposizioan(posberri.x, posberri.y, 8, ".\\img\\korrika3ezker.bmp");

	plataformdatuak();
	while (pantailak == JOKOA && amaiera == 0 ) {



		mugimenduhorizontala(&Vx, &inertzia, &eskuina);
		soinudenbora--;
		if (inertzia != 0 && soinudenbora<0 && salto==0 && posberri.y>130) {
			soinua(".\\sound\\korrika.wav", 7);
			soinudenbora = 20;
		}
		if (ebentu == TECLA_SPACE && salto == 0) {

			Vy = -40;
			salto = 1;
			soinua(".\\sound\\jauzia.wav", 6);
		}

		
		
		if(hondoratu==0)Vy = Vy + AzeY * t;
		aldaketa = Vy * t;
		if (aldaketa > 25)aldaketa = 25;
		posberri.y = posberri.y + aldaketa;
		t = t + 0.05;
	    
		
		animaziofuntzioa(&inertzia, &kont, &animazio, &eskuina, &ezker);
		
		if (plataformatxokea(posberri.x, posberri.y, 38, 60) != 1) {
			posizioaaktualizatu();
		}
		else {
			posizioamantendu();
			if (aldaketa > 0)erorketa(&salto, &t, &aldaketa);
			else Vy = 5;
		}

		irudiaMugitu(imagenak[animazio].id, imagenak[animazio].x, imagenak[animazio].y);

		pantailaGarbitu();

		irudibatMarraztu(imagenak[0].id);
		irudibatMarraztu(imagenak[animazio].id);
		pantailaBerriztu();

		itxi();

		if (inertzia < 0)inertzia++;
		if (inertzia > 0)inertzia--;
		if (inertzia == 0)Vx = 0;

		if (chocacon(imagenak[animazio].x, imagenak[animazio].y,40,60,574,601,200,118==1)) {
			
			hondoratu++;
			Vy = 5;
			t = 1;
			hil = 1;
			
		    
		}
		if (chocacon(imagenak[animazio].x, imagenak[animazio].y, 40, 60, 574, 690, 200, 50 == 1) || chocacon(imagenak[animazio].x, imagenak[animazio].y, 40, 60, 1070, 550, 40, 80 == 1)) {
			amaiera = 1;
		}

		SDL_Delay(30);
		puntuazioa--;
	}
	if (puntuazioa > 300)puntuazioa = 3;
	else {
		if (puntuazioa > 0)puntuazioa = 2;
		else puntuazioa = 1;
	}
	if (hil == 1)puntuazioa = 0;
	return puntuazioa;
}

void plataformdatuak(void) {
	plataform[0].x = 175;
	plataform[0].y = 490;
	plataform[0].width = 115;
	plataform[0].height = 30;
	plataform[1].x = 40;
	plataform[1].y = 384;
	plataform[1].width = 115;
	plataform[1].height = 21;
	plataform[2].x = 155;
	plataform[2].y = 265;
	plataform[2].width = 125;
	plataform[2].height = 30;
	plataform[3].x = 345;
	plataform[3].y = 265;
	plataform[3].width = 235;
	plataform[3].height = 400;
	plataform[4].x = 255;
	plataform[4].y = 210;
	plataform[4].width = 385;
	plataform[4].height = 60;
	plataform[5].x = 0;
	plataform[5].y = 591;
	plataform[5].width = 330;
	plataform[5].height = 129;
	plataform[6].x = 325;
	plataform[6].y = 165;
	plataform[6].width = 37;
	plataform[6].height = 40;
	plataform[7].x = 365;
	plataform[7].y = 140;
	plataform[7].width = 127;
	plataform[7].height = 64;
	plataform[8].x = 446;
	plataform[8].y = 88;
	plataform[8].width = 48;
	plataform[8].height = 54;
	plataform[9].x = 730;
	plataform[9].y = 245;
	plataform[9].width = 125;
	plataform[9].height = 30;
	plataform[10].x = 630;
	plataform[10].y = 400;
	plataform[10].width = 130;
	plataform[10].height = 30;
	plataform[11].x = 775;
	plataform[11].y = 578;
	plataform[11].width = 305;
	plataform[11].height = 242;
	plataform[12].x = -20;
	plataform[12].y = 0;
	plataform[12].width = 10;
	plataform[12].height = 720;

}
int plataformatxokea(int x, int y, int widht, int height) {
	int a = 0, ukitzendu = 0;
	while (a <= 12 && ukitzendu == 0) {
		if (chocacon(x, y, widht, height, plataform[a].x, plataform[a].y, plataform[a].width, plataform[a].height) == 1)ukitzendu = 1;
		a++;
	}
	return ukitzendu;
}

int chocacon(int x1, int y1, int widht1, int height1, int x2, int y2, int widht2, int height2) {
	int ukitzendu = 0;
	if ((x1<x2 + widht2 && x1 + widht1 > x2) && (y1<y2 + height2 && y1 + height1 > y2)) { ukitzendu = 1; }
	return ukitzendu;
}
void posizioamantendu(void) {
	int a;
	for (a = 1; a < 10; a++) {
		posberri.x = imagenak[a].x;
		posberri.y = imagenak[a].y;
	}
}
void posizioaaktualizatu(void) {
	int a;
	for (a = 1; a < 10; a++) {
		imagenak[a].x = posberri.x;
		imagenak[a].y = posberri.y;
	}
}
void erorketa(int *salto,int *t, int *aldaketa) {
	int a;
	if (plataformatxokea(posberri.x, posberri.y + *aldaketa, 38, 60) == 1) {
		a = 1;
		while (plataformatxokea(posberri.x, posberri.y + a, 38, 60) != 1) {
			posberri.y = posberri.y + a;
			a++;
		}
		*salto = 0;
		*t = 0;
	}



}
void animaziofuntzioa(int *inertzia,int *kont,int *animazio, int *eskuina, int *ezker) {
	if (*animazio == 9)*animazio = 7;
	if (*inertzia > 0) { (*animazio)++; *kont = 30; }
	if (*animazio > 4 && *inertzia > 0)*animazio = 1;
	if (*inertzia < 0) { 
		(*ezker)++; 
		*kont = 30; 
		*animazio = *ezker + 4; 
	}
	if (*ezker > 4 && *inertzia < 0)*ezker = 1;


	(*kont)--;
	if (*kont < 0)
	{
		if (*eskuina == 1)*animazio = 1;
		else *animazio = 5;
	}
	if (*animazio == 7)*animazio = 9;
}
void mugimenduhorizontala(int *Vx, int *inertzia, int *eskuina) {
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