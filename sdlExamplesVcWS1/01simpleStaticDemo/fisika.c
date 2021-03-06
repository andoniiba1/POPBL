#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"

#include "fisika.h"
int fisika(void) {
	int puntuazioa=0, aldea = 0, fondoa=8, amaitu=0,txoke=0, soinudenbora=0;

	pantailaGarbitu();
	fisikakargatu();


	kotxepos.x = 80;
	kotxepos.y = 650;
	irudiaMugitu(imagenak[0].id, kotxepos.x, kotxepos.y);
	irudibatMarraztu(imagenak[0].id);

	pantailaBerriztu();
	bazterradatuak1();
	while (pantailak == JOKOA && amaitu==0) {
		puntuazioa++;
		soinudenbora--;
		aldea=direkzioaaldatu(aldea);
		kotzeamugitu(aldea, &soinudenbora);
		itxi();
		fondoaaldatu(&fondoa,&amaitu);
		kotxezentroaajustatu(aldea);
		
		errepidetikatera(&amaitu, &txoke,fondoa);
		kotxeamarraztu(aldea,fondoa);
	}
	puntuazioa = fisikapuntuazioa(txoke, puntuazioa);
	return puntuazioa;
	
}
void kotxeamarraztu(int aldea,int fondoa) {
	irudiaMugitu(imagenak[aldea].id, kotxepos.x-zentroa.x, kotxepos.y-zentroa.y);
	irudiaMugitu(imagenak[fondoa].id, 0, 0);
	pantailaGarbitu();
	irudibatMarraztu(imagenak[fondoa].id);
	irudibatMarraztu(imagenak[aldea].id);
	pantailaBerriztu();
}
int bazterratxokea(int x, int y, int widht, int height, int fondoa) {
	int a = 0, ukitzendu = 0;
	while (a <= fondoa-5 && ukitzendu == 0) {
		if (chocacon(x, y, widht, height, bidea[a].x, bidea[a].y, bidea[a].width, bidea[a].height) == 1)ukitzendu = 1;
		a++;
	}
	return ukitzendu;
}
void bazterradatuak1() {

	bidea[0].x = 123;
	bidea[0].y = 469;
	bidea[0].width = 60;
	bidea[0].height = 253;
	bidea[1].x = 143;
	bidea[1].y = 469;
	bidea[1].width = 957;
	bidea[1].height = 85;
	bidea[2].x = 940;
	bidea[2].y = 93;
	bidea[2].width = 99;
	bidea[2].height = 457;
	bidea[3].x = 0;
	bidea[3].y = 93;
	bidea[3].width = 1000;
	bidea[3].height = 100;
}
void bazterradatuak2(void) {
	bidea[0].x = 700;
	bidea[0].y = 80;
	bidea[0].width = 545;
	bidea[0].height = 120;
	bidea[1].x = 720;
	bidea[1].y = 45;
	bidea[1].width = 80;
	bidea[1].height = 345;
	bidea[2].x = 75;
	bidea[2].y = 380;
	bidea[2].width = 730;
	bidea[2].height = 100;
	bidea[3].x = 85;
	bidea[3].y = 380;
	bidea[3].width = 90;
	bidea[3].height = 338;
	bidea[4].x = 85;
	bidea[4].y = 610;
	bidea[4].width = 824;
	bidea[4].height = 135;
}
void bazterradatuak3(void) {
	bidea[0].x = 710;
	bidea[0].y = 0;
	bidea[0].width = 90;
	bidea[0].height = 280;
	bidea[1].x = 80;
	bidea[1].y = 200;
	bidea[1].width = 734;
	bidea[1].height = 100;
	bidea[2].x = 130;
	bidea[2].y = 200;
	bidea[2].width = 108;
	bidea[2].height = 431;
	bidea[3].x = 77;
	bidea[3].y = 530;
	bidea[3].width = 975;
	bidea[3].height = 132;
	bidea[4].x = 930;
	bidea[4].y = 165;
	bidea[4].width = 100;
	bidea[4].height = 475;
	bidea[5].x = 930;
	bidea[5].y = 165;
	bidea[5].width = 191;
	bidea[5].height = 95;
}
void fisikakargatu(void) {
	imagenak[0].id = irudiaKargatu(".\\img\\aurrea.bmp");
	imagenak[1].id = irudiaKargatu(".\\img\\diagonal1.bmp");
	imagenak[2].id = irudiaKargatu(".\\img\\eskubi.bmp");
	imagenak[3].id = irudiaKargatu(".\\img\\diagonal3.bmp");
	imagenak[4].id = irudiaKargatu(".\\img\\atzea.bmp");
	imagenak[5].id = irudiaKargatu(".\\img\\diagonal2.bmp");
	imagenak[6].id = irudiaKargatu(".\\img\\ezker.bmp");
	imagenak[7].id = irudiaKargatu(".\\img\\diagonal4.bmp");
	imagenak[8].id = irudiaKargatu(".\\img\\fisika1.bmp");
	imagenak[9].id = irudiaKargatu(".\\img\\fisika2.bmp");
	imagenak[10].id = irudiaKargatu(".\\img\\fisika3.bmp");

}
int direkzioaaldatu(int aldea) {
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
	return aldea;
}
void kotzeamugitu(int aldea, int *soinudenbora) {
	if (ebentu == TECLA_UP)
	{
		switch (aldea)
		{
		case 0:
			kotxepos.y = kotxepos.y - 10;
			break;
		case 1:
			kotxepos.x = kotxepos.x + 6;
			kotxepos.y = kotxepos.y - 6;
			break;
		case 2:
			kotxepos.x = kotxepos.x + 10;
			break;
		case 3:
			kotxepos.x = kotxepos.x + 6;
			kotxepos.y = kotxepos.y + 6;
			break;
		case 4:
			kotxepos.y = kotxepos.y + 10;
			break;
		case 5:
			kotxepos.x = kotxepos.x - 6;
			kotxepos.y = kotxepos.y + 6;
			break;
		case 6:
			kotxepos.x = kotxepos.x - 10;
			break;
		case 7:
			kotxepos.x = kotxepos.x - 6;
			kotxepos.y = kotxepos.y - 6;
			break;
		default:
			break;
		}
		if (*soinudenbora < 0) {
			soinua(".\\sound\\kotxea.wav", 9);
			*soinudenbora = 500;
		}
	}
	if (ebentu == TECLA_DOWN)
	{
		switch (aldea)
		{
		case 0:
			kotxepos.y = kotxepos.y + 10;
			break;
		case 1:
			kotxepos.x = kotxepos.x - 6;
			kotxepos.y = kotxepos.y + 6;
			break;
		case 2:
			kotxepos.x = kotxepos.x - 10;
			break;
		case 3:
			kotxepos.x = kotxepos.x - 6;
			kotxepos.y = kotxepos.y - 6;
			break;
		case 4:
			kotxepos.y = kotxepos.y - 10;
			break;
		case 5:
			kotxepos.x = kotxepos.x + 6;
			kotxepos.y = kotxepos.y - 6;
			break;
		case 6:
			kotxepos.x = kotxepos.x + 10;
			break;
		case 7:
			kotxepos.x = kotxepos.x + 6;
			kotxepos.y = kotxepos.y + 6;
			break;
		default:
			break;
		}
		if (*soinudenbora < 0) {
			soinua(".\\sound\\kotxea.wav", 9);
			*soinudenbora = 500;
		}
	}
}
void kotxezentroaajustatu(int aldea) {
	if (aldea == 1 || aldea == 3 || aldea == 5 || aldea == 7) {
		zentroa.x = 50;
		zentroa.y = 50;
	}
	if (aldea == 0 || aldea == 4) {
		zentroa.x = 20;
		zentroa.y = 60;
	}
	if (aldea == 2 || aldea == 6) {
		zentroa.x = 60;
		zentroa.y = 20;
	}
}
void fondoaaldatu(int *fondoa, int *amaitu) {
	if (chocacon(kotxepos.x, kotxepos.y, 50, 50, -10, 80, 10, 90) == 1 && *fondoa == 8) {
		(*fondoa)++;
		kotxepos.x = 1030;
		kotxepos.y = 80;
		bazterradatuak2();
	}
	if (chocacon(kotxepos.x, kotxepos.y, 50, 50, 690, 720, 150, 10) == 1 && *fondoa == 9) {
		(*fondoa)++;
		kotxepos.x = 720;
		kotxepos.y = 30;
		bazterradatuak3();
	}
	if (chocacon(kotxepos.x, kotxepos.y, 50, 50, 1080, 140, 10, 75) == 1 && *fondoa == 10) {
		*amaitu = 1;

	}
}
int fisikapuntuazioa(int txoke, int puntuazioa) {
	if (puntuazioa <= 40000)puntuazioa = 3;
	else {
		if (puntuazioa > 40000 && puntuazioa <= 53000)puntuazioa = 2;
		else puntuazioa = 1;
	}
	if (txoke == 1)puntuazioa = 0;
	return puntuazioa;
}
void errepidetikatera(int *amaitu,int *txoke,int fondoa) {
	if (bazterratxokea(kotxepos.x + zentroa.x, kotxepos.y + zentroa.y, 50, 50, fondoa) != 1) {
		*txoke = 1;
		*amaitu = 1;
	}
}