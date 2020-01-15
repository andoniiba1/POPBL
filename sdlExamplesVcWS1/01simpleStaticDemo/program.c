#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"
#include "program.h"

#define TXAPA1 "Gaurko klasean 3.ariketa egingo duzue. Gaiaren hasieran gaude eta ariketa erraza da, horrenbestez 5 minututan egiteko gai izan behar zinatekete, ez bazerate denbora horretan egiteko gai atzeratuta zoaztela esan nahi du. Ariketa funtzioak erabiliz egin behar da eta gogoratu funtzio bakoitzak ezin duela gauza bat baino gehiago, beraz 30 bat funtziorekin nahiko izango da"
#define AUKERA11 "Noiz egin behar da?"
#define AUKERA12 "Header eta funtzioak orri berdinetan jarri behar dira?"
#define AUKERA13 "Dena ondo daukat, zergatik ez du egiten?"
#define TXAPA2 "Gainera etxerako beste ariketa bat bidaliko dizuet. Gaur klasean ikusi dugunarekin egiteko gai izan beharko zinatekete eta bestela moodleleko apuntetan begiratu dezakezue. Gaur gaueko 10etarako egitea lortzen duzuena entregatu behar duzue. Hurrengo klasean ariketa klasean zuzenduko dugu eta dituzuen dudak argitzen saiatuko naiz. Espero dut denok ariketa egiten saiatzea bestela zeuentzako izango da txarragoa."
#define AUKERA21 "Noizko entregatu behar da?"
#define AUKERA22 "Ez badut lortzen egitea zer egiten dut?"
#define AUKERA23 "Dudaren bat badaukagu al dizugu korreotik galdetu?"
#define TXAPA3 "Hurrengo asteartean 7:45etan, seihilabeteko azken kontrol puntua izango dugu. Saiatu ahalik eta lehenen iristen kontrol puntura, ahalik eta azkarren hasi ahal izateko eta ez etortzeko gero denbora falta zaizuela esanez. Gainera ez ahaztu idazteko boligrafo bat eta ordenagailuaren kargagailua eramateaz. Ikasiko duzuena honezkero ikasita egon beharko litzake, beraz azken egunean ikasteak ez dizue ezertarako balioko."
#define AUKERA31 "Bukaerako notaren zer ehuneko izango da?"
#define AUKERA32 "Kontrola nolakoa izango da ?"
#define AUKERA33 "Beste kontrol punturik egongo da?"
#define ZUZENA "Oso galdera ona"
#define OKERRA "Ez noa galdera horri erantzutera"
#define GALDERA "Zer galdetuko duzu?"

