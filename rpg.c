#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *Fonction qui retourne le nombre de character qu'il y a dans une ligne, ce qui permet de pouvoir plasser le fseek()en debut de la prochaine ligne
 */

int getNbCharLine() {

	FILE * file = NULL; 
	file =fopen("characters.txt","r"); // r for readonly
	int count=0;
	if(file != NULL) {
		char chartmp;
		do {
			
			chartmp = fgetc(file);
			if(chartmp != '\n') {
				count ++;
			}
			
		}while(chartmp != EOF && chartmp != '\n');
	}
	else printf("ERROR CAN'T OPEN FILE");
	fclose(file);
	return count;
}


/*
 * Fonction qui va retourner un tableau de tous les noms des personnages se trouvant dans characteres.txt
 */
char** getNamesCharacterFile(int nbChar) {
	FILE * characterFile = NULL;
	characterFile = fopen("characters.txt","r"); // "r" pour read only
	char chaine[10];
	char ** names = malloc (nbChar*sizeof(char*)); // J'instenci un tableau dynamic de la taille du nb de perso créé pointers de char (tableau 2dimenssions)
	int n=0;
	while(n<10) {
		names[n] = malloc (10*sizeof(char));// On instenci names[n] chaque n aura un tableau dynamic de 10 char (name)
		n++;
	}
	if(characterFile != NULL ) {
		/*int j=0;
		while(fgets(chaine,10,characterFile) !=NULL) {
			int i=0;
			while( chaine[i] !=';') {
				names[j][i] = chaine[i];
				i++;
			}
			names[j][i] = '\0';
			j++;
		}*/

		printf("lol");
	}
	else {
		printf("Impossible d'ouvrir le fichier characters.txt");
	}
	return names;
}
/*
 *FOnction qui retourne le nombre de personnage dans characters.txt
 */
int getNbCharacter() {
	FILE * characterFile = NULL;
        characterFile = fopen("characters.txt","r"); // "r" pour read only
        int count=0;
	if(characterFile != NULL ) {
        	char chartmp;
		int first = 1;
		
		do {	
			chartmp = fgetc(characterFile);
			if(chartmp != '\n' && chartmp != EOF) {	
				if(first == 1 ) {
					//printf("\n\n%c\n\n",chartmp); // il en li 1 en trop (dépassement de tampon)
					count++;
					first = 0;
				}
			}
			else {
				first = 1;
			}
		}while(chartmp != EOF);
	
	}
        else {
                printf("Impossible d'ouvrir le fichier characters.txt");
        }
	fclose(characterFile);
	return count;

}

/*
 * Fonction qui permet de demander à l'utilisateur le nom du personnage qu'il veut créer.
 */

char* getName() {
	int i = 1;
	int exist = 1;
	char * name = malloc(100 * sizeof(char));
	do {
		printf("Nom du personnage : \n");
		scanf("%s",name);
		while(name[i] != '\0') {
			i++;
		}
		int count = getNbCharacter();
		char** names = getNamesCharacterFile(count);
		/*
	         * TODO : Traitement pour comparer si le nom choisi n'existe pas déja ! 
		 */
		//printf("\nNb line dans le fichier characters.txt : %d",getNbCharacter());
		int i = 0;
		while (i > count ) {
			int j = 0;
			while(names[i][j] != '\0') {
				printf("%c",names[i][j]);
				j++;
			}
			i++;
		}
		free(names);
	}while(i > 10 && exist == 1);
	return name;
}

/*
 * Fonction qui permet de demmander à l'utilisateur de selectionner une classe (Geurrier, mage, voleur)
 */

int getClass() {

	int selectedNumber;
	do {
		printf("Quel classe voulez-vous faire ? \n");
		printf ("1.Guerrier\n");
		printf ("2.Mage\n");
		printf ("3.Voleur\n");
		scanf("%d",&selectedNumber);
	}while(selectedNumber != 1 && selectedNumber != 2 && selectedNumber != 3);
	return selectedNumber;
}

/*
 *Fonction main de la création d'un personnage
 */

void creatUser() {
	
	
	int agility;
	int strenght;
	int intellect;
	int stamina;
	FILE* characterFile = NULL;
	characterFile = fopen("characters.txt","a"); // "a" pour ajout en fin de fichier

	char className[7];
	printf("\nNb line dans le fichier characters.txt : %d",getNbCharacter());
	int selectedNumber = getClass(); 
	char* name =  getName();
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
	}
	else {
		printf("Impossible d'ouvrir le fichier characters.txt");
	}
	fclose(characterFile);
	free(name);
	printf("Personnage cree ! %d,%d,%d,%d\n",agility,strenght,intellect,stamina);
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

	printf("*******************************************************************\n");
	printf("*                   Bienvenu dans FVG                             *\n");
	printf("*                                                                 *\n");
	printf("*                                                                 *\n");
	printf("*1.Créer un personnage                                            *\n");
	printf("*                                                                 *\n");
	printf("*2.Selectionner un personnage                                     *\n");
	printf("*                                                                 *\n");
	printf("*                                                                 *\n");
	printf("*                                                                 *\n");
	printf("*******************************************************************\n");
	

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


