#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	system("clear");
	do {
	        printf("*****************************************************\n");
	        printf("*                                                   *\n");
	        printf("*               Creation du personnage              *\n");
	        printf("*                                                   *\n");
	        printf("*****************************************************\n");
		exist = 0;
		i = 1;
		printf("\n\n           Nom du personnage : \n\n");
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
		printf ("                    1. Guerrier\n");
		printf ("                    2. Mage\n");
		printf ("                    3. Voleur\n");
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
		fprintf(characterFile, "%s;%s;%d;%d;%d;%d\n",name,className,agility,strenght,intellect,stamina);
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
	printf("*******************************************************************\n");
	printf("*                                                                 *\n");
	printf("*                   Bienvenu dans FVG                             *\n");
	printf("*                                                                 *\n");
	printf("*******************************************************************\n");
	printf("                   1.Créer un personnage       \n");
	printf("                   2.Selectionner un personnage    \n");
	

}

/*
 * permet de récuperer la selection de l'utilisateur sur le menu principal
 */
int getMenu() {

	int get;
	do {
		scanf("%d",&get);		

	}while(get != 1 && get !=2);

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
		selectCharacter();	
	}
	else {

		printf("ERROR");
	}



return 0;
}


