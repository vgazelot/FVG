#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void navigationMenu();
char ** getMapFile(char nameMap[]);
void printMap(char **mapTab);
void play(char name[]);
char * getMapName( char nameTxt[]);
void errorFile();
char ** mapWithMen(int x,int y,char ** map);
char * getXCharacter (char nameTxt[]);
char * getYCharacter (char nameTxt[]);

char ** mapWithMen(int x,int y,char ** map) {
	if ((map[y][x] == 'H' || map[y][x] == ' ') &&
		(map[y+1][x] == 'H' || map[y+1][x] == ' ') &&
			(map[y+1][x+1] == 'H' || map[y+1][x+1] == ' ') &&
				(map[y+1][x-1] == 'H' || map[y+1][x-1] == ' ') &&
					(map[y+2][x] == 'H' || map[y+2][x] == ' ')){
		map[y][x] = 'o';
		map[y+1][x] = 'I';
		map[y+1][x+1] = '-';
		map[y+1][x-1] = '-';
		map[y+2][x] = '^';
		return map;
	}
	else{
		return map;
	}	
}




char * getNameCharacter(char nameTxt[]) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	char * name = malloc(10 * sizeof(char));
	if(character != NULL) {

		int i = 0;
		char tmp;
		do {
			tmp = fgetc(character);
			if(tmp != EOF && tmp != ';') name[i] = tmp;
			i++;
		}while(tmp != ';' && tmp != EOF);
		name[i] = '\0';	
		fclose(character);
	}
	else {
		printf("ERROR");
	}

	return name;

}

char * getClassName(char nameTxt[]) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	int c = 1;
	int second = 0;
	char * className = malloc(10*sizeof(char));
	if(character != NULL) {

		int i = 0;
		char tmp;
		do {
			tmp = fgetc(character);
			if(tmp == ';' && second == 0) {
				second = 1;
			} 
			else {
				if(second == 1 && tmp != ';') {
					className[i] = tmp;
					i++;
				}else if(second == 1 && tmp == ';') {
					c = 0;
				}	
			}
			
		}while(c == 1);
		className[i] = '\0';	
		fclose(character);
	}
	else {
		printf("ERROR");
	}
	return className;
}

char * getAgility(char nameTxt[]) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	int c = 1;
	int count = 0;
	char * agility = malloc(5*sizeof(char)); //valeur à changer si le jeux permet d'avoir une agilité sup à 9999 (lol)
	if(character != NULL) {
		int i = 0;
		char tmp;
		do {
			tmp = fgetc(character);
			if(tmp == ';' && count < 2) {
				count ++;
			} 
			else {
				if(count == 2 && tmp != ';') {
					agility[i] = tmp;
					i++;
				}else if(count == 2 && tmp == ';') {
					c = 0;
				}	
			}
			
		}while(c == 1);
		agility[i] = '\0';	
		fclose(character);
	}
	else {
		printf("ERROR");
	}
	return agility;
}

