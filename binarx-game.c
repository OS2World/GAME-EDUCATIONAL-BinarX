//-----------------------------------------------------------------------------------------
#include <stdio.h>
//-----------------------------------------------------------------------------------------




#define SCR scrolling();
#define CLS clearscreen();
#define IBM inlaybumpmapping();
#define IJS injectionstatic();
#define IJD injectiondeployment();




int temp[20];
//-----------------------------------------------------------------------------------------
int doppelt(int d_zahl) {
//-----------------------------------------------------------------------------------------
	int i, k;	
	
	for(i=0;i>=20;i++) {
		if(temp[i]==d_zahl) {
			return -1;
		}
	}
	return 0;
}
//-----------------------------------------------------------------------------------------
int scrolling(void) { 
//-----------------------------------------------------------------------------------------
	int x;
	for(x=1;x<=5;x++)    
	printf("\n");
}
//-----------------------------------------------------------------------------------------
int clearscreen(void) { 
//-----------------------------------------------------------------------------------------
	int x;
	for(x=1;x<=30;x++)    
	printf("\n");
}
//-----------------------------------------------------------------------------------------
int inlaybumpmapping(void) { 
//-----------------------------------------------------------------------------------------
	int x;
	for(x=1;x<=9;x++)    
	printf("#           \t\t\t\t\t\t\t\t      #\n");
}
//-----------------------------------------------------------------------------------------
int injectionstatic(void) { 
//-----------------------------------------------------------------------------------------
	int x;
	for(x=1;x<=6;x++)    
	printf("#           \t\t\t\t\t\t\t\t      #\n");
}
//-----------------------------------------------------------------------------------------
int injectiondeployment(void) { 
//-----------------------------------------------------------------------------------------
	int x;
	for(x=1;x<=5;x++)    
	printf("#           \t\t\t\t\t\t\t\t      #\n");
}

//-----------------------------------------------------------------------------------------
int zahl(int level) {
//-----------------------------------------------------------------------------------------
	int d_zahl, i, k=0;

	switch(level) {                               
		case 1: d_zahl=rand()%8+1; break;	 				//Generieren der Zahlen, je höher das lvl, desto höher die zahlenspannweite
		case 2: d_zahl=rand()%8+7; break;
		case 3: d_zahl=rand()%17+16; break;
		case 4: d_zahl=rand()%33+32; break;
		case 5: d_zahl=rand()%44+43; break;	
		case 6: d_zahl=rand()%65+64; break;
		case 7: d_zahl=rand()%129+128; break;
		case 8: d_zahl=rand()%182+182; break;
		case 9: d_zahl=rand()%513+512; break;
		case 10: d_zahl=rand()%1025+1024; break;
		default: d_zahl=rand()%100+1000; break;
	}
								
	for(i=12;i>=0;i--)
	{
		if(d_zahl&(1<<i)) { 
			printf("1");
			k=1;
		} else if(k!=0) {  
			printf ("0");
		} else if(k==0) {
			printf(" ");
		}
	}
	return d_zahl;    								//rückgabe der dezimalzahl zur überprüfung an die main funktion
}

//----------------------------------------------------------------------------------------
int main(void) {
//----------------------------------------------------------------------------------------
	CLS
	int eingabe, d_zahl, b_zahl, i=0, k, temp[100];	
	int leben=5, level=1, versuche=0, falsche=0, richtige=0;
	srand(time(NULL));
		printf ("\n\t\t+----------------------------------------+\n");
		printf ("\t\t|                  BinarX                |\n");
		printf ("\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf ("\t\t|  Code:        Florian Waldmann         |\n");
		printf ("\t\t|  Design:      Gerrit Pannek            |\n");
		printf ("\t\t|  Entwicklung: Florian Waldmann         |\n");
		printf ("\t\t|               Gerrit Pannek            |\n");
		printf ("\t\t|  Supporter:   www.sourceforge.net      |\n");
		printf ("\t\t|  Homepage:    binarx.sourceforge.net   |\n");
		printf ("\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf ("\t\t|                                        |\n");
		printf ("\t\t+----------------------------------------+\n");	
	SCR
	sleep(3);
	CLS										//Zufallsmechanismuss verzufallen ^^
	
	while(level!=10&&leben!=0) {  							//spiel bis Leben alle oder Level 10 durchgespielt sind wiederholen
		versuche++;	
		do {
			CLS	
			printf("###############################################################################\n");
			printf("#                                   BinarX                                    #\n");
			printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
			printf("#  Leben: %i\t\t\t\t\t\t\t\t      #\n", leben); 
			printf("#  Level: %i\t\t\t\t\t\t\t\t      #\n", level);		//ausgabe von Leben und lvl
			IBM
			printf("#                                  Binärzahl:                                 #\n");
			printf("#\t\t\t    ");    
		
		
			d_zahl=zahl(level);           

      			temp[i]=d_zahl;
      			k=0;
      			while(k<i) {
     				if(temp[k]==d_zahl) {
         				i--;
        			}
         			k++;
			}
     			i++;
   		} while(d_zahl==temp[i]);

		printf("\t\t\t\t      #\n");  
		IJS
		printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
		printf("Dezimalzahl: ");						//Eingabe der Deszimalzahl
		scanf("%i", &eingabe);
	
		if(eingabe!=d_zahl) {
		CLS	
		printf("###############################################################################\n");
		printf("#                                   BinarX                                    #\n");
		printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
		printf("#  Leben: %i\t\t\t\t\t\t\t\t      #\n", leben); 
		printf("#  Level: %i\t\t\t\t\t\t\t\t      #\n", level);			//ausgabe von Leben und lvl
		IBM  
		printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
		printf("           \t\t%i ist falsch, es war %i        \t\t\t \n", eingabe, d_zahl);
		printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
		IJD
		printf("###############################################################################\n");
			leben--;							//Leben abziehen
			falsche++;							//Falsche antwort in die statistik aufnehm
			sleep(2);
		} else {
		CLS	
		printf("###############################################################################\n");
		printf("#                                   BinarX                                    #\n");
		printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
		printf("#  Leben: %i\t\t\t\t\t\t\t\t      #\n", leben); 
		printf("#  Level: %i\t\t\t\t\t\t\t\t      #\n", level);			//ausgabe von Leben und lvl
		IBM  
		printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
		printf("           \t\tSehr gut! %i ist richtig!        \t\t\t \n", eingabe);
		printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
		IJD
		printf("###############################################################################\n");
			richtige++;							//Richtige antwort in die statistik
			level++;							//nächstes lvl
			sleep(2);
		}
	}
	CLS
	if(leben!=0) {									//Ende - selbsterklährend
		printf("Gratulation! Du hast es bis Level 10 geschaft!\n\n");
		printf("Du hast dabei %i mal von %i Aufgaben falsch gerechnet", versuche, falsche);
	} else {
		printf("Schade aber deine Leben sind verbraucht!\n\n");
		printf("Trotzdem hattest du %i von %i Aufgaben richtig!\n\n\n", richtige, versuche);
	}
}		



