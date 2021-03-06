#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"
#include <time.h>
#include<stdlib.h>

#include "matematika.h"
int matematika(void) {
	int x = 0, y = 525, aldatu = 2, mantendu = 0, gora = 0, azelerazio = 0, rebote = 0, geldidenbora = 0, geldi = 0, puntuazioa = 0, egon=0;
	int lehena = 0, geio = 0, bigarrena = 0, segunduak = 9, geio2 = 0;
	char kronometroa[128];

	pantailaGarbitu();


	irudiakpantailaratu(0, 0, 0, ".\\img\\mate.bmp");
	irudiakpantailaratu(315, 450, 1, ".\\img\\pelotita.bmp");
	irudiakpantailaratu(x, y, 2, ".\\img\\irakaslea.bmp");
	irudiakargaposizioan(x, y, 3, ".\\img\\irakaslea2.bmp");

	pantailaBerriztu();

	srand((int)time(NULL));
	while (mantendu == 0 && pantailak == JOKOA)
	{
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == TECLA_UP)
		{
			gora = 1;
		}
		if (ebentu == TECLA_DOWN)
		{
			gora = 0;
		}
		itxi();

		maisumugimendua(aldatu,geldi,&x,azelerazio);

		mantendu = harrapatu(x, gora, aldatu, &puntuazioa);

		kronometroa[0] = '2' + geio2;
		kronometroa[1] = '0' + segunduak;
		kronometroa[2] = ':';
		kronometroa[3] = '9' + lehena;
		kronometroa[4] = '9' + bigarrena;
		kronometroa[5] = '\0';

		krono20(&bigarrena, &lehena, &segunduak, &geio2, &geio, &mantendu);



		if ((x >= 929 || rand() % 451 == 0 || x < 0) && egon == 0) {
			geldi = 1;
			soinua(".\\sound\\mmm.wav", 3); 
			egon = 1;
		}
		if (geldi == 1)geldidenbora++;

		if (geldidenbora > 50)
		{

			buelta(&aldatu,&puntuazioa,gora,kronometroa,&rebote,&azelerazio,&geldidenbora,&geldi,&egon);
		}

		else
		{
			segi(aldatu,x,y,gora,kronometroa,&puntuazioa);

		}
		
	}
	soinua(".\\sound\\arrapatuta.wav", 8);
	SDL_Delay(2000);
	puntuazioa=matepuntuazioa(puntuazioa);
	return puntuazioa;
}
int harrapatu(int x, int gora, int aldatu, int *puntuazioa) {
	int ikusi = 0;
	if (gora == 1 && x > 0 && x < 310 && aldatu == 2)
	{

		ikusi = 1;
	}
	if (gora == 1 && x > 310 && x < 929 && aldatu == 3)
	{

		ikusi = 1;
	}
	if (ikusi == 1)*puntuazioa = 0;
	return ikusi;
}
int mateaktualizatu(int gora, int puntuazioa, int aldatu, char* kronometroa) {
	pantailaGarbitu();

	irudibatMarraztu(imagenak[0].id);
	if (gora == 1) {
		irudibatMarraztu(imagenak[1].id);
		puntuazioa++;
	}
	irudibatMarraztu(imagenak[aldatu].id);
	textuaIdatzi(700, 200, kronometroa, 0,0,0);

	pantailaBerriztu();
	return puntuazioa;
}
void krono20(int* bigarrena, int* lehena, int* segunduak, int* geio2, int* geio, int* mantendu) {
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
		*geio = 0;
	}
	if (*segunduak == -1 && *geio == 0 && *geio2 != -2)
	{
		(*geio2)--;
		*segunduak = 9;

	}
	if (*segunduak == -1 && *geio2 == -2)
	{

		*mantendu = 1;
	}

}
int matepuntuazioa(int puntuazioa) {
	if (puntuazioa == 1)puntuazioa = 0;
	if (puntuazioa != 0) {
		if (puntuazioa <= 200)puntuazioa = 1;
		else {
			if (puntuazioa > 200 && puntuazioa <= 400)puntuazioa = 2;
			else puntuazioa = 3;
		}
	}
	return puntuazioa;
}
void maisumugimendua(int aldatu,int geldi,int *x,int azelerazio) {
	if (aldatu == 2 && geldi == 0)*x = *x + (2 + azelerazio);

	if (aldatu == 3 && geldi == 0)*x = *x - (2 + azelerazio);
}
void buelta(int *aldatu, int *puntuazioa,int gora,char* kronometroa,int *rebote,int *azelerazio,int *geldidenbora,int *geldi,int *egon) {
	if (*aldatu == 2)*aldatu = 3;
	else *aldatu = 2;

	*puntuazioa = mateaktualizatu(gora, *puntuazioa, *aldatu, kronometroa);
	(*rebote)++;
	if (*rebote == 5) {
		(*azelerazio)++;
		*rebote = 0;
	}
	*geldidenbora = 0;
	*geldi = 0;
	*egon = 0;
}
void segi(int aldatu,int x,int y,int gora,char* kronometroa,int *puntuazioa) {
	irudiaMugitu(imagenak[aldatu].id, x, y);
	*puntuazioa = mateaktualizatu(gora, *puntuazioa, aldatu, kronometroa);
	SDL_Delay(10);

}