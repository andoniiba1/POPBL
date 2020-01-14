#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"
#include <time.h>
#include <stdlib.h>
#include"hasierako pantailak.h"
#include"testua.h"
#include"program.h"
#include"matematika.h"
#include"plataformak.h"
#include"oinarri.h"
#include"fisika.h"
#include"musika.h"




#define HISTORIA "agur hoal agur hola agur hola agur asas assd adsada adas adsdas adsa adssdad adsdas asdda adsdad adsda adsda adsda"
#define HISTORIA2 "agur hoal agur hola agur hola agur asas assd adsada adas adsdas adsa adssdad adsdas asdda adsdad adsda adsda adsda eta asad asdasd ada"


#define OINARRIONA ""
#define OINARRITXARRA ""








int jokoa(void);

void menuraitzuli(void);




int main(int argc, char* str[])
{
    
    pantailak = MENUA;

    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }
    musikahasi(".\\sound\\friends.wav");
	soinuakkargatu();
    letratamaina(30);

    while (pantailak != IRTEN)
    {
        if (pantailak == MENUA) {
            menua();
            while (pantailak == MENUA) {

                ebentu = ebentuaJasoGertatuBada();
                
                if (ebentu == SAGU_BOTOIA_EZKERRA)

                {
                    pos = saguarenPosizioa();
                    if ((pos.x > 500) && (pos.x < 500 + 70) && (pos.y > 130) && (pos.y < 130 + 70)) { pantailak = JOKOA;  }

                    if ((pos.x > 500) && (pos.x < 500 + 70) && (pos.y > 220) && (pos.y < 220 + 70)) { pantailak = INSTRUKZIOAK; }
                    if ((pos.x > 500) && (pos.x < 500 + 70) && (pos.y > 310) && (pos.y < 310 + 70)) { pantailak = KREDITUAK; }
                    if ((pos.x > 500) && (pos.x < 500 + 70) && (pos.y > 400) && (pos.y < 400 + 70)) { pantailak = IRTEN; }
                }
				itxi();

            }
            toggleMusic();
            
        }


        if (pantailak == JOKOA) {
            jokoa();
           
        }
        if (pantailak == INSTRUKZIOAK) {
            instrukzioak();
            while (pantailak == INSTRUKZIOAK) {

				menuraitzuli();
				itxi();
            }
        }
        if (pantailak == KREDITUAK) {
            kredituak();
            while (pantailak == KREDITUAK) {
                
				menuraitzuli();
				itxi();
            }
            
        }
        toggleMusic();
    }
}





int jokoa(void)
{
    int puntuazioiratzarri,puntuazioplataforma,puntuazioklase;
    
    while (pantailak == JOKOA) {
		
		/*puntuazioiratzarri=iratzarri();
		switch (puntuazioiratzarri)
		{
			case 0:
				historia(ESNATUONA);
			break;
			case 1:
				historia(ESNATUBERANDU);
			break;
			case 2:
				historia(ESNATUOSOBERANDU);
			break;
			case 3:
				historia(EZESNATU);
			break;
		}*/
		puntuazioplataforma=plataformak();

       //puntuazio=matematika();
       // puntuazioa(puntuazio);
       // historia(HISTORIA);
        
		
        //puntuazio = oinarri();
        //puntuazioa(puntuazio);
        //puntuazio = fisika();
        //puntuazioa(puntuazio);
        //puntuazio = redes();
        //puntuazioa(puntuazio);
       // historia(HISTORIA2);
        puntuazioklase = program();
		
        if (pantailak == JOKOA) { pantailak = MENUA; }
    }
    return 0;
}
void menuraitzuli(void) {
	ebentu = ebentuaJasoGertatuBada();
	if (ebentu == SAGU_BOTOIA_EZKERRA)
	{
		pos = saguarenPosizioa();
		if ((pos.x > 0) && (pos.x < 70) && (pos.y > 0) && (pos.y < 70)) { pantailak = MENUA; }
	}
}