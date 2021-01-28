#include "mylib.h"

//dichiarazioni funioni e puntatori di classe static
static void ins_terra ();
static void canc_terra ();
static void stampa_percorso();
static int chiudi_percorso();
static int avanza();
static int prendi_tesoro(int totale);
static int usa_pozione();
static int combatti();
static int distruggi_terra();
static int casual();
static void stop();
static struct Terra* percorso = NULL;
static struct Terra* ultima_terra = NULL;
static struct Terra* counter = NULL;
static struct Terra* stampapercorso=NULL;
static struct Terra* muovioberon=NULL;
static struct Terra* libera=NULL;
static struct Oberon* modifica=NULL;
int main();
//void valori();
int c=0;
int numeroTerre=0;
char arrayTerra[6][10]={"deserto", "foresta", "palude", "villaggio", "pianura", "mare"};
char arrayMostro[6][10]={"nessuno", "scheletro", "lupo", "orco", "squalo", "drago"};
int vitaMostro[6]={0,2,1,3,4,5};
unsigned short i=1;
unsigned short y=1;
int totale, pozioni=0, vita, controllo=0, incantesimi, sicurezza=0, vita, conta,distrutto=0;

//funzione con il menu per creare il percorso
int crea_percorso() {
	int nscelta;
	char sscelta[1];
	do 
	{
		
		printf( "\n Scegli l'operazione da eseguire: \n"
			"\n  digita: 1 per inserire una nuova terra;"
			"\n  digita: 2 per cancellare l'ultima terra inserita;"
			"\n  digita: 3 per stampare il percorso;"
			"\n  digita: 4 per terminare la creazione del percorso e tornare al menu\n");
		scanf("%s", sscelta);
		nscelta=atoi(sscelta);
			switch(nscelta) 
			{
				case 1: ins_terra(); 
				break;
			
				case 2: canc_terra(); 
				break;
			
				case 3: stampa_percorso();
				break;
			
				case 4: chiudi_percorso();
				if(c==1)
				return 0;

				default: printf("\n*Devi inserire 1, 2, 3 o 4*\n\n");
				printf("Premi invio per continuare...\n");
				while(getchar()!='\n');
				getchar(); 
			}
	}
				while (1);
}

