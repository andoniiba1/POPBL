#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"

#include "hasierako pantailak.h"
//#define HASIERAKOPANTAILAK


void menua(void)
{
    pantailaGarbitu();
	
    irudiakpantailaratu(0, 0, 0, ".\\img\\menua.bmp");
    pantailaBerriztu();
	
}

void kredituak(void)
{
    pantailaGarbitu();
    irudiakpantailaratu(0, 0, 0, ".\\img\\EGILEAK.bmp");
	irudiakpantailaratu(40, 600, 1, ".\\img\\gezia2.bmp");
    pantailaBerriztu();
}
void instrukzioak(void)
{
	botoidatuak();
	instrukziopantailak = GENERALA;
    pantailaGarbitu();
    irudiakpantailaratu(0, 0, 0, ".\\img\\azalpenak nagusia.bmp");
	irudiakpantailaratu(40, 600, 1, ".\\img\\gezia2.bmp");
    pantailaBerriztu();
	while (pantailak == NOLAJOKATU) {

		
		botoipantailak();
		itxi();
	}
}
void historia(char* historia) {
	
    pantailaGarbitu();

	irudiakpantailaratu(0, 0, 0, ".\\img\\EGIL.bmp");
    parrafoaidatzi(120, 120, 60, historia, 0X00, 0X00, 0X00);
	irudiakpantailaratu(920,580, 1, ".\\img\\gezia1.bmp");
    

    pantailaBerriztu();
	fletxabuklehurrengoa();

}
void ezkerbotoibukle(void) {
    
    while (pantailak == JOKOA) {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            return;

        }
		itxi();

    }
}
void fletxabuklehurrengoa(void) {

	while (pantailak == JOKOA) {
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == SAGU_BOTOIA_EZKERRA)
		{
			pos = saguarenPosizioa();
			if ((pos.x > 920) && (pos.x < 1010) && (pos.y > 580) && (pos.y < 670)) { soinua(".\\sound\\botoia.wav", 4); return; }
			

		}
		itxi();

	}
}
void puntuazioa(int puntu) {
    char puntuak[128];
    pantailaGarbitu();

    puntuak[0] = puntu + '0';
    puntuak[1] = '\0';
    pantailaGarbitu();
    textuaIdatzi(100, 100, puntuak, 0XFF, 0XFF, 0XFF);
    pantailaBerriztu();
    markoamarraztu(20, 20, 1060, 700, 20, 0XFF, 0XFF, 0XFF);

    pantailaBerriztu();
    ezkerbotoibukle();
}
void itxi() {
	if (ebentu == TECLA_ESCAPE) { pantailak = IRTEN; }
	if (ebentu == GERTAERA_IRTEN) { pantailak = IRTEN; }
}
void puntuaziotestua(int puntuak, char* bikain, char* ondo, char* gaizki, char* desastre) {
	switch (puntuak)
	{
		case 3:
			historia(bikain);
			break;
		case 2:
			historia(ondo);
			break;
		case 1:
			historia(gaizki);
			break;
		case 0:
			historia(desastre);
			break;
	}
}

void botoipantailak(void) {
	int a = 0;
	
	ebentu = ebentuaJasoGertatuBada();
	if (ebentu == SAGU_BOTOIA_EZKERRA)
	{
		pos = saguarenPosizioa();
		if ((pos.x > 40) && (pos.x < 130) && (pos.y > 600) && (pos.y < 690)) { pantailak = MENUA; }
		while (instrukziopantailak == GENERALA && a<7) {
			if ((pos.x > botoia[a].x1) && (pos.x < botoia[a].x2) && (pos.y > botoia[a].y1) && (pos.y < botoia[a].y2)) { instrukziopantailak = a; }
			a++;
		}
		a = 0;
		instrukziobakoitza(ESNATU,".\\img\\Esnatu azalpena.bmp" );
		instrukziobakoitza(PLATABIDEA,".\\img\\Plataformak azalpena.bmp");
		instrukziobakoitza(MATE, ".\\img\\Matematika azalpena.bmp");
		instrukziobakoitza(OINARRI,".\\img\\Oinarri azalpena.bmp" );
		instrukziobakoitza(REDES,".\\img\\Redes azalpena.bmp" );
		instrukziobakoitza(PROGRAM, ".\\img\\Program azalpena.bmp");
		instrukziobakoitza(FISIKA,".\\img\\Fisika azalpena.bmp" );
	}
}
void instrukziobakoitza(int jokoinstrukzioa, char* izena) {
	if (instrukziopantailak == jokoinstrukzioa) {
		pantailaGarbitu();
		irudiakpantailaratu(0, 0, 0, izena);
		irudiakpantailaratu(40, 600, 1, ".\\img\\gezia2.bmp");
		pantailaBerriztu();
		while (pantailak == NOLAJOKATU && instrukziopantailak == jokoinstrukzioa) {
			generaleraitzuli();
			itxi();
		}
		pantailaGarbitu();
		irudiakpantailaratu(0, 0, 0, ".\\img\\azalpenak nagusia.bmp");
		irudiakpantailaratu(40, 600, 1, ".\\img\\gezia2.bmp");
		pantailaBerriztu();

	}
}
void generaleraitzuli(void) {
	ebentu = ebentuaJasoGertatuBada();
	if (ebentu == SAGU_BOTOIA_EZKERRA)
	{
		pos = saguarenPosizioa();
		if ((pos.x > 40) && (pos.x < 130) && (pos.y > 600) && (pos.y < 690)) { instrukziopantailak = GENERALA; }
	}
}
void menuraitzuli(void) {


	ebentu = ebentuaJasoGertatuBada();
	if (ebentu == SAGU_BOTOIA_EZKERRA)
	{
		pos = saguarenPosizioa();
		if ((pos.x > 40) && (pos.x < 130) && (pos.y > 600) && (pos.y < 690)) { pantailak = MENUA; }
	}
}

void botoidatuak(void){
	botoia[0].x1 = 56 ;
	botoia[0].y1 = 50;
	botoia[0].x2 = 248;
	botoia[0].y2 = 242;
	botoia[1].x1 = 309;
	botoia[1].y1 = 95;
	botoia[1].x2 = 502;
	botoia[1].y2 = 291;
	botoia[2].x1 = 440;
	botoia[2].y1 = 369;
	botoia[2].x2 = 640;
	botoia[2].y2 = 575;
	botoia[3].x1 = 780;
	botoia[3].y1 = 375;
	botoia[3].x2 = 980;
	botoia[3].y2 = 580;
	botoia[4].x1 = 560;
	botoia[4].y1 = 40;
	botoia[4].x2 = 760;
	botoia[4].y2 = 245;
	botoia[5].x1 = 815;
	botoia[5].y1 = 90;
	botoia[5].x2 = 1015;
	botoia[5].y2 = 300;
	botoia[6].x1 = 105;
	botoia[6].y1 = 375;
	botoia[6].x2 = 305;
	botoia[6].y2 = 575;
	
}