char * getStrenght(char nameTxt[]) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	int c = 1;
	int count = 0;
	char * strenght = malloc(5*sizeof(char)); //valeur à changer si le jeux permet d'avoir une agilité sup à 9999 (lol)
	if(character != NULL) {
		int i = 0;
		char tmp;
		do {
			tmp = fgetc(character);
			if(tmp == ';' && count < 3) {
				count ++;
			} 
			else {
				if(count == 3 && tmp != ';') {
					strenght[i] = tmp;
					i++;
				}else if(count == 3 && tmp == ';') {
					c = 0;
				}	
			}
			
		}while(c == 1);
		strenght[i] = '\0';	
		fclose(character);
	}
	else {
		printf("ERROR");
	}
	return strenght;
}
char * getIntelect(char nameTxt[]) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	int c = 1;
	int count = 0;
	char * intelect = malloc(5*sizeof(char)); //valeur à changer si le jeux permet d'avoir une intelect sup à 9999 (lol)
	if(character != NULL) {
		int i = 0;
		char tmp;
		do {
			tmp = fgetc(character);
			if(tmp == ';' && count < 4) {
				count ++;
			} 
			else {
				if(count == 4 && tmp != ';') {
					intelect[i] = tmp;
					i++;
				}else if(count == 4 && tmp == ';') {
					c = 0;
				}	
			}
			
		}while(c == 1);
		intelect[i] = '\0';	
		fclose(character);
	}
	else {
		printf("ERROR");
	}
	return intelect;
}
char * getStamina(char nameTxt[]) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	int c = 1;
	int count = 0;
	char * stamina = malloc(5*sizeof(char)); //valeur à changer si le jeux permet d'avoir une endu sup à 9999 (lol)
	if(character != NULL) {
		int i = 0;
		char tmp;
		do {
			tmp = fgetc(character);
			if(tmp == ';' && count < 5) {
				count ++;
			} 
			else {
				if(count == 5 && tmp != ';') {
					stamina[i] = tmp;
					i++;
				}else if(count == 5 && tmp == ';') {
					c = 0;
				}	
			}
			
		}while(c == 1);
		stamina[i] = '\0';	
		fclose(character);
	}
	else {
		printf("ERROR");
	}
	return stamina;
}
char * getXp(char nameTxt[]) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	int c = 1;
	int count = 0;
	char * xp = malloc(5*sizeof(char)); 
	if(character != NULL) {
		int i = 0;
		char tmp;
		do {
			tmp = fgetc(character);
			if(tmp == ';' && count < 6) {
				count ++;
			} 
			else {
				if(count == 6 && tmp != ';') {
					xp[i] = tmp;
					i++;
				}else if(count == 6 && tmp == ';') {
					c = 0;
				}	
			}
			
		}while(c == 1);
		xp[i] = '\0';	
		fclose(character);
	}
	else {
		printf("ERROR");
	}
	return xp;
}
char * getLvl(char nameTxt[]) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	int c = 1;
	int count = 0;
	char * lvl = malloc(5*sizeof(char)); 
	if(character != NULL) {
		int i = 0;
		char tmp;
		do {
			tmp = fgetc(character);
			if(tmp == ';' && count < 7) {
				count ++;
			} 
			else {
				if(count == 7 && tmp != ';') {
					lvl[i] = tmp;
					i++;
				}else if(count == 7 && tmp == ';') {
					c = 0;
				}	
			}
			
		}while(c == 1);
		lvl[i] = '\0';	
		fclose(character);
	}
	else {
		printf("ERROR");
	}
	return lvl;
}
char * getHPTotal(char nameTxt[]) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	int c = 1;
	int count = 0;
	char * hp = malloc(10*sizeof(char)); 
	if(character != NULL) {
		int i = 0;
		char tmp;
		do {
			tmp = fgetc(character);
			if(tmp == ';' && count < 8) {
				count ++;
			} 
			else {
				if(count == 8 && tmp != ';') {
					hp[i] = tmp;
					i++;
				}else if(count == 8 && tmp == ';') {
					c = 0;
				}	
			}
			
		}while(c == 1);
		hp[i] = '\0';	
		fclose(character);
	}
	else {
		printf("ERROR");
	}
	return hp;
}
char * getHPNew(char nameTxt[]) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	int c = 1;
	int count = 0;
	char * hp = malloc(10*sizeof(char)); 
	if(character != NULL) {
		int i = 0;
		char tmp;
		do {
			tmp = fgetc(character);
			if(tmp == ';' && count < 9) {
				count ++;
			} 
			else {
				if(count == 9 && tmp != ';') {
					hp[i] = tmp;
					i++;
				}else if(count == 9 && tmp == ';') {
					c = 0;
				}	
			}
			
		}while(c == 1);
		hp[i] = '\0';	
		fclose(character);
	}
	else {
		printf("ERROR");
	}
	return hp;
}
char * getMapName (char nameTxt[]) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	int c = 1;
	int count = 0;
	char * map = malloc(10*sizeof(char)); 
	if(character != NULL) {
		int i = 0;
		char tmp;
		do {
			tmp = fgetc(character);
			if(tmp == ';' && count < 11) {
				count ++;
			} 
			else {
				if(count == 11 && tmp != ';') {	
					map[i] = tmp;
					i++;
				}else if(count == 11 && tmp == ';') {
					c = 0;
				}	
			}
			
		}while(c == 1);
		map[i] = '\0';	
		fclose(character);
	}
	else {
		printf("ERROR");
	}
	return map;
}
char * getXCharacter (char nameTxt[]) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	int c = 1;
	int count = 0;
	char * x = malloc(10*sizeof(char)); 
	if(character != NULL) {
		int i = 0;
		char tmp;
		do {
			tmp = fgetc(character);
			if(tmp == ';' && count < 12) {
				count ++;
			} 
			else {
				if(count == 12 && tmp != ';') {
					x[i] = tmp;
					i++;
				}else if(count == 12 && tmp == ';') {
					c = 0;
				}	
			}
			
		}while(c == 1);
		x[i] = '\0';
		fclose(character);
	}
	else {
		printf("ERROR");
	}
	return x;
}
char * getYCharacter (char nameTxt[]) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	int c = 1;
	int count = 0;
	char * y = malloc(10*sizeof(char)); 
	if(character != NULL) {
		int i = 0;
		char tmp;
		do {
			tmp = fgetc(character);
			if(tmp == ';' && count < 13) {
				count ++;
			} 
			else {
				if(count == 13 && tmp != ';') {
					y[i] = tmp;
					i++;
				}else if(count == 13 && tmp == ';') {
					c = 0;
				}	
			}
			
		}while(c == 1);
		y[i] = '\0';	
		fclose(character);
	}
	else {
		printf("ERROR");
	}
	return y;
}
void setCharacter (char nameTxt[],char y[],int nb) {
	FILE * character = NULL;
	character =  fopen(nameTxt,"r");
	FILE * tmpFile = fopen("tmp.txt","w");
	if(character != NULL && tmpFile != NULL) {
		char tmpChar;
		do {
			tmpChar = fgetc(character);
			if(tmpChar != EOF)  {
				fputc(tmpChar,tmpFile);
			}
		}while(tmpChar != EOF);
		fclose(tmpFile);
		fclose(character);
		character = fopen(nameTxt,"w");
		tmpFile = fopen("tmp.txt","r");
		int count = 0; 
		if(tmpFile != NULL && character != NULL) {
			do {
				tmpChar = fgetc(tmpFile);
				if(tmpChar == ';' && tmpChar != EOF) {
					count ++;
				}
				if(count == nb) {
					int i = 0;
					fputc(';',character);
					while(y[i] != '\0') {
						fputc(y[i],character);
						i ++;
					}
					do {
						tmpChar = fgetc(tmpFile);
					}while(tmpChar != ';');
					count ++;
					fputc(';',character);
				}
				else if(tmpChar != EOF) {
					fputc(tmpChar,character);
				}

			}while(tmpChar != EOF);
			fclose(tmpFile);
			fclose(character);
		}else {
			printf("ERROR");
		}
	}
	else {
		printf("ERROR");
	}
}
void printTop(char nameTxt[]) {
	FILE * character = fopen(nameTxt,"r");
	char * name = getNameCharacter(nameTxt);
	char * className = getClassName(nameTxt);
	char * agility = getAgility(nameTxt);
	char * strenght = getStrenght(nameTxt);
	char * intelect= getIntelect(nameTxt);
	char * stamina= getStamina(nameTxt);
	char * xp= getXp(nameTxt);
	char * lvl= getLvl(nameTxt);
	int countNbCharLvl = 0;
	char * hpTotal = getHPTotal(nameTxt);
	char * hpNew = getHPNew(nameTxt);
	int hpTotalInt = atoi(hpTotal);
	int hpNewInt = atoi(hpNew);
	int nblife = 0;
	int ratioHP = ( hpNewInt * 100) / hpTotalInt;
	while(lvl[countNbCharLvl] != '\0') {
		countNbCharLvl ++;
	}
	int nbCharName = 0;
	while (name[nbCharName] != '\0') {
		nbCharName ++;
	}
	printf("***********************************************************************************************\n");
	printf("*                                                                                             *\n");
	printf("* Name : %s",name);
	int j;
	for(j=10; j> nbCharName ;j--) printf(" ");
	printf("                                                                  LvL : %s",lvl);
	int nbCharlvlMax; 
	for(nbCharlvlMax=2; nbCharlvlMax > countNbCharLvl; nbCharlvlMax --) printf(" ");
	printf(" *\n"); 
	printf("*       ----------                                                                            *\n");
	printf("* HP : |"); 
	for (nblife=0; nblife<ratioHP/10; nblife++)
		printf("#");
	for (nblife=0; nblife<10 - (ratioHP/10); nblife++)
                printf(" ");
	printf("|                                                                           *\n");
	printf("*       ----------                                                                            *\n");
	printf("***********************************************************************************************\n");
	
	free(name);
	free(stamina);
	free(className);
	free(agility);
	free(strenght);
	free(intelect);
	free(xp);
	free(lvl);
	free(hpTotal);
	free(hpNew);
	fclose(character);
}
/*
 * Fonction qui rajout ".txt" à la chaine mis en parametre
 */