//funzione per inserire la terra, mostri e l'oro
void ins_terra() {
unsigned short tipoTerra;
unsigned short tipoMostro;
unsigned short oro;
	system("clear");
	if(numeroTerre==0) 
	{	
		percorso = malloc(sizeof(struct Terra));
		ultima_terra = percorso;
		numeroTerre++;
	} 
	else 
	{ 
		ultima_terra->terra_successiva = malloc(sizeof(struct Terra));
		ultima_terra = ultima_terra->terra_successiva;
		numeroTerre++;
	}
		error_num:
		printf( "\n-Quale terra vuoi inserire?-\n"
			"\n  0-> deserto"
			"\n  1-> foresta"
			"\n  2-> palude"
			"\n  3-> villaggio"
			"\n  4-> pianura"
			"\n  5-> mare\n");
		scanf("%hu", &tipoTerra);
		ultima_terra->tipo_terra=tipoTerra;
		i=ultima_terra->tipo_terra;
		switch(tipoTerra)
		{	
			case(deserto):
			printf("\nHai scelto la terra di tipo: %s\n", arrayTerra[i]);
			error_deserto:
				 printf(    "\n-Quale mostro vuoi inserire?-\n"
					"\n  0-> nessuno"
					"\n  1-> scheletro"
					"\n  2-> lupo"
					"\n  3-> orco"
					"\n  4-> squalo"
					"\n  5-> drago\n");
				 scanf("%hu", &tipoMostro);
				 if(tipoMostro>5) 
				 {
				    printf("\n*Devi inserire 0, 1, 2, 3, 4 o 5!*\n");
				 	goto error_deserto;
				 }
				 if(tipoMostro==orco)
				 {
					 printf("\n*L'orco non può stare nel deserto!*\n");
					 goto error_deserto;
				 }
				 else
				 {
				 	if(tipoMostro==squalo)
				 	{
				 		printf("\n*Lo squalo non può stare nel deserto!*\n");
				 		goto error_deserto;
				 	}
				 	else 
				 	{
		                ultima_terra->tipo_mostro=tipoMostro;
		                y=ultima_terra->tipo_mostro;
		                printf("\nHai scelto il mostro di tipo: %s\n", arrayMostro[y]);
			        }
			     }
			break;
		
			case(foresta):
			printf("\nHai scelto la terra di tipo: %s\n", arrayTerra[i]);
			error_foresta:
			     printf("\n-Quale mostro vuoi inserire?-\n"
				"\n  0-> nessuno"
				"\n  1-> scheletro"
				"\n  2-> lupo"
				"\n  3-> orco"
				"\n  4-> squalo"
				"\n  5-> drago\n");
				 scanf("%hu", &tipoMostro);
				 if(tipoMostro>5) 
				 {
				    printf("\n*Devi inserire 0, 1, 2, 3, 4 o 5!*\n");
				 	goto error_foresta;
				 }
				 if(tipoMostro==squalo)
				 {
				 	printf("\n*Lo squalo non può stare nella foresta!*\n");
				 	goto error_foresta;
				 }
				 else
				 {
				    ultima_terra->tipo_mostro=tipoMostro;
				    y=ultima_terra->tipo_mostro;
		            printf("\nHai scelto il mostro di tipo: %s\n", arrayMostro[y]);  
				 }
			break;
		
			case(palude):
			printf("\nHai scelto la terra di tipo: %s\n", arrayTerra[i]);		
			error_palude:
				 printf(    "\n-Quale mostro vuoi inserire?-\n"
					"\n  0-> nessuno"
					"\n  1-> scheletro"
					"\n  2-> lupo"
					"\n  3-> orco"
					"\n  4-> squalo"
					"\n  5-> drago\n");
				 scanf("%hu", &tipoMostro);
				 if(tipoMostro>5) 
				 {
				    printf("\n*Devi inserire 0, 1, 2, 3, 4 o 5!*\n");
				 	goto error_palude;
				 }
				 if(tipoMostro==scheletro)
				 {
				 	printf("\n*Lo scheletro non può stare nella palude!*\n");
				 	goto error_palude;
				 }
				 else
				 {
				 	if(tipoMostro==lupo)
				 	{
				 		printf("\n*Il lupo non può stare nella palude!*\n");
				 	    goto error_palude;
				 	}
				 	else
				 	{
				 		if(tipoMostro==squalo)
				 	   {
					 		printf("\n*Lo squalo non può stare nella palude!*\n");
					 	    goto error_palude;
				 	   }
				 	   else
				 	   {
					 	   	ultima_terra->tipo_mostro=tipoMostro;
					 	   	y=ultima_terra->tipo_mostro;
				            printf("\nHai scelto il mostro di tipo: %s\n", arrayMostro[y]);
				 	   }

				 	}
				 }
			break;
		
			case(villaggio):
				 printf("\nHai scelto la terra di tipo: %s\n", arrayTerra[i]);
				 printf("\n-Nel villaggio non ci sono mostri-\n\n");
				 ultima_terra->tipo_mostro=nessuno;
			break;
			case(pianura):
			printf("\nHai scelto la terra di tipo: %s\n", arrayTerra[i]);
			error_pianura:
			    printf(		"\n-Quale mostro vuoi inserire?-\n"
					"\n  0-> nessuno"
					"\n  1-> scheletro"
					"\n  2-> lupo"
					"\n  3-> orco"
					"\n  4-> squalo"
					"\n  5-> drago\n");
				 scanf("%hu", &tipoMostro);
				 if(tipoMostro>5) 
				 {
				    printf("\n*Devi inserire 0, 1, 2, 3, 4 o 5!*\n");
				 	goto error_pianura;
				 }
				 if(tipoMostro==squalo)
				 {
				 	printf("\n*Lo squalo non può stare nella pianura!*\n");
				 	goto error_pianura;
				 }
				 else
				 {
				    ultima_terra->tipo_mostro=tipoMostro;
				    y=ultima_terra->tipo_mostro;
		            printf("\nHai scelto il mostro di tipo: %s\n", arrayMostro[y]);
				 }
			break;

			case(mare):
			printf("\nHai scelto la terra di tipo: %s\n", arrayTerra[i]);
			error_mare:
			    printf(    "\n-Quale mostro vuoi inserire?-\n"
					"\n  0-> nessuno"
					"\n  1-> scheletro"
					"\n  2-> lupo"
					"\n  3-> orco"
					"\n  4-> squalo"
					"\n  5-> drago\n");
				scanf("%hu", &tipoMostro);
				if(tipoMostro>5) 
				 {
				    printf("\n*Devi inserire 0, 1, 2, 3, 4 o 5!*\n");
				 	goto error_mare;
				 }
				switch(tipoMostro)
				{
				case(nessuno):
			 	ultima_terra->tipo_mostro=tipoMostro;
					y=ultima_terra->tipo_mostro;
				    printf("\nHai scelto il mostro di tipo: %s\n", arrayMostro[y]);
				    break;
			  
				case(squalo):
		            	ultima_terra->tipo_mostro=tipoMostro;
				    y=ultima_terra->tipo_mostro;
		            	printf("\nHai scelto il mostro di tipo: %s\n", arrayMostro[y]);
		            	break;		    	
				
				case(drago):
		            	ultima_terra->tipo_mostro=tipoMostro;
				    y=ultima_terra->tipo_mostro;
		            	printf("\nHai scelto il mostro di tipo: %s\n", arrayMostro[y]);
		            	break;

		        default:
		            printf("\n*Questo mostro non può stare nel mare!*\n");
		            goto error_mare;
		            break;
				}
				
	}	
	if(tipoTerra>5)
	   {
	   	printf("\n*Devi inserire 0, 1, 2, 3, 4 o 5!*\n");
	   	system("clear");
	   	goto error_num;
	   } 
		if(tipoTerra==villaggio)
	   {
	   		printf("-Scegli quanto oro inserire nella terra: ");
		    scanf("%hu", &oro);
		    if(oro>10)
		    {
		    	printf("\n*Nel villaggio puoi trovare al massimo 10 monete!*\n\n");
		    }
		}
		else
		{
         printf("-Scegli quanto oro inserire nella terra: ");
		scanf("%hu", &oro);
		}
		ultima_terra->tesoro=oro;
	system("clear");
}

