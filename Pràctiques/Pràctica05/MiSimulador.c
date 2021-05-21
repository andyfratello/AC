#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */
typedef struct {
	unsigned int v;		// Bit de validesa
	int tag;
} linia_cache;

linia_cache cache[128];

int count_hit;				// Comptador de hits
int count_miss;				// Comptador de misses

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */
	for (int i = 0; i < 128; ++i) cache[i].v = 0;	// Inicialitzem tots els bits de validesa a 0
	count_hit = 0;
	count_miss = 0;
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reempla�a una linia valida
	unsigned int tag_out;	   // TAG de la linia reempla�ada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */
	byte = address%32;
	bloque_m = address/32;
	linea_mc = bloque_m%128;
	tag = bloque_m/128;

	miss = 0;
	replacement = 0;
	tag_out = 0;

	if (cache[linea_mc].v) { // vàlid 
		if (cache[linea_mc].tag == tag) { // Hit
			++count_hit;
			miss = 0;
			replacement = 0;
		} else { // Miss
			++count_miss;
			miss = 1;
			replacement = 1;
			tag_out = cache[linea_mc].tag;
			cache[linea_mc].tag = tag;
		}
	} else { // no vàlid
		++count_miss;
		miss = 1;
		replacement = 0;
		cache[linea_mc].tag = tag;
		cache[linea_mc].v = 1;
	}

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb� mesurem el temps d'execuci�
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print (address, byte, bloque_m, linea_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
	printf("Encerts: %d\nFallades: %d", count_hit, count_miss);
}