char * addTxt(char chaine[]) {
	int i = 0;
	while(chaine[i] != '\0') {
		i ++;
	}
	char * chaineWithTxt = malloc(i+5 * sizeof(char));

	char txt[] = ".txt";
	i = 0;
	while(chaine[i] != '\0') {
		chaineWithTxt[i] = chaine[i];
		i ++;
	}
	int j = i;
	i = 0;
	while(i < 5) {
		chaineWithTxt[j] = txt[i];
		i ++;
		j ++;
	}
	return chaineWithTxt;
}
/*
 *FOnction qui retourne le nombre de personnage dans characters.txt
 */
int getNbCharacter() {
	FILE * charactersFile = fopen ("characters.txt","r");
	if(charactersFile != NULL) { 
		char tmp;
		int count = 0;
		int first = 1;
		do {
			tmp = fgetc(charactersFile);	
			if( tmp != EOF) {
				if(tmp != ';'&& first == 1) {
					count ++;
					first = 0;
				}
				else {
					if(tmp == ';') {
						first = 1;
					}
				}
			}
		}while(tmp != EOF);
		return count;
	}
	else {
		return 0;
	}
}


/*
 * Fonction qui va retourner un tableau de tous les noms des personnages se trouvant dans characteres.txt
 */
char** getNamesCharacterFile() {
	int nbCharacter = getNbCharacter();
	char ** names = malloc(nbCharacter * sizeof(char *));
	int i = 0;
	while(i < nbCharacter) {
		names[i] = malloc( 10 * sizeof(char));
		i ++;
	}
	FILE * charactersFile = fopen ("characters.txt","r");
	if(charactersFile != NULL) {
		char tmp;
		i = 0;
		int j= 0;
		do {
			tmp = fgetc(charactersFile);	
			if( tmp != EOF) {
				if(tmp != ';') {
					names[i][j] = tmp;
					j++;
				}
				else{
					j = 0;
					i++;
				}
			}
		}while(tmp != EOF);
		return names;
	}
	else {
		free(names);	
		char ** perror = malloc(1*sizeof(char*));
		perror[0] = malloc(5*sizeof(char));
		perror[0][0] = 'e';
		perror[0][1] = 'r';
		perror[0][2] = 'r';
		perror[0][3] = 'o';
		perror[0][4] = 'r';
		return perror;
		
	}
}