//funzione per cancellare le terre
void canc_terra() {
	system("clear");                                               
	if(numeroTerre==0)
	{
 		printf("\n*Non hai ancora inserito nessuna terra*\n");
 	}
	else
	{
		if(numeroTerre==1)
		{
			free(percorso=ultima_terra);
			numeroTerre--;
		}
		else 
		{
			counter=percorso;
			while(counter->terra_successiva!= ultima_terra) 
				{
					counter=counter->terra_successiva;
				}
			ultima_terra=counter;
			free(ultima_terra->terra_successiva);
			ultima_terra->terra_successiva=NULL;
			numeroTerre--;                                           
		}
	}
}
	
//funzione per stampare il percorso
void stampa_percorso() {
	system("clear");                               
	if(numeroTerre==0)
	{
 	printf("\n*Non hai ancora inserito nessuna terra*\n");
 	}
 	else
 	{
		stampapercorso=percorso;
		do 
		{
			printf("Tipo Terra: %s\nTipo Mostro: %s\nOro: %d\n\n",arrayTerra[stampapercorso->tipo_terra],arrayMostro[stampapercorso->tipo_mostro],stampapercorso->tesoro);
			stampapercorso=stampapercorso->terra_successiva;
		}
	while (stampapercorso!=NULL) ;
	}
}	 

//funzione per chiudere il percorso
int chiudi_percorso() { 
	c=1;
	system("clear");																	
	printf("\n-Hai terminato il percorso\n \n cosa vuoi fare ora?\n\n");
	return c;
	}

