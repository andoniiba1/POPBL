#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"

#include "iratzarri.h"

int iratzarri(void) {

	int x = -150, y = 175;
	int lehena = 0, aldia = 0, geio = 0, bigarrena = 0, errepikatu = 1, irudia = 0;
	char  kronometroa[128];
	int segunduak = 0;


	
	irudiakargaposizioan(0, 0, 1, ".\\img\\fondoa1.bmp");
	irudiakargaposizioan(0, 0, 2, ".\\img\\fondoa2.bmp");
	irudiakargaposizioan(0, 0, 3, ".\\img\\fondoa3.bmp");
	irudiakargaposizioan(x, y, 0, ".\\img\\arm2.bmp");

	while (irudia < 3 && errepikatu == 1 && pantailak == JOKOA)
	{
		soinuakkargatu();
		musikahasi(".\\sound\\alarma.wav");
		soinua(".\\sound\\bostezo.wav", 2);
		errepikatu = 0;
		while (aldia < 35 && errepikatu==0 && pantailak == JOKOA)
		{

			irudiaMugitu(imagenak[0].id, x, y);
			ebentu = ebentuaJasoGertatuBada2();
			if (ebentu == TECLA_SPACE)
			{
				y = y + 2;
				aldia++;
			}
			itxi();

			krono10(&lehena, &bigarrena, &geio, &segunduak, &aldia, &errepikatu);

			kronometroa[0] = '1' + geio;
			kronometroa[1] = '0' + segunduak;
			kronometroa[2] = ':';
			kronometroa[3] = '9' + lehena;
			kronometroa[4] = '9' + bigarrena;
			kronometroa[5] = '\0';



			SDL_Delay(10);
			pantailaGarbitu();

			irudibatMarraztu(imagenak[1 + irudia].id);
			irudibatMarraztu(imagenak[0].id);
			textuaIdatzi(700, 200, kronometroa, 0X00, 0X00, 0X00);

			pantailaBerriztu();



		}


		if (errepikatu == 1)
		{
			erreseteatu(&aldia, &lehena, &geio, &bigarrena, &segunduak, &x, &y);
			etzaraesnatu();
			irudia++;
		}
	}
	
	if (irudia != 4)audioTerminate();
	soinuakkargatu();
 	return 3-irudia;
}

void erreseteatu(int* aldia, int* lehena, int* geio, int* bigarrena, int* segunduak, int* x, int* y) {
	*aldia = 0;
	*lehena = 0;
	*geio = 0;
	*bigarrena = 0;
	*segunduak = 0;
	*x = -150;
	*y = 175;
}
void krono10(int* lehena, int* bigarrena, int* geio, int* segunduak, int* aldia, int* errepikatu) {

	(*bigarrena)--;

	if (*bigarrena == -9 && *lehena != -9)
	{
		(*lehena)--;
		*bigarrena = 0;
	}
	if (*lehena == -9 && *bigarrena == -9)
	{
		*lehena = 0;
		*bigarrena = 0;
		(*segunduak)--;
	}
	if (*segunduak == 0 && *geio == 0)
	{
		(*geio)--;
		*segunduak = 9;
	}
	if (*segunduak == -1 && *geio == -1)
	{
		
		(*errepikatu)++;
		

	}
}
void etzaraesnatu(void)
{
	audioTerminate();
	
	pantailaGarbitu();
	irudiakpantailaratu(0, 0, 4, ".\\img\\EGIL.bmp");
	letratamaina(50);
	textuaIdatzi(340, 300, "EZ ZARA ESNATU", 0X00, 0X00, 0X00);
	letratamaina(30);
	pantailaBerriztu();
	ezkerbotoibukle();
	
	
}