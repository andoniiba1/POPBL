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

                    if ((pos.x > 500) && (pos.x < 500 + 70) && (pos.y > 220) && (pos.y < 220 + 70)) { pantailak = NOLAJOKATU; }
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
        if (pantailak == NOLAJOKATU) {
            instrukzioak();
           
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
    int puntuazioiratzarri,puntuazioplataforma,puntuazioklase,eguna=0,egunekopuntuak=0,astekopuntuak=0;
    
    while (pantailak == JOKOA) {
		puntuazioiratzarri = redes();
		/*eguna++;
		puntuazioiratzarri = 0;
		puntuazioplataforma = 0;
		puntuazioklase = 0;
		puntuazioiratzarri=iratzarri();
		puntuaziotestua(puntuazioiratzarri, ESNATUONA, ESNATUBERANDU, ESNATUOSOBERANDU, EZESNATU);
		if (puntuazioiratzarri != 0 && pantailak==JOKOA) {
			puntuazioplataforma = plataformak();
			puntuaziotestua(puntuazioplataforma, KLASEAONDOIRITSI, KLASEABERANDU, KLASEOSOBERANDU, URETAERORI);
		}
		if (puntuazioplataforma != 0 && pantailak == JOKOA) {
			switch (eguna)
			{
			case 1:
				historia(MATEAZALPENA);
				puntuazioklase = matematika();
				puntuaziotestua(puntuazioklase, MATEONDO, MATETARTE, MATEGAIZKI, MATEOSOGAIZKI);
				break;
			case 2:
				historia(OINARRIAZALPENA);
				puntuazioklase = oinarri();
				puntuaziotestua(puntuazioklase, OINARRIONDO, OINARRITARTE, OINARRIGAIZKI, OINARRIOSOGAIZKI);
				break;
			case 3:
				historia(REDESAZALPENA);
				puntuazioklase = redes();
				puntuaziotestua(puntuazioklase, REDESONDO, REDESTARTE, REDESGAIZKI, REDESOSOGAIZKI);
				break;
			case 4:
				historia(PROGRAMAZALPENA);
				puntuazioklase = program();
				puntuaziotestua(puntuazioklase, PROGRAMONDO, PROGRAMTARTE, PROGRAMGAIZKI, PROGRAMOSOGAIZKI);
				break;
			case 5:
				historia(FISIKAAZALPENA);
				puntuazioklase = fisika();
				puntuaziotestua(puntuazioklase, FISIKAONDO, FISIKATARTE, FISIKAGAIZKI, FISIKAOSOGAIZKI);
				break;
			}
		}
		if (pantailak == JOKOA) {
			egunekopuntuak = puntuazioiratzarri + puntuazioplataforma + puntuazioklase;
			if (egunekopuntuak <= 3)historia(EGUNTXARRA);
			else {
				if (egunekopuntuak > 3 && egunekopuntuak <= 6) { historia(EGUNERTAINA); }
				else { historia(EGUNONA); }
			}
		}
		if (pantailak == JOKOA) {
			astekopuntuak = astekopuntuak + egunekopuntuak;
			if (eguna == 5) {
				if (egunekopuntuak <= 15)historia(ASTEONA);
				else {
					if (egunekopuntuak > 15 && egunekopuntuak <= 30) { historia(ASTEERTAINA); }
					else { historia(ASTETXARRA); }
				}
				if (pantailak == JOKOA) { pantailak = MENUA; }
			}
		}*/
       
		
        
    }
    return 0;
}
