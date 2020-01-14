#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"
#include "testua.h"

int hitzluzera(int posizioa, char* str) {
    int luzera = 0;

    while (str[posizioa] != ' ' && str[posizioa] != '\0') {
        luzera++;
        posizioa++;
    }
    return luzera;
}
void parrafoaidatzi(int hasierax, int hasieray, int karakterelineako, char* testua,int r,int g,int b) {

    int lerrokop = 0;
    int lerroa = 0, distatzia = 50;


    lerrokop = lerrotanbanatu(karakterelineako, testua);

    while (lerroa <= lerrokop) {
        textuaIdatzi(hasierax, hasieray + (lerroa * distatzia), str[lerroa], r,g,b);
        lerroa++;
    }

}
int lerrotanbanatu(int lerroluzeramax, char* testua) {
    int c = 0, hitza = 0, lerroa = 0, lerrokoposizioa = 0;

    int lerroluzera = 0;

    while (testua[c] != '\0') {
        hitza = hitzluzera(c, testua);
        lerroluzera += hitza + 1;
        if (lerroluzera < lerroluzeramax) {
            while (testua[c] != ' ' && testua[c] != '\0') {
                str[lerroa][lerrokoposizioa] = testua[c];
                lerrokoposizioa++;
                c++;
            }
            str[lerroa][lerrokoposizioa] = testua[c];
            lerrokoposizioa++;
            c++;
        }
        else {
            str[lerroa][lerrokoposizioa] = '\0';
            lerroa++;
            lerroluzera = 0;
            lerrokoposizioa = 0;
        }
    }

    return lerroa;
}