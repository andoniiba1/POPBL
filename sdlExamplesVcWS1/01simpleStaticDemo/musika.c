#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"
#include "musika.h"

char* soundFiles[] = { ".\\sound\\128GBVHR_01.wav", ".\\sound\\ondo.wav", ".\\sound\\bostezo.wav",
					   ".\\sound\\mmm.wav",  ".\\sound\\botoia.wav", ".\\sound\\alarma.wav", ".\\sound\\jauzia.wav",
					   ".\\sound\\korrika.wav", ".\\sound\\arrapatuta.wav", ".\\sound\\kotxea.wav", ".\\sound\\gaizki.wav",
						".\\sound\\128NIGHT_01.wav" };

void musikahasi(char* izena) {
	audioInit();
	if (!loadTheMusic(izena))
	{
		fprintf(stderr, "Unable to load music %s\n", SDL_GetError());

	}
	playMusic();
}
void soinua(char* izena, int soinuzenbakia) {
	audioInit();
	if (!loadSound(izena))
	{
		fprintf(stderr, "Unable to load music %s\n", SDL_GetError());

	}
	playSound(soniduak[soinuzenbakia]);
	
}

void soinuakkargatu(void) {
	int i;
	for (i = 0; i < SOINUKOP; i++)
	{
		if ((soniduak[i] = loadSound(soundFiles[i])) == -1)
		{
			fprintf(stderr, "Unable to load sound %s\n", SDL_GetError());
			
		}
	}
}