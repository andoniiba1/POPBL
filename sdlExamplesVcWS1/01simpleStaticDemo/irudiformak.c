#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"

#include "irudiformak.h"

void irudiakargaposizioan(int x, int y, int irudizenbakia, char* irudiizena) {
	imagenak[irudizenbakia].id = irudiaKargatu(irudiizena);
	imagenak[irudizenbakia].x = x;
	imagenak[irudizenbakia].y = y;
	irudiaMugitu(imagenak[irudizenbakia].id, imagenak[irudizenbakia].x, imagenak[irudizenbakia].y);

}
void markoamarraztu(int xhasiera, int yhasiera, int xbukaera, int ybukaera, int lodiera, int gorri, int berde, int urdin) {

	int a;
	arkatzKoloreaEzarri(gorri, berde, urdin);
	for (a = yhasiera; a <= yhasiera + lodiera; a++) {
		zuzenaMarraztu(xhasiera, a, xbukaera, a);
	}
	for (a = xhasiera; a <= xhasiera + lodiera; a++) {
		zuzenaMarraztu(a, yhasiera, a, ybukaera);
	}
	for (a = ybukaera - lodiera; a <= ybukaera; a++) {
		zuzenaMarraztu(xhasiera, a, xbukaera, a);
	}
	for (a = xbukaera - lodiera; a <= xbukaera; a++) {
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

void irudiakpantailaratu(int x, int y, int irudizenbakia, char* irudiizena) {
	irudiakargaposizioan(x, y, irudizenbakia, irudiizena);
	irudibatMarraztu(imagenak[irudizenbakia].id);
}