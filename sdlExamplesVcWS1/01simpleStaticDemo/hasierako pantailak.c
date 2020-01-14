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
    pantailaBerriztu();
}
void instrukzioak(void)
{
    pantailaGarbitu();
    irudiakpantailaratu(0, 0, 0, ".\\img\\git2.bmp");
    pantailaBerriztu();
}
void historia(char* historia) {
    
    pantailaGarbitu();

    parrafoaidatzi(120, 120, 60, historia, 0XFF, 0XFF, 0XFF);
    markoamarraztu(20, 20, 1060, 700, 20, 0XFF, 0XFF, 0XFF);

    pantailaBerriztu();
    ezkerbotoibukle();
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