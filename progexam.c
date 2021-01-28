#include "mylib.h"
 
int main() {
	int nScelta, controllo=0;
	char sScelta[1];
	system("clear");
	printf( "\nBenvenuto in 'Oberon ed il mondo magico'\n\n");
	printf("Tu sei il potente mago Oberon, detto Calzino Bucato; armato di spada, un paio di incantesimi ed una pozione curativa, il tuo obiettivo è quello di farti largo tra le numerose insidie che ti si presenteranno contro (preferibilmente uscendone vivo) per riuscire a tornare nella tua amata torre magica dove potrai rilassarti bevendo un bel bicchiere di Ippocrasso.\n\n");
	printf( "Per giocare scegli fra i comandi che ti verranno proposti.\n"
			"Buona fortuna!\n\n");
	do {
		printf( "\n|-------------|"
				"\n Menù di gioco\n\n"); 
		printf(" digita: 1 per creare il percorso;\n digita: 2 per muovere Oberon;\n digita: 3 per terminare il gioco.\n");
		scanf("%s", sScelta);
		nScelta=atoi(sScelta);
		switch(nScelta) {
		case 1: system("clear");
				printf( "\n|----------|"
				"\n Crea Terra\n\n"); 
				printf("Benvenuto nel menù Terre!\n");
				crea_percorso();
				break;

		case 2: system("clear");
				printf( "\n|------------|"
				"\n Muovi Oberon\n\n");
				muovi_Oberon();
				break;

		case 3: system("clear");
				printf("\n-Confermi di voler terminare la partita?\n");
				termina_gioco(controllo);
				break;

		default: printf("\n*Per giocare devi inserire 1, 2 o 3!*\n\n");
		printf("Premi invio per continuare...\n");
		while(getchar()!='\n');
		getchar();
		system("clear");
		}
	}
	while(1);
}
