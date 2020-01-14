#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"
#include "redes.h"

int redes(void) {
    int puntuazioa;
    pantailaGarbitu();
    redesmarkoak();

    irudiakpantailaratu(50, 100, 0, ".\\img\\a.bmp");
    irudiakpantailaratu(50, 300, 1, ".\\img\\b.bmp");
    irudiakpantailaratu(50, 500, 2, ".\\img\\c.bmp");
    irudiakpantailaratu(175, 125, 3, ".\\img\\redesjokoa.bmp");

    pantailaBerriztu();

    while (pantailak == JOKOA) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();

        irudimugimendua(0);
        irudimugimendua(1);
        irudimugimendua(2);
        if (ebentu == SAGU_BOTOIA_EZKERRA && pos.x > 900 && pos.x < 1000 && pos.y>650 && pos.y < 700) {
            puntuazioa = redespuntuazioa();
            return puntuazioa;
        }

        if (ebentu == TECLA_ESCAPE) { pantailak = IRTEN; }
        if (ebentu == GERTAERA_IRTEN) { pantailak = IRTEN; }

    }
}
void irudimugimendua(int irudizenbakia) {
    int a, b, c;

    if (ebentu == SAGU_BOTOIA_EZKERRA && pos.x > imagenak[irudizenbakia].x && pos.x<(imagenak[irudizenbakia].x + 100) && pos.y>imagenak[irudizenbakia].y && pos.y < (imagenak[irudizenbakia].y + 100)) {
        a = 1;
        b = pos.x - imagenak[irudizenbakia].x;
        c = pos.y - imagenak[irudizenbakia].y;

        while (a == 1) {

            pos = saguarenPosizioa();
			imagenak[irudizenbakia].x = pos.x - b;
			imagenak[irudizenbakia].y = pos.y - c;
            irudiaMugitu(imagenak[irudizenbakia].id, imagenak[irudizenbakia].x, imagenak[irudizenbakia].y);

            pantailaGarbitu();
            redesmarkoak();
            besteirudiakmantendu(irudizenbakia);

            irudibatMarraztu(imagenak[irudizenbakia].id);


            pantailaBerriztu();

            ebentu = ebentuaJasoGertatuBada();
            a = enkajatu(irudizenbakia, 925, 125);
            a = enkajatu(irudizenbakia, 925, 325);
            a = enkajatu(irudizenbakia, 925, 525);
        }
    }
}
void redesmarkoak(void) {


    laukizuzenamarraztu(0, 0, 1080, 720, 0XFF, 0XFF, 0XFF);
    markoamarraztu(850, 50, 1000, 200, 5, 0X00, 0X00, 0X00);
    markoamarraztu(850, 250, 1000, 400, 5, 0X00, 0X00, 0X00);
    markoamarraztu(850, 450, 1000, 600, 5, 0X00, 0X00, 0X00);
    laukizuzenamarraztu(900, 650, 1000, 700, 0X00, 0X00, 0X00);
}
void besteirudiakmantendu(int irudizenbakia) {

    irudibatMarraztu(imagenak[3].id);
    if (irudizenbakia == 0) { irudibatMarraztu(imagenak[1].id); irudibatMarraztu(imagenak[2].id); }
    if (irudizenbakia == 1) { irudibatMarraztu(imagenak[0].id); irudibatMarraztu(imagenak[2].id); }
    if (irudizenbakia == 2) { irudibatMarraztu(imagenak[0].id); irudibatMarraztu(imagenak[1].id); }

}
int enkajatu(int irudizenbakia, int x, int y) {
    int a = 1;
    if (ebentu == SAGU_BOTOIA_EZKERRA && imagenak[irudizenbakia].x > x - 125 && imagenak[irudizenbakia].x < x + 25 && imagenak[irudizenbakia].y>y - 100 && imagenak[irudizenbakia].y < y + 25) {
        a = 0;
		imagenak[irudizenbakia].x = x - 50;
		imagenak[irudizenbakia].y = y - 50;
        irudiaMugitu(imagenak[irudizenbakia].id, imagenak[irudizenbakia].x, imagenak[irudizenbakia].y);
        pantailaGarbitu();
        redesmarkoak();
        irudibatMarraztu(imagenak[irudizenbakia].id);
        besteirudiakmantendu(irudizenbakia);

        pantailaBerriztu();
    }
    else if (ebentu == SAGU_BOTOIA_EZKERRA) { a = 0; }
    return a;
}
int redespuntuazioa(void) {
    int kont = 0;
    if (imagenak[0].x == 875 && imagenak[0].y == 75) {
        kont++;
    }
    if (imagenak[1].x == 875 && imagenak[1].y == 275) {
        kont++;
    }
    if (imagenak[2].x == 875 && imagenak[2].y == 475) {
        kont++;
    }
    return kont;
}