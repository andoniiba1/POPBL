#ifndef OURTYPES_H
#define OURTYPES_H

#include "ebentoak.h"
#define SOINUKOP 10


typedef enum { IRTEN, MENUA, JOKOA, INSTRUKZIOAK, KREDITUAK } PANTAILAK;
typedef struct S_IRUDIAK 
{
    int x;
    int y;
    int id;
}IRUDIAK;
typedef struct S_KONSEJOAK
{
    int x;
    int y;
    int erortzen;
    int behea;
    int id;
    int aprobatu;
}KONSEJOAK;
typedef struct S_PLATAFORMAK
{
    int x;
    int y;
    int width;
    int height;
}PLATAFORMAK;
typedef struct ANIMAZIO
{
    int ezker;
    int eskuin;
    
}ANIMAZIO;

IRUDIAK imagenak[32];
PANTAILAK pantailak;
POSIZIOA pos;
int ebentu;
int soniduak[SOINUKOP];


#endif