#ifndef IRATZARRI_H
#define IRATZARRI_H
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
#include "hasierako pantailak.h"


int iratzarri(void);
void erreseteatu(int* aldia, int* lehena, int* geio, int* bigarrena, int* segunduak, int* x, int* y);
void krono10(int* lehena, int* bigarrena, int* geio, int* segunduak, int* aldia, int* errepikatu);
void etzaraesnatu(void);

#endif