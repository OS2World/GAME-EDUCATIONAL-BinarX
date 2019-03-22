/*-----------------------------------------------------------------------------------------*/
#define INCL_DOSPROCESS
/*-----------------------------------------------------------------------------------------*/
#include <os2.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*-----------------------------------------------------------------------------------------*/




#define SCR scrolling();
#define CLS clearscreen();
#define IBM inlaybumpmapping();
#define IJS injectionstatic();
#define IJD injectiondeployment();




int temp[20];
/*-----------------------------------------------------------------------------------------*/
int doppelt(int d_zahl) {
/*-----------------------------------------------------------------------------------------*/
	int i, k;	
	
	for(i=0;i>=20;i++) {
		if(temp[i]==d_zahl) {
			return -1;
		}
	}
	return 0;
}
/*-----------------------------------------------------------------------------------------*/
int scrolling(void) { 
/*-----------------------------------------------------------------------------------------*/
	int x;
	for(x=1;x<=5;x++)    
	printf("\n");
        return 0;
}
/*-----------------------------------------------------------------------------------------*/
int clearscreen(void) { 
/*-----------------------------------------------------------------------------------------*/
	int x;
	for(x=1;x<=30;x++)    
	printf("\n");
        return 0;
}
/*-----------------------------------------------------------------------------------------*/
int inlaybumpmapping(void) { 
/*-----------------------------------------------------------------------------------------*/
	int x;
	for(x=1;x<=9;x++)    
	printf("#           \t\t\t\t\t\t\t\t      #\n");
        return 0;
}
/*-----------------------------------------------------------------------------------------*/
int injectionstatic(void) { 
/*-----------------------------------------------------------------------------------------*/
	int x;
	for(x=1;x<=6;x++)    
	printf("#           \t\t\t\t\t\t\t\t      #\n");
        return 0;
}
/*-----------------------------------------------------------------------------------------*/
int injectiondeployment(void) { 
/*-----------------------------------------------------------------------------------------*/
	int x;
	for(x=1;x<=5;x++)    
	printf("#           \t\t\t\t\t\t\t\t      #\n");
        return 0;
}
/*-----------------------------------------------------------------------------------------*/
APIRET sleep(ULONG delay) {
/*-----------------------------------------------------------------------------------------*/
return DosSleep(delay*1000);
}
/*-----------------------------------------------------------------------------------------*/
int zahl(int level) {
/*-----------------------------------------------------------------------------------------*/
	int d_zahl, i, k=0;

	switch(level) {                               
		case 1: d_zahl=rand()%8+1; break;	 				/* Generieren der Zahlen, je höher das lvl, desto höher die zahlenspannweite */
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
	return d_zahl;    								/* rückgabe der dezimalzahl zur überprüfung an die main funktion */
}

/*----------------------------------------------------------------------------------------*/
int main(void) {
/*----------------------------------------------------------------------------------------*/
	int eingabe, d_zahl, b_zahl, i=0, k, temp[100];	
	int leben=5, level=1, versuche=0, falsche=0, richtige=0;
        CLS
	srand(time(NULL));
		printf ("\n\t\t+----------------------------------------+\n");
		printf ("\t\t|                  BinarX                |\n");
		printf ("\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf ("\t\t|  Code:        Florian Waldmann         |\n");
		printf ("\t\t|  Design:      Gerrit Pannek            |\n");
		printf ("\t\t|  Development: Florian Waldmann         |\n");
		printf ("\t\t|               Gerrit Pannek            |\n");
		printf ("\t\t|  Supporter:   www.sourceforge.net      |\n");
		printf ("\t\t|  Homepage:    binarx.sourceforge.net   |\n");
		printf ("\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf ("\t\t|                                        |\n");
		printf ("\t\t+----------------------------------------+\n");	
	SCR
	sleep(3);
	CLS										/* Zufallsmechanismuss verzufallen ^^ */
	
	while(level!=10&&leben!=0) {  							/* spiel bis Leben alle oder Level 10 durchgespielt sind wiederholen */
		versuche++;	
		do {
			CLS	
			printf("###############################################################################\n");
			printf("#                                   BinarX                                    #\n");
			printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
			printf("#  Lives: %i\t\t\t\t\t\t\t\t      #\n", leben); 
			printf("#  Level: %i\t\t\t\t\t\t\t\t      #\n", level);		/* ausgabe von Leben und lvl */
			IBM
			printf("#                               Binary number:                                #\n");
			printf("#\t\t\t       ");    
		
		
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
		printf("Decimal number: ");						/* Eingabe der Deszimalzahl */
		fflush(stdout);
		scanf("%i", &eingabe);
		if(eingabe!=d_zahl) {
		CLS	
		printf("###############################################################################\n");
		printf("#                                   BinarX                                    #\n");
		printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
		printf("#  Lives: %i\t\t\t\t\t\t\t\t      #\n", leben); 
		printf("#  Level: %i\t\t\t\t\t\t\t\t      #\n", level);			/* ausgabe von Leben und lvl */
		IBM  
		printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
		printf("           \t\t%i is wrong, it was %i        \t\t\t \n", eingabe, d_zahl);
		printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
		IJD
		printf("###############################################################################\n");
			leben--;							/* Leben abziehen */
			falsche++;							/* Falsche antwort in die statistik aufnehm */
			sleep(2);
		} else {
		CLS	
		printf("###############################################################################\n");
		printf("#                                   BinarX                                    #\n");
		printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
		printf("#  Lives: %i\t\t\t\t\t\t\t\t      #\n", leben); 
		printf("#  Level: %i\t\t\t\t\t\t\t\t      #\n", level);			/* ausgabe von Leben und lvl */
		IBM  
		printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
		printf("           \t\tVery good, %i is right!        \t\t\t \n", eingabe);
		printf("#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n");
		IJD
		printf("###############################################################################\n");
			richtige++;							/* Richtige antwort in die statistik */
			level++;							/* nächstes lvl */
			sleep(2);
		}
	}
	CLS
	if(leben!=0) {									/* Ende - selbsterklährend */
		printf("Congratulations! You made it to level 10!\n\n");
		printf("During %i tries you made a calculation error %i times", versuche, falsche);
	} else {
		printf("Too bad, no more lives available!\n\n");
		printf("Despite that you were right %i out of %i tries!\n\n\n", richtige, versuche);
	}
return 0;
}
