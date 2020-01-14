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
#define AUKERA12 "Headerra eta funtzioak orri desberdinetan jarri behar dira?"
#define AUKERA13 "Dena ondo daukat, zergatik ez du egiten?"
#define TXAPA2 "Gainera etxerako beste ariketa bat bidaliko dizuet. Gaur klasean ikusi dugunarekin egiteko gai izan beharko zinatekete eta bestela moodleleko apuntetan begiratu dezakezue. Gaur gaueko 10etarako egitea lortzen duzuena entregatu behar duzue. Hurrengo klasean ariketa klasean zuzenduko dugu eta dituzuen dudak argitzen saiatuko naiz. Espero dut denok ariketa egiten saiatzea bestela zeuentzako izango da txarragoa."
#define AUKERA21 "Noizko entregatu behar da?"
#define AUKERA22 "Ez badut lortzen egitea zer egiten dut?"
#define AUKERA23 "Dudaren bat badaukagu al dizugu korreotik galdetu?"
#define TXAPA3 "Hurrengo asteartean 7:45etan, seihilabeteko azken kontrol puntua izango dugu. Saiatu ahalik eta lehenen iristen kontrol puntura, ahalik eta azkarren hasi ahal izateko eta ez etortzeko gero denbora falta zaizuela esanez. Gainera ez ahaztu idazteko boligrafo bat eta ordenagailuaren kargagailua eramateaz. Ikasiko duzuena honezkero ikasita egon beharko litzake, beraz azken egunean ikasteak ez dizue ezertarako balioko."
#define AUKERA31 "Bukaerako notaren zer ehuneko izango da kontrol puntu hau?"
#define AUKERA32 "Kontrola nolakoa izango da ?"
#define AUKERA33 "Beste kontrol punturik egongo da?"
#define ZUZENA "Oso galdera ona"
#define OKERRA "Ez noa galdera horri erantzutera"
#define GALDERA "Zer galdetuko duzu?"

void txapapantaila(char* txapa) {

    pantailaGarbitu();
	letratamaina(20);
	irudiakpantailaratu(0, 0, 0, ".\\img\\program.bmp");
    parrafoaidatzi(310, 10, 80, txapa,0X00, 0X00, 0X00);
	letratamaina(30);
    pantailaBerriztu();
    ezkerbotoibukle();
}
void zuzenoker(int zuzena) {
    pantailaGarbitu();
    letratamaina(60);
    if (zuzena == 1) {
        textuaIdatzi(300, 300, ZUZENA,0XFF, 0XFF, 0XFF);
    }
    else {
        textuaIdatzi(100, 300, OKERRA, 0XFF, 0XFF, 0XFF);
    }
    letratamaina(30);
    pantailaBerriztu();
    ezkerbotoibukle();

}
int program(void) {

    int erantzuna = 0, zuzenaalda = 0, puntuazioa = 0;

    txapapantaila(TXAPA3);
    erantzuna = aukerak(AUKERA11, AUKERA12, AUKERA13);
    if (erantzuna == 1) {
        zuzenaalda = 1;
        puntuazioa++;
    }
    zuzenoker(zuzenaalda);
    zuzenaalda = 0;
    txapapantaila(TXAPA2);
    erantzuna = aukerak(AUKERA21, AUKERA22, AUKERA23);
    if (erantzuna == 1) {
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
    pantailaGarbitu();
    letratamaina(50);
    textuaIdatzi(300, 100, GALDERA, 0XFF, 0XFF, 0XFF);
    letratamaina(30);
    laukizuzenamarraztu(900, 650, 1000, 700, 0XF0, 0XF0, 0X00);
    markoamarraztu(50, 200, 1030, 300, 5, 0XF0, 0XF0, 0X00);
    textuaIdatzi(75, 230, aukera1, 0XFF, 0XFF, 0XFF);
    markoamarraztu(50, 350, 1030, 450, 5, 0XF0, 0XF0, 0X00);
    textuaIdatzi(75, 380, aukera2, 0XFF, 0XFF, 0XFF);
    markoamarraztu(50, 500, 1030, 600, 5, 0XF0, 0XF0, 0X00);
    textuaIdatzi(75, 530, aukera3, 0XFF, 0XFF, 0XFF);
    pantailaBerriztu();

    while (pantailak == JOKOA) {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();

            if ((pos.x > 50) && (pos.x < 1030) && (pos.y > 200) && (pos.y < 300)) {
                aukeratu(1);
                aukeratualdu = 1;
            }
            if ((pos.x > 50) && (pos.x < 1030) && (pos.y > 350) && (pos.y < 450)) {
                aukeratu(2);
                aukeratualdu = 2;
            }
            if ((pos.x > 50) && (pos.x < 1030) && (pos.y > 500) && (pos.y < 600)) {
                aukeratu(3);
                aukeratualdu = 3;
            }
            if ((pos.x > 900) && (pos.x < 1000) && (pos.y > 650) && (pos.y < 700) && (aukeratualdu != 0)) {
                pantailaGarbitu();
                pantailaBerriztu();
                return aukeratualdu;
            }

        }
        if (ebentu == TECLA_ESCAPE) { pantailak = IRTEN; }
        if (ebentu == GERTAERA_IRTEN) { pantailak = IRTEN; }

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
        markoamarraztu(50, 200, 1030, 300, 5, 0XF0, 0XF0, 0XFF);
        markoamarraztu(50, 350, 1030, 450, 5, 0XF0, 0XF0, 0X00);
        markoamarraztu(50, 500, 1030, 600, 5, 0XF0, 0XF0, 0X00);

    }
    else if (aukera == 2) {
        markoamarraztu(50, 200, 1030, 300, 5, 0XF0, 0XF0, 0X00);
        markoamarraztu(50, 350, 1030, 450, 5, 0XF0, 0XF0, 0XFF);
        markoamarraztu(50, 500, 1030, 600, 5, 0XF0, 0XF0, 0X00);
    }
    else if (aukera == 3) {
        markoamarraztu(50, 200, 1030, 300, 5, 0XF0, 0XF0, 0X00);
        markoamarraztu(50, 350, 1030, 450, 5, 0XF0, 0XF0, 0X00);
        markoamarraztu(50, 500, 1030, 600, 5, 0XF0, 0XF0, 0XFF);
    }
    pantailaBerriztu();

}