void printGetName() {
	printf("*****************************************************\n");
	printf("*                                                   *\n");
	printf("*               Creation du personnage              *\n");
	printf("*                                                   *\n");
	printf("*****************************************************\n");
	printf("             0. Retourner au menu principal  ");
	printf("\n\n   Nom du personnage (10 characteres max): ");
}
/*
 * Fonction qui permet de demander à l'utilisateur le nom du personnage qu'il veut créer.
 */
char* getName() {
	int i = 1;
	int exist = 0;
	char * name = malloc(100 * sizeof(char));
	if(name != NULL)
	{
		do {
			system("clear");
			if( i > 10) {
				printf("Nom supérieur a 10 characteres \n" );
			}
			int i = 0;
			exist = 0;
			printGetName();
			scanf("%s",name);
			while(name[i] != '\0') {
				i++;
			}
			if(name[0] == '0')
			{
				navigationMenu();
				return NULL;
			}
			else {
				
				int j = 0;
				while(j < sizeof(name)){
					if(name[j] == ';' || name[j] == ' ' || name[j] == ',' || name[j] == ':' || name[j] == '!' || name[j] == '.' || name[j] == '?') {
						name[j]='_';
					}
					j++;
				}	
				int nbCharacter = getNbCharacter();
				char ** names = getNamesCharacterFile();
				int t = 0; 
				int diff = 0;
				while( t < nbCharacter && exist == 0) {
					int j = 0;
					int n = 0;
					diff = 0;
					while(names[t][j] != '\0' && diff == 0 && name[n] != '\0') {
						if( name[n] != names[t][j]) {
							diff = 1;	
						}
						j++;
						n++;
					}
					if(diff == 0) {
						exist = 1;		
					}
					t++;
				}
				if(exist == 1 && nbCharacter > 0) {
					system("clear");
					printf("/!\\ PERSONNAGE DEJA EXISTANT ! /!\\ \n Veuillez choisir un autre nom.\n");
					exist = 1;	
				}
				free(names);
			}
		}while(i > 10 || exist == 1);
	return name;
	}
	else {
		exit(0);
	}
}


