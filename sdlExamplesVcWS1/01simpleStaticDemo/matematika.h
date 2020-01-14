#ifndef MATEMATIKA_H
#define MATEMATIKA_H
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"
#include "testua.h"
#include "irudiformak.h"
#include "musika.h"


int matematika(void);
int harrapatu(int x, int gora, int aldatu);
int mateaktualizatu(int gora, int puntuazioa, int aldatu, char* kronometroa);
void krono20(int* bigarrena, int* lehena, int* segunduak, int* geio2, int* geio, int* mantendu);
#endif