void txapapantaila(char* txapa) {

    pantailaGarbitu();
	letratamaina(20);
	irudiakpantailaratu(0, 0, 0, ".\\img\\program.bmp");
	irudiakpantailaratu(920, 580, 1, ".\\img\\gezia1.bmp");
    parrafoaidatzi(310, 10, 80, txapa,0X00, 0X00, 0X00);
	letratamaina(30);
    pantailaBerriztu();
	fletxabuklehurrengoa();
}
void zuzenoker(int zuzena) {
    pantailaGarbitu();
    
    if (zuzena == 1) {
		irudiakpantailaratu(0, 0, 0, ".\\img\\program ona.bmp");
		irudiakpantailaratu(920, 580, 1, ".\\img\\gezia1.bmp");

    }
    else {
		irudiakpantailaratu(0, 0, 0, ".\\img\\program txarra.bmp");
		irudiakpantailaratu(920, 580, 1, ".\\img\\gezia1.bmp");
    }
    
    pantailaBerriztu();
	fletxabuklehurrengoa();

}
int program(void) {

    int erantzuna = 0, zuzenaalda = 0, puntuazioa = 0;

    txapapantaila(TXAPA3);
    erantzuna = aukerak(AUKERA11, AUKERA12, AUKERA13);
    if (erantzuna == 2) {
        zuzenaalda = 1;
        puntuazioa++;
    }
    zuzenoker(zuzenaalda);
    zuzenaalda = 0;
    txapapantaila(TXAPA2);
    erantzuna = aukerak(AUKERA21, AUKERA22, AUKERA23);
    if (erantzuna == 3) {
        zuzenaalda = 1;
        puntuazioa++;
    }
    zuzenoker(zuzenaalda);
    zuzenaalda = 0;
    txapapantaila(TXAPA1);
    erantzuna = aukerak(AUKERA31, AUKERA32, AUKERA33);
    if (erantzuna == 1) {
        zuzenaalda = 1;
        puntuazioa++;
    }
    zuzenoker(zuzenaalda);

    return puntuazioa;


}
int aukerak(char* aukera1, char* aukera2, char* aukera3) {
    int aukeratualdu = 0;
	markodatuak();
    pantailaGarbitu();
	irudiakpantailaratu(0, 0, 0, ".\\img\\programaukerak.bmp");
	irudiakpantailaratu(920, 580, 1, ".\\img\\gezia1.bmp");
    letratamaina(25);
    
    markoamarraztu(marko[0].x1, marko[0].y1, marko[0].x2, marko[0].y2, 5, 0XF0, 0XF0, 0X00);
    textuaIdatzi(marko[0].x1+10, marko[0].y1+30, aukera1, 0X00, 0X00, 0X00);
	markoamarraztu(marko[1].x1, marko[1].y1, marko[1].x2, marko[1].y2, 5, 0XF0, 0XF0, 0X00);
    textuaIdatzi(marko[1].x1 + 10, marko[1].y1 + 30, aukera2, 0X00, 0X00, 0X00);
	markoamarraztu(marko[2].x1, marko[2].y1, marko[2].x2, marko[2].y2, 5, 0XF0, 0XF0, 0X00);
    textuaIdatzi(marko[2].x1 + 10, marko[2].y1 + 30, aukera3, 0X00, 0X00, 0X00);
	letratamaina(30);
    pantailaBerriztu();

    while (pantailak == JOKOA) {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();

            if ((pos.x > marko[0].x1) && (pos.x < marko[0].x2) && (pos.y > marko[0].y1) && (pos.y < marko[0].y2)) {
                aukeratu(1);
                aukeratualdu = 1;
            }
            if ((pos.x > marko[1].x1) && (pos.x < marko[1].x2) && (pos.y > marko[1].y1) && (pos.y < marko[1].y2)) {
                aukeratu(2);
                aukeratualdu = 2;
            }
            if ((pos.x > marko[2].x1) && (pos.x < marko[2].x2) && (pos.y > marko[2].y1) && (pos.y < marko[2].y2)) {
                aukeratu(3);
                aukeratualdu = 3;
            }
            if ((pos.x > 950) && (pos.x < 1040) && (pos.y > 610) && (pos.y < 700) && (aukeratualdu != 0)) {
                pantailaGarbitu();
                pantailaBerriztu();
                return aukeratualdu;
            }

        }
		itxi();

    }
}
void aukeratu(int aukera) {
    /*
     pantailaGarbitu();
     textuaIdatzi(75, 230, AUKERA11);
     textuaIdatzi(75, 380, AUKERA12);
     textuaIdatzi(75, 530, AUKERA13);
     */
    if (aukera == 1) {
        markoamarraztu(marko[0].x1, marko[0].y1, marko[0].x2, marko[0].y2, 5, 0X00, 0X00, 0XFF);
        markoamarraztu(marko[1].x1, marko[1].y1, marko[1].x2, marko[1].y2, 5, 0XF0, 0XF0, 0X00);
        markoamarraztu(marko[2].x1, marko[2].y1, marko[2].x2, marko[2].y2, 5, 0XF0, 0XF0, 0X00);

    }
    else if (aukera == 2) {
		markoamarraztu(marko[0].x1, marko[0].y1, marko[0].x2, marko[0].y2, 5, 0XF0, 0XF0, 0X00);
		markoamarraztu(marko[1].x1, marko[1].y1, marko[1].x2, marko[1].y2, 5, 0X00, 0X00, 0XFF);
		markoamarraztu(marko[2].x1, marko[2].y1, marko[2].x2, marko[2].y2, 5, 0XF0, 0XF0, 0X00);
    }
    else if (aukera == 3) {
		markoamarraztu(marko[0].x1, marko[0].y1, marko[0].x2, marko[0].y2, 5, 0XF0, 0XF0, 0X00);
		markoamarraztu(marko[1].x1, marko[1].y1, marko[1].x2, marko[1].y2, 5, 0XF0, 0XF0, 0X00);
		markoamarraztu(marko[2].x1, marko[2].y1, marko[2].x2, marko[2].y2, 5, 0X00, 0X00, 0XFF);
    }
    pantailaBerriztu();

}
void markodatuak(void) {
	marko[0].x1 = 415;
	marko[0].y1 = 15;
	marko[0].x2 = 1050;
	marko[0].y2 = 115;
	marko[1].x1 = 415;
	marko[1].y1 = 145;
	marko[1].x2 = 1050;
	marko[1].y2 = 245;
	marko[2].x1 = 415;
	marko[2].y1 = 275;
	marko[2].x2 = 1050;
	marko[2].y2 = 375;
}