//funzione con menu per controllare Oberon
int muovi_Oberon() {
		if(numeroTerre==0)
		{
			printf("devi prima creare il percorso!!\n\n");
			return 0;
		}
		else
		{
			struct Oberon Oberon1;
			Oberon1.punti_ferita=5;
			Oberon1.borsa_oro=10;
			Oberon1.pozione_guaritrice=1;
			Oberon1.incantesimi=2;
			modifica=&Oberon1;
			int n_obi;
			char s_obi[1];
			int blocco=0, blocco1=0, blocco2=0;
			int z=0;
			if(z==0) 
			{
				muovioberon=percorso;
				z++;
			}
			
			//printf("\n%d\n", numeroTerre);
			printf("Inizi la tua avventura nella terra di tipo *%s* ed hai difronte a te il mostro *%s*, l'oro a terra è pari a %d\n\n", arrayTerra[muovioberon->tipo_terra],arrayMostro[muovioberon->tipo_mostro],muovioberon->tesoro);
			  do{
				error_lotta:
				printf( "\n Cosa vuoi fare? \n"
					"\n  digita: 1 per avanzare;"
					"\n  digita: 2 per raccogliere il tesoro;"
					"\n  digita: 3 per usare la pozione;"
					"\n  digita: 4 per combattere;"
					"\n  digita: 5 per lanciare l'incantesimo distruggi terra;\n");
				scanf("%s", s_obi);
				n_obi=atoi(s_obi);
				if(muovioberon->tipo_mostro==0)
				{
					blocco2++;
				}
					switch(n_obi) 
					{
			
						case 1: 
						if(muovioberon->tipo_mostro==5)
						{
							if(blocco1!=0)
							{
								avanza();
								printf("Avanzando ti ritrovi nella terra di tipo *%s* ed hai difronte a te il mostro *%s*, l'oro a terra è pari a %d\n\n", arrayTerra[muovioberon->tipo_terra],arrayMostro[muovioberon->tipo_mostro],muovioberon->tesoro);
								blocco=0;
								blocco1=0;
								blocco2=0;
							}
							else
							{
								printf("devi battere il drago per andare avanti!\n");
							}
						}
						else
						{
							avanza();
							printf("Avanzando ti ritrovi nella terra di tipo *%s* ed hai difronte a te il mostro *%s*, l'oro a terra è pari a %d\n\n", arrayTerra[muovioberon->tipo_terra],arrayMostro[muovioberon->tipo_mostro],muovioberon->tesoro);
							blocco=0;
							blocco1=0;
							blocco2=0;
						}
						break;
			
						case 2: 
						if(blocco==0)
						{
							if(blocco2==0)
								{
									printf("devi battere il mostro prima di poter raccogliere l'oro!\n");
									goto error_tesoro;
								}
							else
								{
									totale = prendi_tesoro(Oberon1.borsa_oro);
									Oberon1.borsa_oro=totale;							
									blocco++;
								}
						}
						else
						{	
							system("clear");
							printf("hai già raccolto il tesoro!\n");
						}
						error_tesoro:
						break;
			
						case 3: 
						if(pozioni==0)
						{
							 pozioni=1;
							 vita = usa_pozione();
							 Oberon1.punti_ferita=vita;
							 Oberon1.pozione_guaritrice=0;
						}
						else 
						{	
							system("clear");
							printf("hai gia usato la tua pozione!\n");
						 	goto error_lotta;
						}
						break;
			
						case 4:
						if(muovioberon->tipo_mostro!=0)
						{
							if(blocco1==0)
							{
								combatti();
								blocco1++;
								blocco2++;
							}
							else
							{	system("clear");
						    	printf("hai già sconfitto il mostro di questa terra!\n");
							}
						}
						else
						{	
							system("clear");
							printf("in questa terra non ci sono mostri da combattere!\n");
						}
						break;
						
						case 5: distruggi_terra();
						break;
						
						default: printf("\n*Devi inserire 1, 2, 3, 4 o 5!*\n\n");
						printf("Premi invio per continuare...\n");
						while(getchar()!='\n');
						getchar(); }
			}
						while (1);
		}
}

//funzione per far avanzare Oberon
int avanza() {
	system("clear");
	if(numeroTerre==0)
	{
		printf("devi prima creare il percorso!\n");
		return crea_percorso(); 
	}
	else
	{
		muovioberon=muovioberon->terra_successiva;	
		if(muovioberon==NULL) 
		{
			controllo=1;
			printf("Dopo aver affrontato diversi ostacoli finalmente riesci a vedere la tua amata casa, la torre magica in cui non vedi l'ora di tornare per poterti rilassare bevendo un bel bicchiere di ippocrasso.\n\n");
			termina_gioco();
		}
	}
	return 0;
}

