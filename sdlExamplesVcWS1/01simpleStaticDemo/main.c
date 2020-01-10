#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"
#include <time.h>

#define SOINU_KOP 5
char* soundFiles[] = { ".\\sound\\128GBVHR_01.wav", ".\\sound\\128NIGHT_01.wav", ".\\sound\\132TRANCE_02.wav",
                        ".\\sound\\BugleCall.wav",  ".\\sound\\terminator.wav" };


#define HISTORIA "agur hoal agur hola agur hola agur asas assd adsada adas adsdas adsa adssdad adsdas asdda adsdad adsda adsda adsda"
#define HISTORIA2 "agur hoal agur hola agur hola agur asas assd adsada adas adsdas adsa adssdad adsdas asdda adsdad adsda adsda adsda eta asad asdasd ada"
#define TXAPA1 "Gaurko klasean 3.ariketa egingo duzue. Gairen hasieran gaude eta ariketa erraza da, horrenbestez 5 minututan egiteko gai izan behar zinatekete, ez bazerate denbora horretan egiteko gai atzeratuta zoaztela esan nahi du. Ariketa funtzioak erabiliz egin behar da eta gogoratu funtzio bakoitzak ezin duela gauza bat baino gehiago, beraz 30 bat funtziorekin nahiko izango da"
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
#define OINARRIONA ""
#define OINARRITXARRA ""
typedef struct S_GURE_GAUZAK
{
    int idSounds[SOINU_KOP];
    
}GURE_GAUZAK;


GURE_GAUZAK gureGauzak;

IRUDIAK irudiak[32];

void musikahasi(void);
int menua(void);
int kredituak(void);
int jokoa(void);
int instrukzioak(void);

int lerrotanbanatu(int lerroluzeramax, char* testua);
int aukerak(char* aukera1, char* aukera2, char* aukera3);
void aukeratu(int aukera);
POSIZIOA pos;
POSIZIOA kotxepos;
PANTAILAK pantailak = MENUA;
int ebentu = 0;
char str[50][100];
void irudimugimendua(int irudizenbakia);
void redesmarkoak(void);
void parrafoaidatzi(int hasierax,int hasieray,int karakterlineako, char* testua);
void markoamarraztu(int xhasiera, int yhasiera, int xbukaera, int ybukaera, int lodiera, int gorri, int berde, int urdin);
void besteirudiakmantendu(int irudizenbakia);
int enkajatu(int irudizenbakia, int x, int y);
void puntuazioa(int puntu);
int redespuntuazioa(void);
int program(void);
int redes(void);
void irudiakpantailaratu(int x, int y, int irudizenbakia, char* irudiizena);
void kotxeamarraztu(int aldea);
void plataformak(void);
int chocacon(int x1, int y1, int widht1, int height1, int x2, int y2, int widht2, int height2);
int fisika(void);
int oinarri(void);
int mugihorizontal(int x);
int mugibertikal(int y);
void konsejoakmarraztu(int kopurua);
int plataformatxokea(int x, int y, int widht, int height);
void plataformdatuak(void);
void iratzarri(void);
void irudiakargaposizioan(int x, int y, int irudizenbakia, char* irudiizena);
int matematika(void);
KONSEJOAK konsejoa[5];

int main(int argc, char* str[])
{
    int  i = 0;
    

    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }
    musikahasi();
    for (i = 0; i < SOINU_KOP; i++)
    {
        if ((gureGauzak.idSounds[i] = loadSound(soundFiles[i])) == -1)
        {
            fprintf(stderr, "Unable to load sound %s\n", SDL_GetError());
            return 0;
        }
    }
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
                if (ebentu == TECLA_ESCAPE) { pantailak = IRTEN; }
                if (ebentu == GERTAERA_IRTEN) { pantailak = IRTEN; }

            }
            toggleMusic();
            
        }


        if (pantailak == JOKOA) {
            jokoa();
           
        }
        if (pantailak == INSTRUKZIOAK) {
            instrukzioak();
            while (pantailak == INSTRUKZIOAK) {

                ebentu = ebentuaJasoGertatuBada();
                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    pos = saguarenPosizioa();
                    if ((pos.x > 0) && (pos.x < 70) && (pos.y > 0) && (pos.y < 70)) { pantailak = MENUA; }
                }
                if (ebentu == TECLA_ESCAPE) { pantailak = IRTEN; }
                if (ebentu == GERTAERA_IRTEN) { pantailak = IRTEN; }

            }
        }
        if (pantailak == KREDITUAK) {
            kredituak();
            while (pantailak == KREDITUAK) {
                
                ebentu = ebentuaJasoGertatuBada();
                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    pos = saguarenPosizioa();
                    if ((pos.x > 0) && (pos.x < 70) && (pos.y > 0) && (pos.y < 70)) { pantailak = MENUA; }
                }
                if (ebentu == TECLA_ESCAPE) { pantailak = IRTEN; }
                if (ebentu == GERTAERA_IRTEN) { pantailak = IRTEN; }
            }
            
        }
        toggleMusic();
    }
}