void printAllClass() {
	printf("*****************************************************\n");
	printf("*                                                   *\n");
	printf("*               Choisissez une classe               *\n");
	printf("*                                                   *\n");
	printf("*****************************************************\n");
	printf ("                  1. Guerrier\n");
	printf ("                  2. Mage\n");
	printf ("                  3. Voleur\n");
	printf ("\n\n              0. Retour au menu principal\n");
}
/*
 * Fonction qui permet de demmander à l'utilisateur de selectionner une classe (Geurrier, mage, voleur)
 */
int getClass() {

	int selectedNumber;
	do {
		system("clear");
		printAllClass();
		scanf("%d",&selectedNumber);
	}while(selectedNumber != 1 && selectedNumber != 2 && selectedNumber != 3 && selectedNumber != 0);
	return selectedNumber;
}




/*
 *Fonction main de la création d'un personnage
 */

void creatUser() {
	system("clear");	
	int selectedNumber = getClass(); 
	if(selectedNumber == 0 ) {
		navigationMenu();
	}else
	{
		int agility;
		int strenght;
		int intellect;
		int stamina;
		int xp = 1;
		int lvl =1;
		int hp = 500;
		char map[] = "startMap";
		char bag1[]="Popo50";
		int x = 10;
		int y = 10;
		FILE * charactersFile = NULL;
		charactersFile = fopen("characters.txt","a"); // "a" pour ajout en fin de fichier

		char className[7];
		char* name =  getName();
		if( name == NULL) { //Selection du 0 (go menu) 
			return;
		}
		char * chaineWithTxt = addTxt(name);
		FILE * characterFile = fopen(chaineWithTxt, "a");
		if(selectedNumber == 1) { //guerrier
			className[0] = 'W';
			className[1] = 'a';
			className[2] = 'r';
			className[3] = 'r';
			className[4] = 'i';
			className[5] = 'o';
			className[6] = 'r';
			className[7] = '\0';
			agility = 5;
			strenght = 10;
			intellect = 5;
			stamina = 7;
		}
		else if (selectedNumber == 2 ) { //Mage
			className[0] = 'M';
			className[1] = 'a';
			className[2] = 'g';
			className[3] = 'e';
			className[4] = '\0';
			agility = 5;
			strenght = 5;
			intellect = 10;
			stamina = 7;
		}
		else if(selectedNumber == 3) { //Voleur
			className[0] = 'R';
			className[1] = 'o';
			className[2] = 'g';
			className[3] = 'u';
			className[4] = 'e';
			className[5] = '\0';
			agility = 10;
			strenght = 5;
			intellect = 5;
			stamina = 7;
		}
		if(characterFile != NULL) {
			fprintf(characterFile, "%s;%s;%d;%d;%d;%d;%d;%d;%d;%d;%s;%s;%d;%d;\n",name,className,agility,strenght,intellect,stamina,xp,lvl,hp,hp,bag1,map,x,y);
			fprintf(charactersFile,"%s;",name);
			fclose(charactersFile);
			fclose(characterFile);
			play(name);
		}
		else {
			fclose(charactersFile);
			fclose(characterFile);
			printf("Impossible d'ouvrir le fichier characters.txt");
			free(name);
		}
	}//end of else selectedNumber == 0
}


