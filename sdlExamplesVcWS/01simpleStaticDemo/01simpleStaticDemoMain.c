#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>


typedef struct S_GURE_GAUZAK
{
    
    int idIrudi;
}GURE_GAUZAK;


GURE_GAUZAK gureGauzak;


int menua(void);
int kredituak(void);

int main(int argc, char * str[]) 
{
  int ebentu = 0, menutikirten=0, kreditutikirten = 0;
  POSIZIOA pos;

  menua();
  while(!menutikirten)
  {
    ebentu = ebentuaJasoGertatuBada();
    if (ebentu == SAGU_BOTOIA_EZKERRA)
    {
        pos = saguarenPosizioa();
        if ((pos.x > 0) && (pos.x <  40) && (pos.y > 0) && (pos.y <  38)) menutikirten = 2;
    }
    if (ebentu == TECLA_ESCAPE) menutikirten = 1;
    
  }
  if (menutikirten == 1) {
      sgItxi();
      return 0;
  }
  if (menutikirten == 2) {
      kredituak();
      
      while (!kreditutikirten)
      {
          ebentu = ebentuaJasoGertatuBada();
          if (ebentu == SAGU_BOTOIA_EZKERRA)
          {
              pos = saguarenPosizioa();
              if ((pos.x > 0) && (pos.x < 40) && (pos.y > 0) && (pos.y < 38)) kreditutikirten = 1;
          }
          if (ebentu == TECLA_ESCAPE) kreditutikirten = 1;

      }
      if (kreditutikirten == 1) {
          sgItxi();
          return 0;
      }
  }
}


int menua(void)
{
    int a;
    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }
  
    

  pantailaGarbitu();
  gureGauzak.idIrudi = irudiaKargatu(".\\img\\git1.bmp");
  irudiaMugitu(gureGauzak.idIrudi, 0 , 0);
  irudiakMarraztu(0);

  pantailaBerriztu();
  


  return 0;
}
int kredituak(void)
{



    pantailaGarbitu();
    gureGauzak.idIrudi = irudiaKargatu(".\\img\\hexagono.bmp");
    irudiaMugitu(gureGauzak.idIrudi, 100, 100);
    irudiakMarraztu(1);

    pantailaBerriztu();



    return 0;
}