void musikahasi(void) {
    audioInit();
    if (!loadTheMusic(".\\sound\\friends.wav"))
    {
        fprintf(stderr, "Unable to load music %s\n", SDL_GetError());

    }
    playMusic();
}
int menua(void)
{




    pantailaGarbitu();
    irudiak[0].id=irudiaKargatu(".\\img\\menua.bmp");
    
    irudiakpantailaratu(0, 0, 0, ".\\img\\menua.bmp");

    pantailaBerriztu();



    return 0;
}

int kredituak(void)
{



    pantailaGarbitu();

    irudiak[0].id = irudiaKargatu(".\\img\\EGILEAK.bmp");
    irudiaMugitu(irudiak[0].id, 0, 0);
    irudibatMarraztu(irudiak[0].id);

    pantailaBerriztu();


    return 0;
}
int instrukzioak(void)
{



    pantailaGarbitu();

    irudiak[0].id = irudiaKargatu(".\\img\\git1.bmp");
    irudiaMugitu(irudiak[0].id, 100, 100);
    irudibatMarraztu(irudiak[0].id);

    pantailaBerriztu();



    return 0;
}
int hitzluzera(int posizioa, char* str) {
    int luzera = 0;

    while (str[posizioa] != ' ' && str[posizioa]!='\0') {
        luzera++;
        posizioa++;
    }
    return luzera;
}
void parrafoaidatzi(int hasierax,int hasieray,int karakterelineako,char* testua){
    
    int lerrokop = 0;
    int lerroa = 0, distatzia = 50;


    lerrokop = lerrotanbanatu(karakterelineako,testua);
    
    while (lerroa <= lerrokop) {
        textuaIdatzi(hasierax, hasieray + (lerroa * distatzia), str[lerroa]);
        lerroa++;
    }

}
int lerrotanbanatu(int lerroluzeramax, char* testua) {
    int c = 0, hitza = 0, lerroa = 0, lerrokoposizioa = 0;
    
    int lerroluzera = 0;

    while (testua[c] != '\0') {
        hitza = hitzluzera(c, testua);
        lerroluzera += hitza + 1;
        if (lerroluzera < lerroluzeramax) {
            while (testua[c] != ' ' && testua[c] != '\0') {
                str[lerroa][lerrokoposizioa] = testua[c];
                lerrokoposizioa++;
                c++;
            }
            str[lerroa][lerrokoposizioa] = testua[c];
            lerrokoposizioa++;
            c++;
        }
        else {
            str[lerroa][lerrokoposizioa] = '\0';
            lerroa++;
            lerroluzera = 0;
            lerrokoposizioa = 0;
        }
    }
    
    return lerroa;
}
void historia(char* historia) {
    pantailaGarbitu();

    parrafoaidatzi(150,150,50, historia);
    markoamarraztu(20, 20, 1060, 700, 20, 0XFF, 0XFF, 0XFF);

    pantailaBerriztu();
    while (pantailak == JOKOA) {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            return;

        }
        if (ebentu == TECLA_ESCAPE) { pantailak = IRTEN; }
        if (ebentu == GERTAERA_IRTEN) { pantailak = IRTEN; }

    }
}
int jokoa(void)
{
    

    int puntuazio=0,puntuazio2=0;
    
    while (pantailak == JOKOA) {
        //puntuazio=matematika();
        //puntuazioa(puntuazio);
        //historia(HISTORIA);
       //iratzarri();
        //plataformak();
        //puntuazio = oinarri();
        //puntuazioa(puntuazio);
        puntuazio = fisika();
        //puntuazioa(puntuazio);
        puntuazio = redes();
        puntuazioa(puntuazio);
        historia(HISTORIA2);
        puntuazio = program();
        puntuazioa(puntuazio);
        
        
                
        if (pantailak == JOKOA) { pantailak = MENUA; }
         

        
    }


    return 0;
}
void puntuazioa(int puntu) {
    char puntuak[128];
    pantailaGarbitu();

    puntuak[0] = puntu + '0';
    puntuak[1] = '\0';
    pantailaGarbitu();
    textuaIdatzi(100, 100, puntuak);
    pantailaBerriztu();
    markoamarraztu(20, 20, 1060, 700, 20, 0XFF, 0XFF, 0XFF);

    pantailaBerriztu();
    while (pantailak == JOKOA) {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            return;

        }
        if (ebentu == TECLA_ESCAPE) { pantailak = IRTEN; }
        if (ebentu == GERTAERA_IRTEN) { pantailak = IRTEN; }

    }
}
void markoamarraztu(int xhasiera, int yhasiera, int xbukaera, int ybukaera,int lodiera, int gorri, int berde,int urdin) {

    int a;
    arkatzKoloreaEzarri( gorri,berde,urdin);
    for (a=yhasiera; a <= yhasiera+lodiera; a++) {
        zuzenaMarraztu(xhasiera, a, xbukaera, a);
    }
    for (a=xhasiera; a <= xhasiera+lodiera; a++) {
        zuzenaMarraztu(a, yhasiera, a, ybukaera);
    }
    for (a = ybukaera-lodiera; a <= ybukaera; a++) {
        zuzenaMarraztu(xhasiera, a, xbukaera,a);
    }
    for (a = xbukaera-lodiera; a <= xbukaera; a++) {
        zuzenaMarraztu(a, yhasiera, a, ybukaera);
    }
}
void laukizuzenamarraztu(int x1, int y1, int x2, int y2, int gorri, int berde, int urdin) {
    int a;
    arkatzKoloreaEzarri(gorri, berde, urdin);
    for (a = x1; a < x2; a++) {
        zuzenaMarraztu(a, y1, a, y2);
    }
}
void txapapantaila(char* txapa) {
    
    pantailaGarbitu();

    laukizuzenamarraztu(0, 0, 1080, 720, 0XFF, 0XFF, 0XFF);
    parrafoaidatzi(75,75,70, txapa);
    irudiakpantailaratu(650, 400, 0, ".\\img\\maisu.bmp");
    pantailaBerriztu();
    while (pantailak == JOKOA) {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            return;

        }
        if (ebentu == TECLA_ESCAPE) { pantailak = IRTEN; }
        if (ebentu == GERTAERA_IRTEN) { pantailak = IRTEN; }

    }
}
void zuzenoker(int zuzena) {
    pantailaGarbitu();
    letratamaina(60);
    if (zuzena == 1) {
        textuaIdatzi(300, 300, ZUZENA);
    }
    else {
        textuaIdatzi(100, 300, OKERRA);
    }
    letratamaina(30);
    pantailaBerriztu();
    while (pantailak == JOKOA) {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            return;

        }
        if (ebentu == TECLA_ESCAPE) { pantailak = IRTEN; }
        if (ebentu == GERTAERA_IRTEN) { pantailak = IRTEN; }

    }
    
}
int program(void) {
     
        int erantzuna = 0, zuzenaalda=0, puntuazioa=0;
        
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
int aukerak(char* aukera1,char* aukera2, char* aukera3) {
    int aukeratualdu = 0;
    pantailaGarbitu();
    letratamaina(50);
    textuaIdatzi(300, 100, GALDERA);
    letratamaina(30);
    laukizuzenamarraztu(900,650,1000,700, 0XF0, 0XF0, 0X00);
    markoamarraztu(50, 200, 1030, 300, 5, 0XF0, 0XF0, 0X00);
    textuaIdatzi(75, 230, aukera1);
    markoamarraztu(50, 350, 1030, 450, 5, 0XF0, 0XF0, 0X00);
    textuaIdatzi(75, 380, aukera2);
    markoamarraztu(50, 500, 1030, 600, 5, 0XF0, 0XF0, 0X00);
    textuaIdatzi(75, 530, aukera3);
    pantailaBerriztu();

    while (pantailak == JOKOA) {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();
            if ((pos.x > 0) && (pos.x < 70) && (pos.y > 0) && (pos.y < 70)) {
                pantailak = MENUA;
            }
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
            if ((pos.x > 900) && (pos.x < 1000) && (pos.y > 650) && (pos.y < 700) && (aukeratualdu!=0)) {
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
void irudiakpantailaratu(int x,int y,int irudizenbakia,char* irudiizena) {
    irudiak[irudizenbakia].id = irudiaKargatu(irudiizena);
    irudiak[irudizenbakia].x = x;
    irudiak[irudizenbakia].y = y;
    irudiaMugitu(irudiak[irudizenbakia].id, irudiak[irudizenbakia].x, irudiak[irudizenbakia].y);
    irudibatMarraztu(irudiak[irudizenbakia].id);
}
int redes(void) {
    int puntuazioa;
    pantailaGarbitu();
    redesmarkoak();
    
    irudiakpantailaratu(50,100,0, ".\\img\\a.bmp");
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
    
    if (ebentu == SAGU_BOTOIA_EZKERRA && pos.x > irudiak[irudizenbakia].x && pos.x<(irudiak[irudizenbakia].x + 100) && pos.y>irudiak[irudizenbakia].y && pos.y < (irudiak[irudizenbakia].y + 100)) {
        a = 1;
        b = pos.x - irudiak[irudizenbakia].x;
        c = pos.y - irudiak[irudizenbakia].y;

        while (a == 1) {

            pos = saguarenPosizioa();
            irudiak[irudizenbakia].x = pos.x - b;
            irudiak[irudizenbakia].y = pos.y - c;
            irudiaMugitu(irudiak[irudizenbakia].id, irudiak[irudizenbakia].x, irudiak[irudizenbakia].y);

            pantailaGarbitu();
            redesmarkoak();
            besteirudiakmantendu(irudizenbakia);
            
            irudibatMarraztu(irudiak[irudizenbakia].id);

            
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
    laukizuzenamarraztu(900,650,1000,700, 0X00, 0X00, 0X00);
}
void besteirudiakmantendu(int irudizenbakia) {

    irudibatMarraztu(irudiak[3].id);
    if (irudizenbakia == 0) { irudibatMarraztu(irudiak[1].id); irudibatMarraztu(irudiak[2].id); }
    if (irudizenbakia == 1) { irudibatMarraztu(irudiak[0].id); irudibatMarraztu(irudiak[2].id); }
    if (irudizenbakia == 2) { irudibatMarraztu(irudiak[0].id); irudibatMarraztu(irudiak[1].id); }

}
int enkajatu(int irudizenbakia, int x, int y) {
    int a = 1;
    if (ebentu == SAGU_BOTOIA_EZKERRA && irudiak[irudizenbakia].x > x-125 && irudiak[irudizenbakia].x < x+25 && irudiak[irudizenbakia].y>y-100 && irudiak[irudizenbakia].y < y+25) {
        a = 0;
        irudiak[irudizenbakia].x = x-50;
        irudiak[irudizenbakia].y = y-50;
        irudiaMugitu(irudiak[irudizenbakia].id, irudiak[irudizenbakia].x, irudiak[irudizenbakia].y);
        pantailaGarbitu();
        redesmarkoak();
        irudibatMarraztu(irudiak[irudizenbakia].id);
        besteirudiakmantendu(irudizenbakia);
        
        pantailaBerriztu();
    }
    else if (ebentu == SAGU_BOTOIA_EZKERRA) { a = 0; }
    return a;
}
int redespuntuazioa(void) {
    int kont = 0;
    if (irudiak[0].x == 875 && irudiak[0].y == 75) {
        kont++;
    }
    if (irudiak[1].x == 875 && irudiak[1].y == 275) {
        kont++;
    }
    if (irudiak[2].x == 875 && irudiak[2].y == 475) {
        kont++;
    }
    return kont;
}
int fisika(void) {
    int puntuazioa,aldea=0;
    //irudiaKendu(irudiak[0].id);
    pantailaGarbitu();
    
    
    
    irudiak[0].id = irudiaKargatu(".\\img\\aurrea.bmp");
    irudiak[1].id = irudiaKargatu(".\\img\\diagonal1.bmp");
    irudiak[2].id = irudiaKargatu(".\\img\\eskubi.bmp");
    irudiak[3].id = irudiaKargatu(".\\img\\diagonal3.bmp");
    
    irudiak[4].id = irudiaKargatu(".\\img\\atzea.bmp");
    irudiak[5].id = irudiaKargatu(".\\img\\diagonal2.bmp");
    irudiak[6].id = irudiaKargatu(".\\img\\ezker.bmp");
    irudiak[7].id = irudiaKargatu(".\\img\\diagonal4.bmp");
    
    
    

    kotxepos.x = 500;
    kotxepos.y = 300;
    irudiaMugitu(irudiak[0].id, kotxepos.x, kotxepos.y);
    irudibatMarraztu(irudiak[0].id);

    pantailaBerriztu();
    while (pantailak == JOKOA) {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == TECLA_RIGHT)
        {
            aldea++;
            if (aldea == 8)aldea = 0;
        }
        if (ebentu == TECLA_LEFT)
        {
            aldea--;
            if (aldea == -1)aldea = 7;
        }
        if (ebentu == TECLA_UP)
        {
            if (aldea == 0) {
                kotxepos.y = kotxepos.y - 5;

            }
            if (aldea == 1) {
                kotxepos.x = kotxepos.x + 3;
                kotxepos.y = kotxepos.y - 3;
            }
            if (aldea == 2) {
                kotxepos.x = kotxepos.x + 5;

            }
            if (aldea == 3) {
                kotxepos.x = kotxepos.x + 3;
                kotxepos.y = kotxepos.y + 3;
            }
            if (aldea == 4) {
                kotxepos.y = kotxepos.y + 5;

            }
            if (aldea == 5) {
                kotxepos.x = kotxepos.x - 3;
                kotxepos.y = kotxepos.y + 3;

            }
            if (aldea == 6) {
                kotxepos.x = kotxepos.x - 5;

            }
            if (aldea == 7) {
                kotxepos.x = kotxepos.x - 3;
                kotxepos.y = kotxepos.y - 3;

            }
            
        }
        if (ebentu == TECLA_DOWN)
        {
            if (aldea == 0) {
                kotxepos.y = kotxepos.y + 5;

            }
            if (aldea == 1) {
                kotxepos.x = kotxepos.x - 3;
                kotxepos.y = kotxepos.y - 3;
            }
            if (aldea == 2) {
                kotxepos.x = kotxepos.x - 5;

            }
            if (aldea == 3) {
                kotxepos.x = kotxepos.x + 3;
                kotxepos.y = kotxepos.y - 3;
            }
            if (aldea == 4) {
                kotxepos.y = kotxepos.y - 5;

            }
            if (aldea == 5) {
                kotxepos.x = kotxepos.x + 3;
                kotxepos.y = kotxepos.y - 3;

            }
            if (aldea == 6) {
                kotxepos.x = kotxepos.x + 5;

            }
            if (aldea == 7) {
                kotxepos.x = kotxepos.x + 3;
                kotxepos.y = kotxepos.y + 3;

            }
           
        }
        
        kotxeamarraztu(aldea);
        
        if (ebentu == TECLA_ESCAPE) { pantailak = IRTEN; }
        if (ebentu == GERTAERA_IRTEN) { pantailak = IRTEN; }

    }
}
void kotxeamarraztu(int aldea) {
    irudiaMugitu(irudiak[aldea].id, kotxepos.x, kotxepos.y);
    pantailaGarbitu();
    irudibatMarraztu(irudiak[aldea].id);
    pantailaBerriztu();
}

int oinarri(void) {
    int puntuazioa=0,irudizenbakia=0,a=0,kont=0,posberri;
    srand(time(NULL));
    while (irudizenbakia < 3) {
        if(rand()%2){ konsejoa[irudizenbakia].id = irudiaKargatu(".\\img\\acierto.bmp"); }
        else{ konsejoa[irudizenbakia].id = irudiaKargatu(".\\img\\errorea.bmp"); }
        
        irudizenbakia++;
    }
    irudiak[0].x = 500;
    irudiak[0].y = 500;
    irudiakpantailaratu(irudiak[0].x, irudiak[0].y, 0, ".\\img\\persona.bmp");
    
    while (pantailak == JOKOA && kont<30) {
        

        

        while (irudizenbakia < 3) {
            if (konsejoa[irudizenbakia].erortzen == 0) {


                konsejoa[irudizenbakia].x = rand() % 1000;
                if (konsejoa[irudizenbakia].behea != 1) {

                    konsejoa[irudizenbakia].y = -irudizenbakia * 240;
                }
                else {
                    if (rand() % 2==0) { 
                        konsejoa[irudizenbakia].id = irudiaKargatu(".\\img\\acierto.bmp"); 
                        konsejoa[irudizenbakia].aprobatu = 1;
                    }
                    else { 
                        konsejoa[irudizenbakia].id = irudiaKargatu(".\\img\\errorea.bmp"); 
                        konsejoa[irudizenbakia].aprobatu = 0;
                    }
                    konsejoa[irudizenbakia].y = 0;
                }
                konsejoa[irudizenbakia].erortzen = 1;
                kont++;
            }
            if (konsejoa[irudizenbakia].y > 620) {
                konsejoa[irudizenbakia].erortzen = 0;
                konsejoa[irudizenbakia].behea = 1;
            }
            konsejoa[irudizenbakia].y = konsejoa[irudizenbakia].y + 4;
            pantailaGarbitu();
            laukizuzenamarraztu(0, 0, 1080, 720, 0XFF, 0XFF, 0XFF);
            irudiaMugitu(konsejoa[irudizenbakia].id, konsejoa[irudizenbakia].x, konsejoa[irudizenbakia].y);
            konsejoakmarraztu(3);
            ebentu = ebentuaJasoGertatuBada();
            posberri=mugihorizontal(irudiak[0].x);
            irudiak[0].x = posberri;
            if (ebentu == TECLA_ESCAPE) { pantailak = IRTEN; }
            if (ebentu == GERTAERA_IRTEN) { pantailak = IRTEN; }
            if (chocacon(irudiak[0].x,irudiak[0].y,100,200,konsejoa[irudizenbakia].x, konsejoa[irudizenbakia].y,100,100) == 1) {
                konsejoa[irudizenbakia].erortzen = 0;
                konsejoa[irudizenbakia].behea = 1;
                if (konsejoa[irudizenbakia].aprobatu == 1) {
                    puntuazioa++;
                }
                else puntuazioa--;
            }
            
        
            irudiaMugitu(irudiak[0].id, irudiak[0].x, irudiak[0].y);
            irudibatMarraztu(irudiak[0].id);
            pantailaBerriztu();
            
            irudizenbakia++;
            a = 0;
        }
        irudizenbakia = 0;

        
        
    }
    if (puntuazioa < 0)puntuazioa = 0;
    return puntuazioa;
}
void konsejoakmarraztu(int kopurua) {
    int a = 0;
    while (a < kopurua) {
        irudibatMarraztu(konsejoa[a].id);
        a++;
    }
}
POSIZIOA posberri;

PLATAFORMAK plataform[12];

void plataformak(void) {
    int animazio = 1, kont = 0, ezker = 0, eskuin=0, Vy=0,AzeY=3,Vx=0,ebentu2=0,inertzia=0;
    float t=0;
    posberri.x = 0;
    posberri.y = 500;
    
    
    irudiakargaposizioan(posberri.x, posberri.y, 4, ".\\img\\korrika3.bmp");
    irudiakargaposizioan(posberri.x, posberri.y, 1, ".\\img\\geldi.bmp");
    irudiakargaposizioan(posberri.x, posberri.y, 2, ".\\img\\korrika1.bmp");
    irudiakargaposizioan(posberri.x, posberri.y, 3, ".\\img\\korrika2.bmp");
    
   /* irudiakargaposizioan(posberri.x, posberri.y, 5, ".\\img\\geldiezker.bmp");
    irudiakargaposizioan(posberri.x, posberri.y, 6, ".\\img\\korrika1ezker.bmp");
    irudiakargaposizioan(posberri.x, posberri.y, 7, ".\\img\\korrika2ezker.bmp");
    irudiakargaposizioan(posberri.x, posberri.y, 8, ".\\img\\korrika3ezker.bmp");
     irudiaKendu(irudiak[5].id);
    irudiaKendu(irudiak[6].id);
    irudiaKendu(irudiak[7].id);
    irudiaKendu(irudiak[8].id);*/
    irudiakargaposizioan(0, 0, 0, ".\\img\\Plataformak.bmp");
    
    
   
    
    plataformdatuak();
    while (pantailak == JOKOA) {

        

        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == TECLA_RIGHT) {
            Vx=10;
            inertzia = 3;
        }
        if (ebentu == TECLA_LEFT) {
            Vx=-10;
            inertzia = -3;
        }
        
        if (ebentu == TECLA_SPACE ) {

            Vy = -40;
            if (inertzia > 0) {
                Vx = 10;
                inertzia = 3;
            }
            if (inertzia < 0) {
                Vx = 10;
                inertzia = -3;
            }
        }
        
        
        
        
        
        posberri.x = posberri.x + Vx;
        
        Vy = Vy+ AzeY * t;
        posberri.y=posberri.y+ Vy*t;
        t = t + 0.05;
        if (posberri.x != irudiak[animazio].x) { animazio ++; kont = 30;  }
        if (animazio > 4) { 
            animazio = 1; 
        }
       /* if (posberri.x < irudiak[animazio].x) { animazio = 4 + ezker; ezker++; kont = 800; eskuin = 0; }
        if (ezker > 4) {
            ezker = 1;
        }*/
        kont--;
        if (kont < 0)animazio = 1;
        //if (kont < 0 && ezker>0)animazio = 4;
       if (plataformatxokea(posberri.x, posberri.y,40,60) != 1) {
            irudiak[1].x = posberri.x;
            irudiak[1].y = posberri.y;
            irudiak[2].x = posberri.x;
            irudiak[2].y = posberri.y;
            irudiak[3].x = posberri.x;
            irudiak[3].y = posberri.y;
            irudiak[4].x = posberri.x;
            irudiak[4].y = posberri.y;
           /* irudiak[5].x = posberri.x;
            irudiak[5].y = posberri.y;
            irudiak[6].x = posberri.x;
            irudiak[6].y = posberri.y;
            irudiak[7].x = posberri.x;
            irudiak[7].y = posberri.y;
            irudiak[8].x = posberri.x;
            irudiak[8].y = posberri.y;
            */

        }
        else {
            Vy = 20;
            t= 0;
            posberri.x = irudiak[1].x ;
            posberri.y = irudiak[1].y ;
            posberri.x = irudiak[2].x;
            posberri.y = irudiak[2].y;
            posberri.x = irudiak[3].x;
            posberri.y = irudiak[3].y;
            posberri.x = irudiak[4].x;
            posberri.y = irudiak[4].y;
           /* posberri.x = irudiak[5].x;
            posberri.y = irudiak[5].y;
            posberri.x = irudiak[6].x;
            posberri.y = irudiak[6].y;
            posberri.x = irudiak[7].x;
            posberri.y = irudiak[7].y;
            posberri.x = irudiak[8].x;
            posberri.y = irudiak[8].y;*/
        }
        
        irudiaMugitu(irudiak[animazio].id, irudiak[animazio].x, irudiak[animazio].y);
       
        pantailaGarbitu();
        
        irudibatMarraztu(irudiak[0].id);
        irudibatMarraztu(irudiak[animazio].id);
        pantailaBerriztu();
        
        if (ebentu == TECLA_ESCAPE) { pantailak = IRTEN; }
        if (ebentu == GERTAERA_IRTEN) { pantailak = IRTEN; }
        
        if(inertzia<0)inertzia++;
        if (inertzia > 0)inertzia--;
        if (inertzia == 0)Vx = 0;
        
        SDL_Delay(30);
    }
}

void plataformdatuak(void) {
    plataform[0].x = 165;
    plataform[0].y = 490;
    plataform[0].width = 130;
    plataform[0].height = 30;
    plataform[1].x = 36;
    plataform[1].y =384;
    plataform[1].width = 130;
    plataform[1].height = 30;
    plataform[2].x = 150;
    plataform[2].y = 265;
    plataform[2].width = 130;
    plataform[2].height = 30;
    plataform[3].x = 330;
    plataform[3].y = 265;
    plataform[3].width = 250;
    plataform[3].height = 400;
    plataform[4].x = 255;
    plataform[4].y = 210;
    plataform[4].width = 385;
    plataform[4].height = 58;
    plataform[5].x = 0;
    plataform[5].y = 591;
    plataform[5].width = 330;
    plataform[5].height = 129;
    plataform[6].x = 326;
    plataform[6].y = 165;
    plataform[6].width = 40;
    plataform[6].height = 40;
    plataform[7].x = 365;
    plataform[7].y = 140;
    plataform[7].width = 133;
    plataform[7].height = 64;
    plataform[8].x = 446;
    plataform[8].y = 88;
    plataform[8].width = 54;
    plataform[8].height = 54;
    plataform[9].x = 725;
    plataform[9].y = 245;
    plataform[9].width = 130;
    plataform[9].height = 30;
    plataform[10].x = 630;
    plataform[10].y = 400;
    plataform[10].width = 130;
    plataform[10].height = 30;
    plataform[11].x = 775;
    plataform[11].y = 578;
    plataform[11].width = 305;
    plataform[11].height = 242;
    
}
int plataformatxokea(int x,int y,int widht,int height) {
    int a = 0, ukitzendu=0;
    while (a<=11 && ukitzendu==0) {
        if (chocacon(x, y, widht, height, plataform[a].x, plataform[a].y, plataform[a].width, plataform[a].height) == 1)ukitzendu = 1;
        a++;
    }
    return ukitzendu;
}
int mugihorizontal(int x) {
    int posberri;
    posberri = x;
    if (ebentu == TECLA_RIGHT) {
        posberri=posberri + 10;
    }
    if (ebentu == TECLA_LEFT) {
        posberri = posberri - 10;
    }
    return posberri;
}
int mugibertikal(int y) {
    int posberri;
    posberri = y;
    if (ebentu == TECLA_UP) {
        posberri = posberri - 10;
    }
    if (ebentu == TECLA_DOWN) {
        posberri = posberri + 10;
    }
    return posberri;
}
int chocacon(int x1, int y1, int widht1, int height1, int x2, int y2, int widht2, int height2) {
    int ukitzendu = 0;
    if ((x1<x2 + widht2 && x1 + widht1 > x2) && (y1<y2 + height2 && y1 + height1 > y2)) { ukitzendu = 1; }
    return ukitzendu;
}
void iratzarri(void) {
    
    int x = -150, y = 175;
    int  espazio = 0, bai = 0, kont = -1,  lehena = 0, aldia = 0, geio = 0, bigarrena = 0, errepikatu = 1, irudia = 0;
    char  kronometroa[128];
    int segunduak = 0;

    irudiakargaposizioan(0, 0, 1, ".\\img\\fondoa1.bmp");
    irudiakargaposizioan(0, 0, 1, ".\\img\\fondoa1.bmp");
    irudiakargaposizioan(0, 0, 2, ".\\img\\fondoa2.bmp");
    irudiakargaposizioan(0, 0, 3, ".\\img\\fondoa3.bmp");
    irudiakargaposizioan(0, 0, 4, ".\\img\\fondoa4.bmp");
    irudiakargaposizioan(0, 0, 5, ".\\img\\fondoa5.bmp");
    irudiakargaposizioan(x, y, 0, ".\\img\\arm2.bmp");
    

    


    while (irudia<5 && errepikatu==1)
    {
        errepikatu = 0;
        while (aldia < 35)
        {

            irudiaMugitu(irudiak[0].id, x, y);
            ebentu = ebentuaJasoGertatuBada2();
            if (ebentu == TECLA_SPACE)
            {
                y = y + 2;
                aldia++;
            }

            bigarrena--;

            kronometroa[0] = '1' + geio;
            kronometroa[1] = '0' + segunduak;
            kronometroa[2] = ':';
            kronometroa[3] = '9' + lehena;
            kronometroa[4] = '9' + bigarrena;
            kronometroa[5] = '\0';

            if (bigarrena == -9 && lehena != -9)
            {
                lehena--;
                bigarrena = 0;
            }
            if (lehena == -9 && bigarrena == -9)
            {
                lehena = 0;
                bigarrena = 0;
                segunduak--;
            }
            if (segunduak == 0 && geio == 0)
            {
                geio--;
                segunduak = 9;
            }
            if (segunduak == -1 && geio == -1)
            {
                aldia = 35;
                errepikatu++;
                
            }

            SDL_Delay(10);
            pantailaGarbitu();
            irudibatMarraztu(irudiak[1 + irudia].id);
            irudibatMarraztu(irudiak[0].id);
            
            textuaIdatzi(700, 200, kronometroa);
            pantailaBerriztu();



        }
        
        
        if (errepikatu == 1)
        {
            aldia = 0;
            lehena = 0;
            geio = 0;
            bigarrena = 0;
            segunduak = 0;
            x = -150;
            y = 175;
            irudia++;
            
            
        }
        
    }
    

}
void irudiakargaposizioan(int x, int y, int irudizenbakia, char* irudiizena) {
    irudiak[irudizenbakia].id = irudiaKargatu(irudiizena);
    irudiak[irudizenbakia].x = x;
    irudiak[irudizenbakia].y = y;
    irudiaMugitu(irudiak[irudizenbakia].id, irudiak[irudizenbakia].x, irudiak[irudizenbakia].y);
    
}
int erreseteatu() {

}
int matematika(void) {
    int x = 0, y = 500, aldatu = 2, mantendu = 0,  gora = 0,  azelerazio=0,rebote=0, geldidenbora=0,buelta=0,geldi=0,puntuazioa=0;
    int lehena = 0, aldia = 0, geio = 0, bigarrena = 0, segunduak = 9, errepikatu = 0, geio2 = 0;
    char kronometroa[128];

    pantailaGarbitu();
   
    irudiak[0].id = irudiaKargatu(".\\img\\fondo.bmp");
    irudiak[1].id = irudiaKargatu(".\\img\\irudi.bmp");
    irudiak[2].id = irudiaKargatu(".\\img\\irakaslea.bmp");
    irudiak[3].id = irudiaKargatu(".\\img\\irakaslea2.bmp");
   
    irudiaMugitu(irudiak[0].id, 0, 0);
    irudiaMugitu(irudiak[1].id, 230, 500);
    irudiaMugitu(irudiak[2].id, x, y);
    irudiaMugitu(irudiak[3].id, x, y);
    irudibatMarraztu(irudiak[0].id);
    irudibatMarraztu(irudiak[1].id);
    irudibatMarraztu(irudiak[2].id);
    
    
    pantailaBerriztu();
    
    srand(time(NULL));
    while (mantendu == 0)
    {


        
        

             
            ebentu = ebentuaJasoGertatuBada();
            if (ebentu == TECLA_UP)
            {
                pantailaGarbitu();

                
                
                irudibatMarraztu(irudiak[1].id);
                irudibatMarraztu(irudiak[0].id);
                irudibatMarraztu(irudiak[aldatu].id);
                pantailaBerriztu();
               
                
                gora = 1;


            }
            if (ebentu == TECLA_DOWN && gora==1)
            {

                pantailaGarbitu();
                irudibatMarraztu(irudiak[0].id);
                irudibatMarraztu(irudiak[aldatu].id);
                pantailaBerriztu();
                
                
                gora = 0;
            }

            if(aldatu==2 && geldi==0)x = x + (2+azelerazio);
            if (aldatu == 3 && geldi==0)x = x - (2+azelerazio);
            bigarrena = bigarrena--;

            kronometroa[0] = '2' + geio2;
            kronometroa[1] = '0' + segunduak;
            kronometroa[2] = ':';
            kronometroa[3] = '9' + lehena;
            kronometroa[4] = '9' + bigarrena;
            kronometroa[5] = '\0';

            if (bigarrena == -9 && lehena != -9)
            {
                lehena--;
                bigarrena = 0;
            }
            if (lehena == -9 && bigarrena == -9)
            {
                lehena = 0;
                bigarrena = 0;
                segunduak--;
                geio = 0;
            }
            if (segunduak == -1 && geio == 0 && geio2 != -2)
            {
                geio2--;
                segunduak = 9;

            }
            if (segunduak == -1 && geio2 == -2)
            {
                aldia = 35;
                errepikatu--;
                aldatu = 2;
                mantendu = 1;
            }

            if (gora == 1 && x > 0 && x < 230 && aldatu==2)
            {
                
                mantendu = 1;
            }
            if (gora == 1 && x > 230 && x < 929 && aldatu == 3)
            {

                mantendu = 1;
            }
            if (x >= 929 || rand() % 451==0 || x < 0)geldi = 1;
            if (geldi == 1)geldidenbora++;
            
            if (geldidenbora>50)
            {

                if (aldatu == 2)aldatu = 3;
                else aldatu = 2;
                pantailaGarbitu();

                irudibatMarraztu(irudiak[0].id);
                if(gora==1)irudibatMarraztu(irudiak[1].id);
                irudibatMarraztu(irudiak[aldatu].id);
                rebote++;
                if (rebote == 5) {
                    azelerazio++;
                    rebote = 0;
                }
                pantailaBerriztu();
                geldidenbora = 0;
                geldi = 0;

            }
            
            else
            {
                irudiaMugitu(irudiak[aldatu].id, x, y);
                pantailaGarbitu();
                irudibatMarraztu(irudiak[0].id);
                if (gora == 1) {
                    irudibatMarraztu(irudiak[1].id);
                    puntuazioa++;
                }
                irudibatMarraztu(irudiak[aldatu].id);
                textuaIdatzi(700, 200, kronometroa);
                pantailaBerriztu();
                SDL_Delay(10);
                if (puntuazioa == 1000) {
                    pantailaGarbitu();
                }

            }
        
        
        

        


    }
    
    
    return puntuazioa / 200;

}
