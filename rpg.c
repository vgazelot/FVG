#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define printTop(char nameTxt[]);


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
void printTop(char nameTxt[]) {
	//FILE * character = fopen(nameTxt,"r");
	char * name = getNameCharacter(nameTxt);
	printf("name : %s\n",name);
	char * className = getClassName(nameTxt);
	printf("ClassName : %s\n",className);
	char * agility = getAgility(nameTxt);
	printf("Agility : %s\n",agility);
	char * strenght = getStrenght(nameTxt);
	printf("Strenght : %s\n",strenght);
	char * intelect= getIntelect(nameTxt);
	printf("Intelect : %s\n",intelect);
	char * stamina= getStamina(nameTxt);
	printf("Stamina : %s\n",stamina);
	char * xp= getXp(nameTxt);
	printf("xp : %s\n",xp);
	char * lvl= getLvl(nameTxt);
	printf("lvl : %s\n",lvl);
	free(name);
	free(stamina);
	free(className);
	free(agility);
	free(strenght);
	free(intelect);
	free(xp);
	free(lvl);
	//fclose(character);
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
	        printf("*****************************************************\n");
	        printf("*                                                   *\n");
	        printf("*               Creation du personnage              *\n");
	        printf("*                                                   *\n");
	        printf("*****************************************************\n");
		exist = 0;
		i = 1;
		printf("   Nom du personnage (10 characteres max): ");
		scanf("%s",name);
		while(name[i] != '\0') {
			i++;
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
	}while(i > 10 || exist == 1);
	return name;
}

/*
 * Fonction qui permet de demmander à l'utilisateur de selectionner une classe (Geurrier, mage, voleur)
 */

int getClass() {

	int selectedNumber;
	do {
		system("clear");
	        printf("*****************************************************\n");
	        printf("*                                                   *\n");
	        printf("*               Choisissez une classe               *\n");
	        printf("*                                                   *\n");
	        printf("*****************************************************\n");
		printf ("                  1. Guerrier\n");
		printf ("                  2. Mage\n");
		printf ("                  3. Voleur\n");
		scanf("%d",&selectedNumber);
	}while(selectedNumber != 1 && selectedNumber != 2 && selectedNumber != 3);
	return selectedNumber;
}




/*
 *Fonction main de la création d'un personnage
 */

void creatUser() {

	system("clear");
	int agility;
	int strenght;
	int intellect;
	int stamina;
	int xp = 100;
	int lvl =1;
	FILE* charactersFile = NULL;
	charactersFile = fopen("characters.txt","a"); // "a" pour ajout en fin de fichier

	char className[7];
	int selectedNumber = getClass();
	char* name =  getName();

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
		stamina = 10;
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
		fprintf(characterFile, "%s;%s;%d;%d;%d;%d;%d;%d;\n",name,className,agility,strenght,intellect,stamina,xp,lvl);
		fprintf(charactersFile,"%s;",name);
	}
	else {
		printf("Impossible d'ouvrir le fichier characters.txt");
	}
	fclose(charactersFile);
	fclose(characterFile);
	free(name);
	printf("Personnage cree !\n");
}

void getMap() {
	int map[10][10]={{1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
    int i,j;
    int taille1=10;
    int taille2=10;
    for (i=0;i < taille1;i++){
        for (j=0;j<taille2 ;j++){
            map[i][j]=0;
            printf("%d",*map);
       }
    }

}

/*
 * Fonction permettant de selectionner un personnage parmis une liste de perso stocké dans un fichier "characters.txt"
 */

void selectCharacter() {


	printf("SelectCharacter");


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
	printf("                3. generer map    \n");


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


int main() {

	printMenu();
	int userChoise = getMenu();

	if(userChoise == 1) {
		system("clear");
		creatUser();
	}
	else if(userChoise == 2) {
		//selectCharacter();
		printTop("bloodax.txt");
	}
	else if(userChoise == 3) {
		getMap();
	}
	else {

		printf("ERROR");
	}



return 0;
}


