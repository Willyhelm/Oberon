#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum Tipo_terra {	deserto=0, 
					foresta, 
					palude, 
					villaggio, 
					pianura, 
					mare
};

enum Tipo_mostro {	nessuno=0,
					scheletro,
					lupo, 
					orco,
					squalo, 
					drago
};

struct Terra {	enum Tipo_terra tipo_terra;
		enum Tipo_mostro tipo_mostro;
		unsigned short tesoro;
		struct Terra* terra_successiva;
};
		  
struct Oberon {	short borsa_oro;
		short punti_ferita;
		short incantesimi;
		short pozione_guaritrice;
};
			
int crea_percorso();
int muovi_Oberon();
void termina_gioco();