//funzione per prendere il tesoro
int prendi_tesoro(int totale) {	
	system("clear");
	printf("\nL'oro presente nella terra è: %d\n", muovioberon->tesoro);
	totale = totale + muovioberon->tesoro;
	if(totale>500)
	{
		printf("puoi tenere massimo 500 monete! \nOra in borsa hai 500 monete!\n");
		totale=500;
	}
	else
	{
		printf("\nHai raccolto l'oro!\nOra hai in borsa %d monete!\n", totale);
	}
return(totale);
}

//funzione per usare la pozione
int usa_pozione(){	
	system("clear");
	vita=5;
	if(sicurezza==0)
	{	
	printf("\nAdesso Oberon ha %d di vita!\n", vita);
	sicurezza++;
	return(vita);
    }
    else
    {
    	printf("non hai più pozioni!\n");
    }
    return 0;
}

//funzione per combattere
int combatti() {
		//struct Oberon Oberon1;
		int vitamostro=0, caso, nInc, turno=1, poz=0;
		y=muovioberon->tipo_mostro;
		system("clear");
		//valori();
		printf("decidi di affrontare il mostro di tipo %s, che ha %d punti vita!\n", arrayMostro[y], vitaMostro[y]);
		vitamostro=vitaMostro[y];
			if(modifica->incantesimi==0)
             	{
             		goto fint_inc;
             	}
            else
            	{
            		printf("vuoi usare l'incantesimo?\nSe sì digita 1 altrimenti 0\n");
            		scanf("%d", &nInc);
                }
            if(nInc==1)
               {
               		printf("hai sconfitto il mostro!\n");
               		modifica->incantesimi--;
               		return(0);
               }
    do{
    	    printf("\nturno %d\n", turno);
            fint_inc:
            printf("stai per attaccare!\n");
            stop();
            caso=casual();
            if(caso>60)//attacco Oberon
            	{
            		vitamostro=vitamostro-3;
            		if(vitamostro>0)
            			{
            				printf("hai colpito il mostro portandolo così a %d punti ferita", vitamostro);
            			}
            		else
            			{
            				goto fine;
            			}
            	}
            else 
            	{
            		printf("hai fallito l'attacco!\n");
                }
             stop();
            caso=casual();
            
            if(caso>50)	//attacco mostro
            	{           		
            		modifica->punti_ferita=modifica->punti_ferita-vitaMostro[y];
            		printf("il mostro ti ha colpito!\n");
            		if(modifica->punti_ferita>0)
            			{
            				printf("ora hai %d punti ferita\n", modifica->punti_ferita);          				
            				if(modifica->pozione_guaritrice==1)
            				{
            					printf("vuoi usare la pozione guaritrice?\nSe sì digita 1 altrimenti 0.\n");
            					scanf("%d", &poz);
            					if(poz==1)
            					{
            						modifica->punti_ferita = usa_pozione();
            						modifica->pozione_guaritrice=0;
            					}
            					else
            					{
            						goto error_pozione;
            					}
            				}

            			}
           			 else
            			{
            				printf("\nIL MOSTRO TI HA SCONFITTO!\n\n");
            				controllo=666;
            	   			 termina_gioco(controllo);
            			}
            	}
            else
            	{
            		printf("il mostro ha fallito l'attacco!\n");
                }
            error_pozione:
            turno++;
	  }
      while(vitamostro>0);
      fine:
	  printf("***Hai sconfitto il mostro!***\n");
	  return(incantesimi);
	system("clear");
}

//funzione per distruggere la terra										
int distruggi_terra() {
	system("clear");
	if(distrutto!=0)
	{
		printf("Durante l'ultimo utilizzo di questo incantesimo hai consumato tantissima energia ed ora sei troppo stanco per poterlo utilizzare dinuovo!\n\n");
		return 0;
	}
	
	else
	{
		printf("Decidi di utilizzare un potentissimo incantesimo per distruggere tutto ciò che hai difronte a te e teletrasportarti in un luogo possibilmente più sicuro\n\n");
		if(numeroTerre==1 || muovioberon->terra_successiva==NULL)
		{
			controllo=1;
			printf("Riuscendo con successo a fuggire dal precendente ostacolo finisci per trovarti in un luogo a te molto familiare...finalmente sei riuscito a tornare a casa, nella tua torre magica, dove ora potrai rilassarti bevendo un bel bicchiere di Ippocrasso.\n\n");
			termina_gioco();
			return controllo;
		}
		else
		{
			free(muovioberon);
			muovioberon=muovioberon->terra_successiva;
			printf("Riuscendo con successo a fuggire dal precendente ostacolo finisci per trovarti in una terra di tipo *%s* ed hai difronte a te il mostro *%s*, l'oro a terra è pari a %d\n\n", arrayTerra[muovioberon->tipo_terra],arrayMostro[muovioberon->tipo_mostro],muovioberon->tesoro);
			distrutto++;
		}
	}
return distrutto;
}

