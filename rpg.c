#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void navigationMenu();


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
void printTop(char nameTxt[]) {
	FILE * character = fopen(nameTxt,"r");
	char * name = getNameCharacter(nameTxt);
	//printf("name : %s\n",name);
	char * className = getClassName(nameTxt);
	//printf("ClassName : %s\n",className);
	char * agility = getAgility(nameTxt);
	//printf("Agility : %s\n",agility);
	char * strenght = getStrenght(nameTxt);
	//printf("Strenght : %s\n",strenght);
	char * intelect= getIntelect(nameTxt);
	//printf("Intelect : %s\n",intelect);
	char * stamina= getStamina(nameTxt);
	//printf("Stamina : %s\n",stamina);
	char * xp= getXp(nameTxt);
	//printf("xp : %s\n",xp);
	char * lvl= getLvl(nameTxt);
	//printf("lvl : %s\n",lvl);
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
	char * chaineWithTxt = malloc(i+4 * sizeof(char));

	char txt[] = ".txt";
	i = 0;
	while(chaine[i] != '\0') {
		chaineWithTxt[i] = chaine[i];
		i ++;
	}
	int j = i;
	i = 0;
	while(i < 4) {
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
		char bag1[]="Popo50";
		FILE* charactersFile = NULL;
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
			fprintf(characterFile, "%s;%s;%d;%d;%d;%d;%d;%d;%d;%d;%s;\n",name,className,agility,strenght,intellect,stamina,xp,lvl,hp,hp,bag1);
			fprintf(charactersFile,"%s;",name);
		}
		else {
			printf("Impossible d'ouvrir le fichier characters.txt");
		}
		fclose(charactersFile);
		fclose(characterFile);
		free(name);
		printf("Personnage cree !\n");
	}//end of else selectedNumber == 0
}

void getMap(int sn) {
	system("clear");
	sn --;
	char ** names = getNamesCharacterFile(); //Permet de récuperer les infos du personnage selectionné
	printTop(addTxt(names[sn]));		

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
	int i = 0;
	int nbCharacter = getNbCharacter();
	if(nbCharacter != 0) {
		while(i < nbCharacter) {
			printf("             %d. %s\n",i + 1,names[i]);
			i ++;
		}
	}else {
		printf("           Aucun personnage\n");
	}
	printf("\n\n             0. Retour au menu principal\n");
	i =0;
	while(i < nbCharacter) {
		free(names[i]);
		i++;
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
				getMap(sn);
			}
			else {
			     navigationMenu();
			}
		}
		else {	
			printf("ERROR");
		}

}
int main() {
	navigationMenu();
return 0;
}