/*
 * Fonction qui permet de récuperer l'action du jouer (déplacement du personnage)
 */
char userAction() {
	int boolean = 0;
	char action = NULL;
	while (boolean == 0) {
		scanf("%c",&action);
		if(action == 'd' || action == 's' || action == 'q' || action == 'z' || action == 'e') {
			boolean = 1;
		}
	}
	return action;	
}

/*
 * Fonction qui permet de bouger le perssonage dans le tableau map
 */
void deplacement(char action, char * nameTxt, char ** map) {
//	FILE * charcterFile = fopen(nameTxt,"w+"); 		
	char * xchar = getXCharacter(nameTxt);
	char * ychar = getYCharacter(nameTxt);
	int x = atoi(xchar);
	int y = atoi(ychar);		
	map[y][x] = ' ';
	map[y+1][x] = ' ';
	map[y+1][x+1] = ' ';
	map[y+1][x-1] = ' ';
	map[y+2][x] = ' ';
	if (action == 'z') {
		y = y -1;	
	}
	else if(action == 'q') {
		x = x - 1;
	}
	else if(action == 's') {
		y = y + 1;
	}
	else if(action == 'd') {
		x = x + 1;
	}else {
		return;	
	}
	if ((map[y][x] == 'H' || map[y][x] == ' ') &&
		(map[y+1][x] == 'H' || map[y+1][x] == ' ') &&
			(map[y+1][x+1] == 'H' || map[y+1][x+1] == ' ') &&
				(map[y+1][x-1] == 'H' || map[y+1][x-1] == ' ') &&
					(map[y+2][x] == 'H' || map[y+2][x] == ' ')){
		char yIntToChar[10]; 
		sprintf(yIntToChar,"%d",y);
		char xIntToChar[10]; 
		sprintf(xIntToChar,"%d",x);
		setCharacter(nameTxt,xIntToChar,12);
		setCharacter(nameTxt,yIntToChar,13);
	}
	else if(map[y][x] == '1' ) {
		setCharacter(nameTxt,"maison1",11);
		setCharacter(nameTxt,"10",12);
		setCharacter(nameTxt,"10",13);
	}
}
/*
 * Fonction principal, celle qui va faire tourner le jeu
 */
void play(char name[]) {
	char * nameTxt = addTxt(name);
	char * mapName = getMapName(nameTxt);
	char ** map = getMapFile(mapName);
	if(map[0][0] == 'e' && map[0][1] == 'r' && map[0][2] == 'r' && map[0][3] == 'o' && map[0][4] == 'r' ) {
        	free(map[0]);
		free(map);
		free(mapName);
		free(nameTxt);
		navigationMenu();
	}
	else {
		system("clear");
		printTop(nameTxt);
		char * xchar = getXCharacter(nameTxt);
		char * ychar = getYCharacter(nameTxt);
		int xint = atoi(xchar);
		int yint = atoi(ychar);		
		map = mapWithMen(xint ,yint, map);
		printMap(map);
		char action = userAction();
		deplacement(action,nameTxt,map);		
		
		//on clear tous les mallocs
		int i = 0;
		while(i <35) {
        		free(map[i]);
        		i++;
        	}
		free(xchar);
		free(ychar);
		free(map);
		free(mapName);
		free(nameTxt);
		play(name);	
	}
}
	
/*
 * Fonction qui afficher le menu principal 
 */
void printMenu () {
	system("clear");
	printf("*****************************************************\n");
	printf("*                                                   *\n");
	printf("*                 Bienvenu dans FVG                 *\n");
	printf("*                                                   *\n");
	printf("*****************************************************\n");
	printf("                1. Créer un personnage       \n");
	printf("                2. Selectionner un personnage    \n");
	

}