//funzione che termina il gioco con conferma
void termina_gioco() {
	if(controllo==0)
	{
		printf("\n  -Digita 1 per uscire dal gioco, 0 per continuare a giocare-\n");
		int conf;
		scanf("%d", &conf);	
		if(conf==1)
		{	
			if(numeroTerre==0)
			{
				exit(0);
			}
			libera=percorso;
			if(numeroTerre==1)
					{
					free(percorso=ultima_terra);
					}
			else
			{
				do
				{
					free(libera=libera->terra_successiva);
				}
				while (libera!=NULL) ;
			} 
			exit(0);
		}
		else
		{
			printf("L'avventura continua\n");
			system("clear");
		}
	}	
	else
	{
		int conf;
		if(controllo==666)
		{
			printf("OH NO! il mostro %s ti ha impedito di raggiungere la tua amata dimora!\n Ma non c'è da temere, un mago potente come te saprà sicuramente trovare il modo di ritentare il viaggio per riuscire a tornare a casa, d'altrone un buonissimo bicchiere di Ippocrasso sta aspettando solo te!\n\n",arrayMostro[muovioberon->tipo_mostro]);
		}
		else
		{
			printf("HAI COMPLETATO IL GIOCO!\n\n");
		}
		printf("Cosa vuoi fare ora?\ndigita 1 per ricominciare una nuova partita 0 per chiudere il gioco\n");
		scanf("%d", &conf);
		if(conf==1)
		{
			libera=percorso;
			if(numeroTerre==1)
					{
					free(percorso=ultima_terra);
					numeroTerre--;
					percorso=NULL;
					ultima_terra=NULL;
					counter=NULL;
					stampapercorso=NULL;
					muovioberon=NULL;
					libera=NULL;
					modifica=NULL;
					controllo=0;
					distrutto=0;
					i=0;
					y=0;
					pozioni=0;
					vita=0;
					controllo=0;
					incantesimi=0;
					sicurezza=0;
					conta=0;
					}
			else
			{
				do
				{
					free(libera=libera->terra_successiva);
				}
				while (libera!=NULL) ;
				percorso=NULL;
				ultima_terra=NULL;
				counter=NULL;
				stampapercorso=NULL;
				muovioberon=NULL;
				libera=NULL;
				modifica=NULL;
				numeroTerre=0;
				controllo=0;
				distrutto=0;
				i=0;
				y=0;
				pozioni=0;
				vita=0;
				controllo=0;
				incantesimi=0;
				sicurezza=0;
				conta=0;
			}
			main();
		}
		else
		{
			libera=percorso;
			if(numeroTerre==1)
					{
					free(percorso=ultima_terra);
					numeroTerre--;
					}
			else
			{
				do
				{
					free(libera=libera->terra_successiva);
				}
				while (libera!=NULL) ;
			}
			exit(0);
		}						
	}
}

//funzione che genera numeri casuali
int casual(){
	time_t t;
	int caso;
	srand((unsigned) time(&t));
	caso= rand()%101;
	return(caso);
}

/*//funzione che stampa in combattimento i vari parametri
void valori() {
	struct Oberon Oberon1;
	printf("Punti ferita: %d\n\n", Oberon1.punti_ferita);
	printf("Punti ferita: %d		Incantesimi: %d\nPozione curativa: %d		Oro: \n\n", Oberon1.punti_ferita, Oberon1.incantesimi, Oberon1.pozione_guaritrice, Oberon1.borsa_oro);
}*/

//funzione che mette in pausa il combattimento
void stop() {
	while('\n' !=getchar());
}
