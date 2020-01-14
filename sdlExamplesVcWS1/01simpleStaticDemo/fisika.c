#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"

#include "fisika.h"
int fisika(void) {
	int puntuazioa, aldea = 0, fondoa=8, amaitu=0;

	pantailaGarbitu();
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



	kotxepos.x = 80;
	kotxepos.y = 650;
	irudiaMugitu(imagenak[0].id, kotxepos.x, kotxepos.y);
	irudibatMarraztu(imagenak[0].id);

	pantailaBerriztu();
	bazterradatuak1();
	while (pantailak == JOKOA && amaitu==0) {
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
			switch (aldea)
			{
			case 0:
				kotxepos.y = kotxepos.y - 5;
				break;
			case 1:
				kotxepos.x = kotxepos.x + 3;
				kotxepos.y = kotxepos.y - 3;
				break;
			case 2:
				kotxepos.x = kotxepos.x + 5;
				break;
			case 3:
				kotxepos.x = kotxepos.x + 3;
				kotxepos.y = kotxepos.y + 3;
				break;
			case 4:
				kotxepos.y = kotxepos.y + 5;
				break;
			case 5:
				kotxepos.x = kotxepos.x - 3;
				kotxepos.y = kotxepos.y + 3;
				break;
			case 6:
				kotxepos.x = kotxepos.x - 5;
				break;
			case 7:
				kotxepos.x = kotxepos.x - 3;
				kotxepos.y = kotxepos.y - 3;
				break;
			default:
				break;
			}
		}
		if (ebentu == TECLA_DOWN)
		{
			switch (aldea)
			{
			case 0:
				kotxepos.y = kotxepos.y + 5;
				break;
			case 1:
				kotxepos.x = kotxepos.x - 3;
				kotxepos.y = kotxepos.y + 3;
				break;
			case 2:
				kotxepos.x = kotxepos.x - 5;
				break;
			case 3:
				kotxepos.x = kotxepos.x - 3;
				kotxepos.y = kotxepos.y - 3;
				break;
			case 4:
				kotxepos.y = kotxepos.y - 5;
				break;
			case 5:
				kotxepos.x = kotxepos.x + 3;
				kotxepos.y = kotxepos.y - 3;
				break;
			case 6:
				kotxepos.x = kotxepos.x + 5;
				break;
			case 7:
				kotxepos.x = kotxepos.x + 3;
				kotxepos.y = kotxepos.y + 3;
				break;
			default:
				break;
			}
		}
		itxi();
		if (chocacon(kotxepos.x,kotxepos.y,50,50,-10,80,10,90)==1 && fondoa==8) {
			fondoa++;
			kotxepos.x = 1030;
			kotxepos.y = 80;
			bazterradatuak2();
		}
		if (chocacon(kotxepos.x, kotxepos.y, 50, 50, 690, 720, 150, 10) == 1 && fondoa == 9) {
			fondoa++;
			kotxepos.x = 720;
			kotxepos.y = 30;
			bazterradatuak3();
		}
		if (chocacon(kotxepos.x, kotxepos.y, 50, 50, 1080, 140, 10, 75) == 1 && fondoa == 10) {
			amaitu=1;
			
		}
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
		
		if (bazterratxokea(kotxepos.x+zentroa.x, kotxepos.y+zentroa.y, 50, 50,fondoa) != 1) {
			amaitu = 1;
		}
		kotxeamarraztu(aldea,fondoa);
	}
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

	bidea[0].x = 43;
	bidea[0].y = 419;
	bidea[0].width = 143;
	bidea[0].height = 303;
	bidea[1].x = 43;
	bidea[1].y = 419;
	bidea[1].width = 1007;
	bidea[1].height = 135;
	bidea[2].x = 890;
	bidea[2].y = 43;
	bidea[2].width = 169;
	bidea[2].height = 507;
	bidea[3].x = 0;
	bidea[3].y = 43;
	bidea[3].width = 1055;
	bidea[3].height = 150;
}
void bazterradatuak2(void) {
	bidea[0].x = 655;
	bidea[0].y = 45;
	bidea[0].width = 445;
	bidea[0].height = 125;
	bidea[1].x = 655;
	bidea[1].y = 45;
	bidea[1].width = 165;
	bidea[1].height = 425;
	bidea[2].x = 20;
	bidea[2].y = 325;
	bidea[2].width = 790;
	bidea[2].height = 150;
	bidea[3].x = 20;
	bidea[3].y = 325;
	bidea[3].width = 158;
	bidea[3].height = 393;
	bidea[4].x = 20;
	bidea[4].y = 587;
	bidea[4].width = 854;
	bidea[4].height = 135;
}
void bazterradatuak3(void) {
	bidea[0].x = 692;
	bidea[0].y = -50;
	bidea[0].width = 122;
	bidea[0].height = 294;
	bidea[1].x = 80;
	bidea[1].y = 165;
	bidea[1].width = 734;
	bidea[1].height = 131;
	bidea[2].x = 80;
	bidea[2].y = 165;
	bidea[2].width = 168;
	bidea[2].height = 466;
	bidea[3].x = 77;
	bidea[3].y = 496;
	bidea[3].width = 975;
	bidea[3].height = 132;
	bidea[4].x = 891;
	bidea[4].y = 115;
	bidea[4].width = 161;
	bidea[4].height = 513;
	bidea[5].x = 891;
	bidea[5].y = 115;
	bidea[5].width = 191;
	bidea[5].height = 135;
}