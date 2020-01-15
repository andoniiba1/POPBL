#ifndef OURTYPES_H
#define OURTYPES_H

#include "ebentoak.h"
#define SOINUKOP 10


typedef enum { IRTEN, MENUA, JOKOA, NOLAJOKATU, KREDITUAK } PANTAILAK;
typedef enum { ESNATU, PLATABIDEA, MATE, OINARRI, REDES, PROGRAM, FISIKA,GENERALA } INSTRUKZIOPANTAILAK;
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
typedef struct MARKO
{
	int x1;
	int y1;
	int x2;
	int y2;

}MARKO;
IRUDIAK imagenak[32];
PANTAILAK pantailak;
POSIZIOA pos;
int ebentu;
int soniduak[SOINUKOP];


#endif