/*
 * permet de récuperer la selection de l'utilisateur sur le menu principal
 */
int getMenu() {
	int get;
	do {
		scanf("%d",&get);		

	}while(get != 1 && get !=2 && get != 3);
	return get;
}

void printAllCharacter() {
	system("clear");
	printf("*****************************************************\n");
	printf("*                                                   *\n");
	printf("*              Selection du personnage              *\n");
	printf("*                                                   *\n");
	printf("*****************************************************\n");
	char ** names = getNamesCharacterFile();
	int nbCharacter = getNbCharacter();
	int true = 0;
	if(names[0][0] == 'e' && names[0][1] == 'r' &&names[0][2] == 'r' && names[0][3] == 'o'&&names[0][4] == 'r') {	
		printf("Fichier characters introuvable.\n");
		errorFile();
		navigationMenu();
	}
	else {
		int i = 0;
		if(nbCharacter != 0) {
			while(i < nbCharacter) {
				printf("             %d. %s\n",i + 1,names[i]);
				i ++;
			}
		}else {
			printf("           Aucun personnage\n");
		}
		true =1;
		printf("\n\n             0. Retour au menu principal\n");
	}
	if(nbCharacter == 0) {
		if (true == 1 ) { // tout est ok, juste 0 personnage
			int i =0;
			while(i < nbCharacter) {
				free(names[i]);
				i++;
			}
		}
		free(names[0]);
	}
	else {
		int i =0;
		while(i < nbCharacter) {
			free(names[i]);
			i++;
		}
	}
		free(names);
}
int  selectCharacter() {
	int selectedNumber;
	printAllCharacter();
	int nbCharacter = getNbCharacter();
	do {	
		scanf("%d",&selectedNumber);
	}while((selectedNumber < 0 || selectedNumber > nbCharacter) && selectedNumber != 0);
	return selectedNumber;
}
void navigationMenu() {
		printMenu();
		int userChoise = getMenu();
		if(userChoise == 1) {
			creatUser();
		}
		else if(userChoise == 2) {
			int sn = selectCharacter();
			if(sn != 0 ) {
				sn --;
				char ** names = getNamesCharacterFile();
				play(names[sn]);
			}
			else {
			     navigationMenu();
			}
		}	
		else {	
			printf("ERROR");
		}

}

void printMap(char **mapTab) {
	int i = 0;
	while( i < 35 ){
		int j = 0 ;
		while ( j < 96 ){
			printf("%c",mapTab[i][j]);	
			j++;
		}
		i++;
	}
}
void errorFile() {

		int j = 5;
		while(j > 0) {
			printf("Retour au menu principal dans %ds...\n",j);
			system("sleep 1");
			j--;
		}
}
char ** getMapFile(char nameMap[]) {
	FILE * map = NULL; 
	char * nameMapTxt = addTxt(nameMap);
	map = fopen(nameMapTxt,"r");
	char ** mapTab = malloc(35*sizeof(char *));
	int i = 0;
	while(i < 35){
		mapTab[i] = malloc(96*sizeof(char));
		i++;
	}
	if(map != NULL) {
		char tmp;
		int countC = 0;
		int countL = 0;
		do {
			tmp = fgetc(map);
			if(tmp != EOF) {
				if(countC < 96) {
					mapTab[countL][countC] = tmp;
					countC ++;	
				}
				else {
					countL ++;
					countC = 0;
					mapTab[countL][countC] = tmp;
				}
			} 
		}while(tmp != '\0' && tmp != EOF);
		free(nameMapTxt);
		fclose(map);
		return mapTab;
	}
	else {
		printf("Fichier %s introuvable.\n",nameMapTxt);
		errorFile();
		free(nameMapTxt);
		char ** perror = malloc(1*sizeof(char*));
		perror[0] = malloc(5*sizeof(char));
		perror[0][0] = 'e';
		perror[0][1] = 'r';
		perror[0][2] = 'r';
		perror[0][3] = 'o';
		perror[0][4] = 'r';
		return perror;
	}
}
int main() {
	navigationMenu();
return 0;
}


