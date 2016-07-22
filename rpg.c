#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef
typedef struct Character Character;
typedef struct Quest Quest;
typedef struct Monster Monster;
//controler
void navigationMenu();
void play(char name[]);
void errorFile();
char * addTxt(char chaine[]);
char* getName();
int getClass();
char userAction();
int strcomp2(char * str1, char * str2);
int deplacement(char action,Character * user, char ** map);
int getMenu();
int  selectCharacter();
//Fight

void printHp(char ** screenFight,Character * user,Monster * monster);
void bot(Monster * monster, Character * user );
void printBottom(Character * user);
char ** addMonster(char ** screenFight,char name[]);
void printScreenFight(char ** ScreenTab);
void fight(Character * user);
char actionUserFight();
void traitementAction(char action,Character * user,Monster* monster);
void flashMonster(char** screenFight,Monster* monster,Character* user);

//Print
void printGetName();
void printTop(Character * user);
void printMap(char **mapTab, Character* user,Quest* quests);
void printAllClass();
void printDialog(char dialogName[], char name[],Quest* quests);
void printMenu ();
void printMenuInGame();
void printAllCharacter();

//map 
char * getMapName( char nameTxt[]);
char ** mapWithMen(int x,int y,char ** map);
char ** getMapFile(char mapName[]);


//Quests
void creatQuest( char name[]);
char * addQuestTxt(char chaine[]);
void addQuest(char name[],int nb, char chaine[],char nbStart[], char nbEnd[]);
int QuestIsDone(char name[],int nbQuest);
char * getQuestMission(char name[],int nb);  
char * getStartQuest(char questFile[],int id);
char * getEndQuest(char questFile[],int id);
char * getStatusQuest(char questFile[],int id);


//user structure 

struct Character* getUser(char name[]);
void creatUser();
char** getNamesCharacterFile();
char * getNameCharacter(char nameTxt[]);
void setCharacter (char nameTxt[],char y[],int nb);
char * getClassName(char nameTxt[]);  
char * getAgility(char nameTxt[]);
char * getStrenght(char nameTxt[]);
char * getIntelect(char nameTxt[]);
char * getStamina(char nameTxt[]);
char * getXp(char nameTxt[]);
char * getLvl(char nameTxt[]);
char * getHPTotal(char nameTxt[]);
char * getHPNew(char nameTxt[]);
char * getMapName (char nameTxt[]);
char * getDialog (char nameTxt[]);
char * getXCharacter (char nameTxt[]);
char * getYCharacter (char nameTxt[]);
int getNbCharacter();

//monster
Monster *getSpider();
Monster *getOther();
//MenuInGame
int getActionMenuInGame();


//save
void save(Character* user, Quest* quests);


struct Monster {
	int hp;
	int hpMax;
	int strenght;
	int def;
	int attack;
	char name[10];

};
struct Character {
	char name[10];
	char className[10];
	int agility;
	int strenght;
	int intellect;
	int stamina;
	int xp;
	int lvl;
	int hp;
	int hpMax;
	char map[100] ;
	char bag1[100];
	int x;
	int y;
	char dial[30];

};
struct Quest {
	int id;
	char mission[100];
	int start;
	int end;
	int status;	
};
Monster *getSpider(){
	Monster spider;
	Monster * pspider = malloc(sizeof(spider));
	pspider->hp = 250;
	pspider->hpMax = 250;
	pspider->strenght = 60;
	pspider->def = 10; 
	pspider->name[0] = 's';
	pspider->name[1] = 'p';
	pspider->name[2] = 'i';
	pspider->name[3] = 'd';
	pspider->name[4] = 'e';
	pspider->name[5] = 'r';
	pspider->name[6] = '\0';
	pspider->attack = 30;
	return pspider;

}
Monster *getOther(){
	Monster other;
	Monster * pother = malloc(sizeof(other));
	pother->hp = 250;
	pother->hpMax = 250;
	pother->strenght = 60;
	pother->def = 25; 
	pother->name[0] = 'o';
	pother->name[1] = 't';
	pother->name[2] = 'h';
	pother->name[3] = 'e';
	pother->name[4] = 'r';
	pother->name[6] = '\0';
	pother->attack = 30 ;
	return pother;
}



Character* getUser(char name[]) {
	Character user;
	Character* pUser = malloc(sizeof(user));
	char* nameWithTxt = addTxt(name);
	int i = 0;
	while(name[i] != '\0') {
		pUser->name[i] = name[i];
	 	i++;	
	}
	pUser->name[i] = '\0';
	char* className = getClassName(nameWithTxt);
	i =0;
	while(className[i] != '\0') {
		pUser->className[i] = className[i];
	 	i++;	
	}
	pUser->agility = atoi(getAgility(nameWithTxt));
	pUser->strenght = atoi(getStrenght(nameWithTxt));
	pUser->intellect = atoi(getIntelect(nameWithTxt));
	pUser->stamina = atoi(getStamina(nameWithTxt));
	pUser->xp = atoi(getXp(nameWithTxt));
	pUser->lvl = atoi(getLvl(nameWithTxt));
	pUser->hp = atoi(getHPNew(nameWithTxt));
	pUser->hpMax = atoi(getHPTotal(nameWithTxt));
	char* map = getMapName(nameWithTxt);
	i =0;
	while(map[i] != '\0') {
		pUser->map[i] = map[i];
	 	i++;	
	}
	pUser->map[i] = '\0';
//	pUser->bag1[100];
	pUser->x = atoi(getXCharacter(nameWithTxt));
	pUser->y = atoi(getYCharacter(nameWithTxt));
	char* dial = getDialog(nameWithTxt);
	i =0;
	while(map[i] != '\0') {
		pUser->dial[i] = dial[i];
	 	i++;	
	}
	pUser->dial[i] = '\0';
	return pUser;
}

Quest * initQuest(int id,char mission[],int start, int end, int status) {
	Quest tquest;
	Quest * pQuest = malloc(sizeof(tquest));
	pQuest->id = id;
	int i =0;
	while(mission[i] != '\0') {
		pQuest->mission[i] = mission[i];
	 	i++;	
	}
	pQuest->mission[i] = '\0';
	pQuest->start = start;
	pQuest->end = end;
	pQuest->status = status;
	return pQuest;
}


char * getMissionQuest(char questFile[], int id) {
	FILE * quests = NULL;
	quests =  fopen(questFile,"r");
	int c = 1;
	char * mission = malloc(100*sizeof(char));
	if(quests != NULL) {
		int i = 0;
		char tmp;
		int j = 1;
		while (j < id) {
			tmp = fgetc(quests);
			if(tmp == '\n') {
				j++;
			}
		}
		do {
			tmp = fgetc(quests);
		}while(tmp != ';' && tmp == EOF);
		tmp = fgetc(quests);
		if(tmp != EOF) {
			do {
				tmp = fgetc(quests);
				if(((tmp >= 48 && tmp <= 122) || tmp == 32 ) && tmp != 59) {
					mission[i] = tmp;
					i++;
				}else {
					c =0;
				} 
			}while(c == 1);
			
			mission[i] = '\0';	
		}
		fclose(quests);
	}
	else {
		printf("ERROR OPEN QUEST MISSION\n");
	}
	return mission;
}
char * getStartQuest(char questFile[],int id) {
	FILE * quests = NULL;
	quests =  fopen(questFile,"r");
	int c = 1;
	int count =1 ;
	char * start = malloc(3*sizeof(char));
	if(quests != NULL) {
		int i = 0;
		char tmp;
		int j = 1;
		while (j < id) {
			tmp = fgetc(quests);
			if(tmp == '\n') {
				j++;
			}
		}
		do {
			tmp = fgetc(quests);
			if(tmp == ';' && count < 2) {
				count ++;
			} 
			else {
				if(count == 2 && tmp != ';' && i <3) {
					start[i] = tmp;
					i++;
				}else if((count == 2 && tmp == ';') || i>= 3) {
					c = 0;
				}else if (i > 3) {
					c = 0;
				}
			}
			
		}while(c == 1);
		start[i] = '\0';
		fclose(quests);
	}
	else {
		printf("ERROR open quest start\n");
	}
	return start;
}

char * getEndQuest(char questFile[],int id) {
	FILE * quests = NULL;
	quests =  fopen(questFile,"r");
	int c = 1;
	int count = 0;
	char * end = malloc(3*sizeof(char));
	if(quests != NULL) {
		int i = 0;
		char tmp;
		int j = 1;
		while (j < id) {
			tmp = fgetc(quests);
			if(tmp == '\n') {
				j++;
			}
		}
		do {
			tmp = fgetc(quests);
			if(tmp == ';' && count < 3) {
				count ++;
			} 
			else {
				if(count == 3 && tmp != ';' && i < 3) {
					end[i] = tmp;
					i++;
				}else if((count == 3 && tmp == ';') || i>= 3) {
					c = 0;
				}else if (i > 3) {
					c = 0;
				}
			}
			
		}while(c == 1);
		end[i] = '\0';	
		fclose(quests);
	}
	else {
		printf("ERROR OPEN END \n");
	}
	return end;
}
char * getStatusQuest(char questFile[],int id) {
	FILE * quests = NULL;
	quests =  fopen(questFile,"r");
	int c = 1;
	int count = 0;
	char * status = malloc(3*sizeof(char));
	if(quests != NULL) {
		int i = 0;
		char tmp;
		int j = 1;
		while (j < id) {
			tmp = fgetc(quests);
			if(tmp == '\n') {
				j++;
			}
		}
		do {
			tmp = fgetc(quests);
			if(tmp == ';' && count < 4) {
				count ++;
			} 
			else {
				if(count == 4 && tmp != ';' && i < 3) {
					status[i] = tmp;
					i++;
				}else if((count == 4 && tmp == ';') || i>= 3) {
					c = 0;
				}else if (i > 3) {
					c = 0;
				}
			}
			
		}while(c == 1);
		status[i] = '\0';	
		fclose(quests);
	}
	else {
		printf("ERROR open quest status\n");
	}
	return status;
}

char ** getScreenFight(){
	FILE * ScreenFightFile = NULL; 
	ScreenFightFile = fopen("ScreenFight.txt","r");
	char ** ScreenTab = malloc(35*sizeof(char *));
	int i = 0;
	while(i < 35){
		ScreenTab[i] = malloc(96*sizeof(char));
		i++;
	}
	if(ScreenFightFile != NULL) {
		char tmp;
		int countC = 0;
		int countL = 0;
		do {
			tmp = fgetc(ScreenFightFile);
			if(tmp != EOF) {
				if(countC < 96) {
					ScreenTab[countL][countC] = tmp;
					countC ++;	
				}
				else {
					countL ++;
					countC = 0;
					ScreenTab[countL][countC] = tmp;
				}
			} 
		}while(tmp != '\0' && tmp != EOF);
		fclose(ScreenFightFile);
		return ScreenTab;
	}
	else {
		char** error = malloc (sizeof(char *));
		error[0] = malloc(6*sizeof(char));
		error[0][0] = 'e'; 
		error[0][1] = 'r'; 
		error[0][2] = 'r'; 
		error[0][3] = 'o'; 
		error[0][4] = 'r'; 
		error[0][5] = '\0';
		return error; 
	}
}
char ** addMonster(char ** screenFight,char monster[]){
	int x = 16;
	int y = 43;
	if(strcomp2(monster,"spider" )){
		screenFight[5][81] = '(';
		screenFight[6][82] = ')';
		screenFight[7][81] = '(';
		screenFight[8][74] = '/';
		screenFight[8][75] = '\\';
		screenFight[8][78] = '.';
		screenFight[8][79] = '-';
		screenFight[8][80] = '"';
		screenFight[8][81] = '"';
		screenFight[8][82] = '"';
		screenFight[8][83] = '-';
		screenFight[8][84] = '.';
		screenFight[8][87] = '/';
		screenFight[8][88] = '\\';
		screenFight[9][73] = '/';
		screenFight[9][74] = '/';
		screenFight[9][75] = '\\';
		screenFight[9][76] = '\\';
		screenFight[9][77] = '/';
		screenFight[9][81] = '.';
		screenFight[9][82] = '.';
		screenFight[9][83] = '.';
		screenFight[9][85] = '\\';
		screenFight[9][86] = '/';
		screenFight[9][87] = '/';
		screenFight[9][88] = '\\';
		screenFight[9][89] = '\\';
		screenFight[10][73] = '|';
		screenFight[10][74] = '/';
		screenFight[10][75] = '\\';
		screenFight[10][76] = '|';
		screenFight[10][78] = ',';
		screenFight[10][79] = ';';
		screenFight[10][80] = ';';
		screenFight[10][81] = ';';
		screenFight[10][82] = ';';
		screenFight[10][83] = ';';
		screenFight[10][84] = ',';
		screenFight[10][86] = '|';
		screenFight[10][87] = '/';
		screenFight[10][88] = '\\';
		screenFight[10][89] = '|';
		screenFight[11][73] = '/';
		screenFight[11][74] = '/';
		screenFight[11][75] = '\\';
		screenFight[11][76] = '\\';
		screenFight[11][77] = '\\';
		screenFight[11][78] = ';';
		screenFight[11][79] = '-';
		screenFight[11][80] = '"';
		screenFight[11][81] = '"';
		screenFight[11][82] = '"';
		screenFight[11][83] = '-';
		screenFight[11][84] = ';';
		screenFight[11][85] = '/';
		screenFight[11][86] = '/';
		screenFight[11][87] = '/';
		screenFight[11][88] = '\\';
		screenFight[11][89] = '\\';
		screenFight[12][72] = '/';
		screenFight[12][73] = '/';
		screenFight[12][76] = '\\';
		screenFight[12][77] = '/';
		screenFight[12][81] = '.';
		screenFight[12][85] = '\\';
		screenFight[12][86] = '/';
		screenFight[12][89] = '\\';
		screenFight[12][90] = '\\';
		screenFight[13][71] = '(';
		screenFight[13][72] = '|';
		screenFight[13][74] = ',';
		screenFight[13][75] = '-';
		screenFight[13][76] = '_';
		screenFight[13][77] = '|';
		screenFight[13][79] = '\\';
		screenFight[13][81] = '|';
		screenFight[13][83] = '/';
		screenFight[13][85] = '|';
		screenFight[13][86] = '_';
		screenFight[13][87] = '-';
		screenFight[13][88] = ',';
		screenFight[13][90] = '|';
		screenFight[13][91] = ')';
		screenFight[14][73] = '/';
		screenFight[14][74] = '/';
		screenFight[14][75] = '\\';
		screenFight[14][76] = '_';
		screenFight[14][77] = '_';
		screenFight[14][78] = '\\';
		screenFight[14][79] = '.';
		screenFight[14][80] = '-';
		screenFight[14][81] = '.';
		screenFight[14][82] = '-';
		screenFight[14][83] = '.';
		screenFight[14][84] = '/';
		screenFight[14][85] = '_';
		screenFight[14][86] = '_';
		screenFight[14][87] = '`';
		screenFight[14][88] = '\\';
		screenFight[14][89] = '\\';
		screenFight[15][72] = '/';
		screenFight[15][73] = '/';
		screenFight[15][75] = '/';
		screenFight[15][76] = '.';
		screenFight[15][77] = '-';
		screenFight[15][78] = '(';
		screenFight[15][79] = '(';
		screenFight[15][80] = ')';
		screenFight[15][82] = '(';
		screenFight[15][83] = ')';
		screenFight[15][84] = ')';
		screenFight[15][85] = '-';
		screenFight[15][86] = '.';
		screenFight[15][87] = '\\';
		screenFight[15][89] = '\\';
		screenFight[15][90] = '\\';
		screenFight[16][71] = '(';
		screenFight[16][72] = '\\';
		screenFight[16][74] = '|';
		screenFight[16][75] = ')';
		screenFight[16][79] = '`';
		screenFight[16][80] = '-';
		screenFight[16][81] = '-';
		screenFight[16][82] = '-';
		screenFight[16][83] = '`';
		screenFight[16][87] = '(';
		screenFight[16][88] = '|';
		screenFight[16][90] = '/';
		screenFight[16][91] = ')';
		screenFight[17][74] = '(';
		screenFight[17][75] = '|';
		screenFight[17][87] = '|';
		screenFight[17][88] = ')';
		screenFight[18][74] = '\\';
		screenFight[18][75] = ')';
		screenFight[18][87] = '(';
		screenFight[18][88] = '/';		

	}else{
		screenFight[x][y]= 't';
	}
	return screenFight;
}
void printScreenFight(char ** ScreenTab){

	system("clear");
	int i = 0;
	while( i < 35 ){
		int j = 0 ;
		while ( j < 96 ){
				printf("%c",ScreenTab[i][j]);	
			j++ ;
		}
		i++;
	}

}
	
char actionUserFight() {
	int boolean = 0;
	char action;
	while (boolean == 0) {
		scanf("%c",&action);
		if(action == '1' || action == '2' || action == '3' || action == '4' || action == 'o'|| action == 'f') {
			boolean = 1;
		}
	}
	return action;	
}
void traitementAction(char action,Character * user,Monster* monster){
	int spell = 0;
	action = atoi(&action);
	if(action == 1){
		if ( strcomp2(user->className,"Warrior")) {
			if(user->lvl > 0 && user->lvl <=10) {
				spell = 30 + (user->strenght);
			}
			else if(user->lvl >10 && user->lvl <= 20) {
				spell = 40 +(user->strenght);
			}
			else if(user->lvl >20 && user->lvl <= 30) {
				spell = 50 + (user->strenght);
			}
			else if(user->lvl >30 && user->lvl <= 40) {
				spell = 60 + (user->strenght);
			}
			else if(user->lvl >40 && user->lvl <= 50) {
				spell = 70 + (user->strenght);
			}
			else if(user->lvl >50 && user->lvl <= 60) {
				spell = 80 + (user->strenght);
			}
		}else if(strcomp2(user->className,"Mage")){
			if(user->lvl >=0 && user->lvl <=10) {
				spell = 30 + (user->intellect);
			}
			else if(user->lvl >10 && user->lvl <= 20) {
				spell = 40 +(user->intellect);
			}
			else if(user->lvl >20 && user->lvl <= 30) {
				spell = 50 + (user->intellect);
			}
			else if(user->lvl >30 && user->lvl <= 40) {
				spell = 60 + (user->intellect);
			}
			else if(user->lvl >40 && user->lvl <= 50) {
				spell = 70 + (user->intellect);
			}
			else if(user->lvl >50 && user->lvl <= 60) {
				spell = 80 + (user->intellect);
			}

		}else if(strcomp2(user->className,"Rogue")){
			if(user->lvl >=0 && user->lvl <=10) {
				spell = 30 + (user->agility);
			}
			else if(user->lvl >10 && user->lvl <= 20) {
				spell = 40 +(user->agility);
			}
			else if(user->lvl >20 && user->lvl <= 30) {
				spell = 50 + (user->agility);
			}
			else if(user->lvl >30 && user->lvl <= 40) {
				spell = 60 + (user->agility);
			}
			else if(user->lvl >40 && user->lvl <= 50) {
				spell = 70 + (user->agility);
			}
			else if(user->lvl >50 && user->lvl <= 60) {
				spell = 80 + (user->agility);
			}
		}	
	}
	else if(action == 2){
		if ( strcomp2(user->className,"Warrior")) {
			if(user->lvl >=0 && user->lvl <=10) {
				spell = 30 + (user->strenght);
			}
			else if(user->lvl >10 && user->lvl <= 20) {
				spell = 40 +(user->strenght);
			}
			else if(user->lvl >20 && user->lvl <= 30) {
				spell = 50 + (user->strenght);
			}
			else if(user->lvl >30 && user->lvl <= 40) {
				spell = 60 + (user->strenght);
			}
			else if(user->lvl >40 && user->lvl <= 50) {
				spell = 70 + (user->strenght);
			}
			else if(user->lvl >50 && user->lvl <= 60) {
				spell = 80 + (user->strenght);
			}
		}else if(strcomp2(user->className,"Mage")){
			if(user->lvl >=0 && user->lvl <=10) {
				spell = 30 + (user->intellect);
			}
			else if(user->lvl >10 && user->lvl <= 20) {
				spell = 40 +(user->intellect);
			}
			else if(user->lvl >20 && user->lvl <= 30) {
				spell = 50 + (user->intellect);
			}
			else if(user->lvl >30 && user->lvl <= 40) {
				spell = 60 + (user->intellect);
			}
			else if(user->lvl >40 && user->lvl <= 50) {
				spell = 70 + (user->intellect);
			}
			else if(user->lvl >50 && user->lvl <= 60) {
				spell = 80 + (user->intellect);
			}

		}else if(strcomp2(user->className,"Rogue")){
			if(user->lvl >=0 && user->lvl <=10) {
				spell = 30 + (user->agility);
			}
			else if(user->lvl >10 && user->lvl <= 20) {
				spell = 40 +(user->agility);
			}
			else if(user->lvl >20 && user->lvl <= 30) {
				spell = 50 + (user->agility);
			}
			else if(user->lvl >30 && user->lvl <= 40) {
				spell = 60 + (user->agility);
			}
			else if(user->lvl >40 && user->lvl <= 50) {
				spell = 70 + (user->agility);
			}
			else if(user->lvl >50 && user->lvl <= 60) {
				spell = 80 + (user->agility);
			}
		}	
	}
	else if(action == 3){
		if ( strcomp2(user->className,"Warrior")) {
			if(user->lvl >=0 && user->lvl <=10) {
				spell = 30 + (user->strenght);
			}
			else if(user->lvl >10 && user->lvl <= 20) {
				spell = 40 +(user->strenght);
			}
			else if(user->lvl >20 && user->lvl <= 30) {
				spell = 50 + (user->strenght);
			}
			else if(user->lvl >30 && user->lvl <= 40) {
				spell = 60 + (user->strenght);
			}
			else if(user->lvl >40 && user->lvl <= 50) {
				spell = 70 + (user->strenght);
			}
			else if(user->lvl >50 && user->lvl <= 60) {
				spell = 80 + (user->strenght);
			}
		}else if(strcomp2(user->className,"Mage")){
			if(user->lvl >=0 && user->lvl <=10) {
				spell = 30 + (user->intellect);
			}
			else if(user->lvl >10 && user->lvl <= 20) {
				spell = 40 +(user->intellect);
			}
			else if(user->lvl >20 && user->lvl <= 30) {
				spell = 50 + (user->intellect);
			}
			else if(user->lvl >30 && user->lvl <= 40) {
				spell = 60 + (user->intellect);
			}
			else if(user->lvl >40 && user->lvl <= 50) {
				spell = 70 + (user->intellect);
			}
			else if(user->lvl >50 && user->lvl <= 60) {
				spell = 80 + (user->intellect);
			}

		}else if(strcomp2(user->className,"Rogue")){
			if(user->lvl >=0 && user->lvl <=10) {
				spell = 30 + (user->agility);
			}
			else if(user->lvl >10 && user->lvl <= 20) {
				spell = 40 +(user->agility);
			}
			else if(user->lvl >20 && user->lvl <= 30) {
				spell = 50 + (user->agility);
			}
			else if(user->lvl >30 && user->lvl <= 40) {
				spell = 60 + (user->agility);
			}
			else if(user->lvl >40 && user->lvl <= 50) {
				spell = 70 + (user->agility);
			}
			else if(user->lvl >50 && user->lvl <= 60) {
				spell = 80 + (user->agility);
			}
		}	
	}
	else if(action == 4){
		if ( strcomp2(user->className,"Warrior")) {
			if(user->lvl >=0 && user->lvl <=10) {
				spell = 30 + (user->strenght);
			}
			else if(user->lvl >10 && user->lvl <= 20) {
				spell = 40 +(user->strenght);
			}
			else if(user->lvl >20 && user->lvl <= 30) {
				spell = 50 + (user->strenght);
			}
			else if(user->lvl >30 && user->lvl <= 40) {
				spell = 60 + (user->strenght);
			}
			else if(user->lvl >40 && user->lvl <= 50) {
				spell = 70 + (user->strenght);
			}
			else if(user->lvl >50 && user->lvl <= 60) {
				spell = 80 + (user->strenght);
			}
		}else if(strcomp2(user->className,"Mage")){
			if(user->lvl >=0 && user->lvl <=10) {
				spell = 30 + (user->intellect);
			}
			else if(user->lvl >10 && user->lvl <= 20) {
				spell = 40 +(user->intellect);
			}
			else if(user->lvl >20 && user->lvl <= 30) {
				spell = 50 + (user->intellect);
			}
			else if(user->lvl >30 && user->lvl <= 40) {
				spell = 60 + (user->intellect);
			}
			else if(user->lvl >40 && user->lvl <= 50) {
				spell = 70 + (user->intellect);
			}
			else if(user->lvl >50 && user->lvl <= 60) {
				spell = 80 + (user->intellect);
			}

		}else if(strcomp2(user->className,"Rogue")){
			if(user->lvl >=0 && user->lvl <=10) {
				spell = 30 + (user->agility);
			}
			else if(user->lvl >10 && user->lvl <= 20) {
				spell = 40 +(user->agility);
			}
			else if(user->lvl >20 && user->lvl <= 30) {
				spell = 50 + (user->agility);
			}
			else if(user->lvl >30 && user->lvl <= 40) {
				spell = 60 + (user->agility);
			}
			else if(user->lvl >40 && user->lvl <= 50) {
				spell = 70 + (user->agility);
			}
			else if(user->lvl >50 && user->lvl <= 60) {
				spell = 80 + (user->agility);
			}
		}	
	}
	spell = spell - monster->def;
	monster->hp = monster->hp - spell;
}
void printBottom(Character * user){
	if ( strcomp2(user->className,"Warrior")){
		if(user->lvl >0 && user->lvl <=10){
			printf("***********************************************************************************************\n");
			printf("**                                                       |    f.Fuite                         *\n");
			printf("** 1.Frape heroic                                        |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("***********************************************************************************************\n");

		}
		if(user->lvl >10 && user->lvl <=20){
			printf("***********************************************************************************************\n");
			printf("**                                                       |    f.Fuite                         *\n");
			printf("** 1.Frape heroic            2.Fulgurance                |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("***********************************************************************************************\n");

		}
		if(user->lvl >20 && user->lvl <=30){
			printf("***********************************************************************************************\n");
			printf("**                                                       |    f.Fuite                         *\n");
			printf("** 1.Frappe heroic            2.Fulgurance               |                                    *\n");
			printf("** 3.Frappe du collosse                                  |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("***********************************************************************************************\n");

		}
		if(user->lvl >30){
			printf("***********************************************************************************************\n");
			printf("**                                                       |    f.Fuite                         *\n");
			printf("** 1.Frape heroic             2.Fulgurance               |                                    *\n");
			printf("** 3.Frappe du colosse        4.Frappe Executrice        |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("***********************************************************************************************\n");

		}
	}
	if ( strcomp2(user->className,"Rogue")){
		if(user->lvl >0 && user->lvl <=10){
			printf("***********************************************************************************************\n");
			printf("**                                                       |    f.Fuite                         *\n");
			printf("** 1.Embuche                                             |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("***********************************************************************************************\n");

		}
		if(user->lvl >10 && user->lvl <=20){
			printf("***********************************************************************************************\n");
			printf("**                                                       |    f.Fuite                         *\n");
			printf("** 1.Embuche            2.Coup bas                       |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("***********************************************************************************************\n");

		}
		if(user->lvl >20 && user->lvl <=30){
			printf("***********************************************************************************************\n");
			printf("**                                                       |    f.Fuite                         *\n");
			printf("** 1.Embuche            2.Coup bas                       |                                    *\n");
			printf("** 3.Suriner                                             |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("***********************************************************************************************\n");

		}
		if(user->lvl >30){
			printf("***********************************************************************************************\n");
			printf("**                                                       |    f.Fuite                         *\n");
			printf("** 1.Embuche                  2.Coup bas                 |                                    *\n");
			printf("** 3.Suriner                  4.Saignement               |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("***********************************************************************************************\n");

		}
	}
	if ( strcomp2(user->className,"Mage")){
		if(user->lvl >0 && user->lvl <=10){
			printf("***********************************************************************************************\n");
			printf("**                                                       |    f.Fuite                         *\n");
			printf("** 1.Boule de feu                                        |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("***********************************************************************************************\n");

		}
		if(user->lvl >10 && user->lvl <=20){
			printf("***********************************************************************************************\n");
			printf("**                                                       |    f.Fuite                         *\n");
			printf("** 1.Boule de feu            2.Trait de givre            |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("***********************************************************************************************\n");

		}
		if(user->lvl >20 && user->lvl <=30){
			printf("***********************************************************************************************\n");
			printf("**                                                       |    f.Fuite                         *\n");
			printf("** 1.Boule de feu            2.Trait de givre            |                                    *\n");
			printf("** 3.Pluie de glace                                      |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("***********************************************************************************************\n");

		}
		if(user->lvl >30){
			printf("***********************************************************************************************\n");
			printf("**                                                       |    f.Fuite                         *\n");
			printf("** 1.Boule de feu             2.Trait de givre           |                                    *\n");
			printf("** 3.Pluie de glace           4.Explosion des arcades    |                                    *\n");
			printf("**                                                       |                                    *\n");
			printf("***********************************************************************************************\n");

		}
		}
}
void bot(Monster * monster, Character * user ){
	user->hp = user->hp - monster->attack;	
}
void flashMonster(char** screenFight,Monster* monster,Character* user) {
	if(strcomp2(monster->name,"spider" )){
		screenFight[5][81] = ' ';
		screenFight[6][82] = ' ';
		screenFight[7][81] = ' ';
		screenFight[8][74] = ' ';
		screenFight[8][75] = ' ';
		screenFight[8][78] = ' ';
		screenFight[8][79] = ' ';
		screenFight[8][80] = ' ';
		screenFight[8][81] = ' ';
		screenFight[8][82] = ' ';
		screenFight[8][83] = ' ';
		screenFight[8][84] = ' ';
		screenFight[8][87] = ' ';
		screenFight[8][88] = ' ';
		screenFight[9][73] = ' ';
		screenFight[9][74] = ' ';
		screenFight[9][75] = ' ';
		screenFight[9][76] = ' ';
		screenFight[9][77] = ' ';
		screenFight[9][81] = ' ';
		screenFight[9][82] = ' ';
		screenFight[9][83] = ' ';
		screenFight[9][85] = ' ';
		screenFight[9][86] = ' ';
		screenFight[9][87] = ' ';
		screenFight[9][88] = ' ';
		screenFight[9][89] = ' ';
		screenFight[10][73] = ' ';
		screenFight[10][74] = ' ';
		screenFight[10][75] = ' ';
		screenFight[10][76] = ' ';
		screenFight[10][78] = ' ';
		screenFight[10][79] = ' ';
		screenFight[10][80] = ' ';
		screenFight[10][81] = ' ';
		screenFight[10][82] = ' ';
		screenFight[10][83] = ' ';
		screenFight[10][84] = ' ';
		screenFight[10][86] = ' ';
		screenFight[10][87] = ' ';
		screenFight[10][88] = ' ';
		screenFight[10][89] = ' ';
		screenFight[11][73] = ' ';
		screenFight[11][74] = ' ';
		screenFight[11][75] = ' ';
		screenFight[11][76] = ' ';
		screenFight[11][77] = ' ';
		screenFight[11][78] = ' ';
		screenFight[11][79] = ' ';
		screenFight[11][80] = ' ';
		screenFight[11][81] = ' ';
		screenFight[11][82] = ' ';
		screenFight[11][83] = ' ';
		screenFight[11][84] = ' ';
		screenFight[11][85] = ' ';
		screenFight[11][86] = ' ';
		screenFight[11][87] = ' ';
		screenFight[11][88] = ' ';
		screenFight[11][89] = ' ';
		screenFight[12][72] = ' ';
		screenFight[12][73] = ' ';
		screenFight[12][76] = ' ';
		screenFight[12][77] = ' ';
		screenFight[12][81] = ' ';
		screenFight[12][85] = ' ';
		screenFight[12][86] = ' ';
		screenFight[12][89] = ' ';
		screenFight[12][90] = ' ';
		screenFight[13][71] = ' ';
		screenFight[13][72] = ' ';
		screenFight[13][74] = ' ';
		screenFight[13][75] = ' ';
		screenFight[13][76] = ' ';
		screenFight[13][77] = ' ';
		screenFight[13][79] = ' ';
		screenFight[13][81] = ' ';
		screenFight[13][83] = ' ';
		screenFight[13][85] = ' ';
		screenFight[13][86] = ' ';
		screenFight[13][87] = ' ';
		screenFight[13][88] = ' ';
		screenFight[13][90] = ' ';
		screenFight[13][91] = ' ';
		screenFight[14][73] = ' ';
		screenFight[14][74] = ' ';
		screenFight[14][75] = ' ';
		screenFight[14][76] = ' ';
		screenFight[14][77] = ' ';
		screenFight[14][78] = ' ';
		screenFight[14][79] = ' ';
		screenFight[14][80] = ' ';
		screenFight[14][81] = ' ';
		screenFight[14][82] = ' ';
		screenFight[14][83] = ' ';
		screenFight[14][84] = ' ';
		screenFight[14][85] = ' ';
		screenFight[14][86] = ' ';
		screenFight[14][87] = ' ';
		screenFight[14][88] = ' ';
		screenFight[14][89] = ' ';
		screenFight[15][72] = ' ';
		screenFight[15][73] = ' ';
		screenFight[15][75] = ' ';
		screenFight[15][76] = ' ';
		screenFight[15][77] = ' ';
		screenFight[15][78] = ' ';
		screenFight[15][79] = ' ';
		screenFight[15][80] = ' ';
		screenFight[15][82] = ' ';
		screenFight[15][83] = ' ';
		screenFight[15][84] = ' ';
		screenFight[15][85] = ' ';
		screenFight[15][86] = ' ';
		screenFight[15][87] = ' ';
		screenFight[15][89] = ' ';
		screenFight[15][90] = ' ';
		screenFight[16][71] = ' ';
		screenFight[16][72] = ' ';
		screenFight[16][74] = ' ';
		screenFight[16][75] = ' ';
		screenFight[16][79] = ' ';
		screenFight[16][80] = ' ';
		screenFight[16][81] = ' ';
		screenFight[16][82] = ' ';
		screenFight[16][83] = ' ';
		screenFight[16][87] = ' ';
		screenFight[16][88] = ' ';
		screenFight[16][90] = ' ';
		screenFight[16][91] = ' ';
		screenFight[17][74] = ' ';
		screenFight[17][75] = ' ';
		screenFight[17][87] = ' ';
		screenFight[17][88] = ' ';
		screenFight[18][74] = ' ';
		screenFight[18][75] = ' ';
		screenFight[18][87] = ' ';
		screenFight[18][88] = ' ';
		printScreenFight(screenFight);
		printBottom(user);		
		system("sleep 1");
		addMonster(screenFight, monster->name);
	
		}
}
void printHp(char ** screenFight,Character * user,Monster * monster){
	int ratioHpMonster = ( monster->hp *100) / monster->hpMax;
	screenFight[3][34]='-';
	screenFight[3][35]='-';
	screenFight[3][36]='-';
	screenFight[3][37]='-';
	screenFight[3][38]='-';
	screenFight[3][39]='-';
	screenFight[3][40]='-';
	screenFight[3][41]='-';
	screenFight[3][42]='-';
	screenFight[3][43]='-';
	screenFight[3][44]='-';
	screenFight[3][45]='-';
	screenFight[4][34]='|';
	screenFight[4][45]='|';
	screenFight[5][34]='-';
	screenFight[5][35]='-';
	screenFight[5][36]='-';
	screenFight[5][37]='-';
	screenFight[5][38]='-';
	screenFight[5][39]='-';
	screenFight[5][40]='-';
	screenFight[5][41]='-';
	screenFight[5][42]='-';
	screenFight[5][43]='-';
	screenFight[5][44]='-';
	screenFight[5][45]='-';
	if (ratioHpMonster > 0 && ratioHpMonster <= 10){

		screenFight[4][35]='#';
		screenFight[4][36]=' ';
		screenFight[4][37]=' ';
		screenFight[4][38]=' ';
		screenFight[4][39]=' ';
		screenFight[4][40]=' ';
		screenFight[4][41]=' ';
		screenFight[4][42]=' ';
		screenFight[4][43]=' ';
		screenFight[4][44]=' ';
	}else if (ratioHpMonster > 10 && ratioHpMonster <= 20){
		screenFight[4][35]='#';
		screenFight[4][36]='#';
		screenFight[4][37]=' ';
		screenFight[4][38]=' ';
		screenFight[4][39]=' ';
		screenFight[4][40]=' ';
		screenFight[4][41]=' ';
		screenFight[4][42]=' ';
		screenFight[4][43]=' ';
		screenFight[4][44]=' ';

	}else if (ratioHpMonster > 20 && ratioHpMonster <= 30){
		screenFight[4][35]='#';
		screenFight[4][36]='#';
		screenFight[4][37]='#';
		screenFight[4][38]=' ';
		screenFight[4][39]=' ';
		screenFight[4][40]=' ';
		screenFight[4][41]=' ';
		screenFight[4][42]=' ';
		screenFight[4][43]=' ';
		screenFight[4][44]=' ';
	
	}else if (ratioHpMonster > 30 && ratioHpMonster <= 40){
		screenFight[4][35]='#';
		screenFight[4][36]='#';
		screenFight[4][37]='#';
		screenFight[4][38]='#';
		screenFight[4][39]=' ';
		screenFight[4][40]=' ';
		screenFight[4][41]=' ';
		screenFight[4][43]=' ';
		screenFight[4][44]=' ';
	}else if (ratioHpMonster > 40 && ratioHpMonster <= 50){
		screenFight[4][35]='#';
		screenFight[4][36]='#';
		screenFight[4][37]='#';
		screenFight[4][38]='#';
		screenFight[4][39]='#';
		screenFight[4][40]=' ';
		screenFight[4][41]=' ';
		screenFight[4][42]=' ';
		screenFight[4][43]=' ';
		screenFight[4][44]=' ';
	}else if (ratioHpMonster > 50 && ratioHpMonster <= 60){
		screenFight[4][35]='#';
		screenFight[4][36]='#';
		screenFight[4][37]='#';
		screenFight[4][38]='#';
		screenFight[4][39]='#';
		screenFight[4][40]='#';
		screenFight[4][41]=' ';
		screenFight[4][42]=' ';
		screenFight[4][43]=' ';
		screenFight[4][44]=' ';
	}else if (ratioHpMonster > 60 && ratioHpMonster <= 70){
		screenFight[4][35]='#';
		screenFight[4][36]='#';
		screenFight[4][37]='#';
		screenFight[4][38]='#';
		screenFight[4][39]='#';
		screenFight[4][40]='#';
		screenFight[4][41]='#';
		screenFight[4][42]=' ';
		screenFight[4][43]=' ';
		screenFight[4][44]=' ';
	}else if (ratioHpMonster > 70 && ratioHpMonster <= 80){
		screenFight[4][35]='#';
		screenFight[4][36]='#';
		screenFight[4][37]='#';
		screenFight[4][38]='#';
		screenFight[4][39]='#';
		screenFight[4][40]='#';
		screenFight[4][41]='#';
		screenFight[4][42]='#';
		screenFight[4][43]=' ';
		screenFight[4][44]=' ';
	}else if (ratioHpMonster > 80 && ratioHpMonster <= 90){
		screenFight[4][35]='#';
		screenFight[4][36]='#';
		screenFight[4][37]='#';
		screenFight[4][38]='#';
		screenFight[4][39]='#';
		screenFight[4][40]='#';
		screenFight[4][41]='#';
		screenFight[4][42]='#';
		screenFight[4][43]='#';
		screenFight[4][44]=' ';
	}else if (ratioHpMonster > 90 && ratioHpMonster <= 100){
		screenFight[4][35]='#';
		screenFight[4][36]='#';
		screenFight[4][37]='#';
		screenFight[4][38]='#';
		screenFight[4][39]='#';
		screenFight[4][40]='#';
		screenFight[4][41]='#';
		screenFight[4][42]='#';
		screenFight[4][43]='#';
		screenFight[4][44]='#';
		}
	int ratioHpUser = ( user->hp *100) / user->hpMax;
	screenFight[29][67]='-';
	screenFight[29][68]='-';
	screenFight[29][69]='-';
	screenFight[29][70]='-';
	screenFight[29][71]='-';
	screenFight[29][72]='-';
	screenFight[29][73]='-';
	screenFight[29][74]='-';
	screenFight[29][75]='-';
	screenFight[29][76]='-';
	screenFight[29][77]='-';
	screenFight[30][64]='P';
	screenFight[30][65]='V';
	screenFight[30][66]=':';
	screenFight[30][67]='|';
	screenFight[30][77]='|';
	screenFight[31][67]='-';
	screenFight[31][68]='-';
	screenFight[31][69]='-';
	screenFight[31][70]='-';
	screenFight[31][71]='-';
	screenFight[31][72]='-';
	screenFight[31][73]='-';
	screenFight[31][74]='-';
	screenFight[31][75]='-';
	screenFight[31][76]='-';
	screenFight[31][77]='-';
	if (ratioHpUser > 0 && ratioHpUser <= 10){
		screenFight[30][68]=' ';
		screenFight[30][69]=' ';
		screenFight[30][70]=' ';
		screenFight[30][71]=' ';
		screenFight[30][72]=' ';
		screenFight[30][73]=' ';
		screenFight[30][74]=' ';
		screenFight[30][75]=' ';
		screenFight[30][76]=' ';
	}else if (ratioHpUser > 10 && ratioHpUser <= 20){
		screenFight[30][68]='#';
		screenFight[30][69]=' ';
		screenFight[30][70]=' ';
		screenFight[30][71]=' ';
		screenFight[30][72]=' ';
		screenFight[30][73]=' ';
		screenFight[30][74]=' ';
		screenFight[30][75]=' ';
		screenFight[30][76]=' ';

	}else if (ratioHpUser > 20 && ratioHpUser <= 30){
		screenFight[30][68]='#';
		screenFight[30][69]='#';
		screenFight[30][70]=' ';
		screenFight[30][71]=' ';
		screenFight[30][72]=' ';
		screenFight[30][73]=' ';
		screenFight[30][74]=' ';
		screenFight[30][75]=' ';
		screenFight[30][76]=' ';
	
	}else if (ratioHpUser > 30 && ratioHpUser <= 40){
		screenFight[30][68]='#';
		screenFight[30][69]='#';
		screenFight[30][70]='#';
		screenFight[30][71]=' ';
		screenFight[30][72]=' ';
		screenFight[30][73]=' ';
		screenFight[30][74]=' ';
		screenFight[30][75]=' ';
		screenFight[30][76]=' ';
	}else if (ratioHpUser > 40 && ratioHpUser <= 50){
		screenFight[30][68]='#';
		screenFight[30][69]='#';
		screenFight[30][70]='#';
		screenFight[30][71]='#';
		screenFight[30][72]=' ';
		screenFight[30][73]=' ';
		screenFight[30][74]=' ';
		screenFight[30][75]=' ';
		screenFight[30][76]=' ';
	}else if (ratioHpUser > 50 && ratioHpUser <= 60){
		screenFight[30][68]='#';
		screenFight[30][69]='#';
		screenFight[30][70]='#';
		screenFight[30][71]='#';
		screenFight[30][72]='#';
		screenFight[30][73]=' ';
		screenFight[30][74]=' ';
		screenFight[30][75]=' ';
		screenFight[30][76]=' ';
	}else if (ratioHpUser > 60 && ratioHpUser <= 70){
		screenFight[30][68]='#';
		screenFight[30][69]='#';
		screenFight[30][70]='#';
		screenFight[30][71]='#';
		screenFight[30][72]='#';
		screenFight[30][73]='#';
		screenFight[30][74]=' ';
		screenFight[30][75]=' ';
		screenFight[30][76]=' ';
	}else if (ratioHpUser > 70 && ratioHpUser <= 80){
		screenFight[30][68]='#';
		screenFight[30][69]='#';
		screenFight[30][70]='#';
		screenFight[30][71]='#';
		screenFight[30][72]='#';
		screenFight[30][73]='#';
		screenFight[30][74]='#';
		screenFight[30][75]=' ';
		screenFight[30][76]=' ';
	}else if (ratioHpUser > 80 && ratioHpUser <= 90){
		screenFight[30][68]='#';
		screenFight[30][69]='#';
		screenFight[30][70]='#';
		screenFight[30][71]='#';
		screenFight[30][72]='#';
		screenFight[30][73]='#';
		screenFight[30][74]='#';
		screenFight[30][75]='#';
		screenFight[30][76]=' ';
	}else if (ratioHpUser > 90 && ratioHpUser <= 100){
		screenFight[30][68]='#';
		screenFight[30][69]='#';
		screenFight[30][70]='#';
		screenFight[30][71]='#';
		screenFight[30][72]='#';
		screenFight[30][73]='#';
		screenFight[30][74]='#';
		screenFight[30][75]='#';
		screenFight[30][76]='#';
		}
/*	printf("*       ----------                                                                            *\n");
	printf("* HP : |"); 
	int nbLife;
	for (nbLife=0; nbLife<ratioHP/10; nbLife++)
		printf("#");
	for (nbLife=0; nbLife<10 - (ratioHP/10); nbLife++)
                printf(" ");
	printf("|                                                                           *\n");
	printf("*       ----------                                                                            *\n");

*/
}
void fight (Character * user){
	char action = ' ';  
	int alea = rand()%1;
	Monster * monster;
  	if(alea == 0){
		monster = getSpider();
  	}else{
		monster = getOther();
  	}
  	char ** screenFight = getScreenFight();
	if(screenFight[0][0] =='e' && screenFight[0][1] == 'r' && screenFight[0][2] == 'r' && screenFight[0][3] == 'o' && screenFight[0][4] == 'r') {
		printf("ERROR\n");
		return;
	}
	else {
		while(monster->hp > 0 && user->hp > 0 && action != 'f'){
  			addMonster(screenFight,monster->name);
			printHp(screenFight,user,monster);
  			printScreenFight(screenFight);
			printBottom(user);
   			action = actionUserFight();
			if(action != 'f'){
  				traitementAction(action,user,monster);
				flashMonster(screenFight,monster,user);
				printHp(screenFight,user,monster);
  				printScreenFight(screenFight);
				printBottom(user);
				system("sleep 1");	
				bot(monster,user);
			}
		}
	}	
}
  
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
char * getDialog (char nameTxt[]) {
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
			if(tmp == ';' && count < 14) {
				count ++;
			} 
			else {
				if(count == 14 && tmp != ';') {	
					map[i] = tmp;
					i++;
				}else if(count == 14 && tmp == ';') {
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
void printTop(Character * user) {
	/*FILE * character = fopen(nameTxt,"r");
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
	}*/
	int ratioHP = ( user->hp *100) / user->hpMax;
	int nbCharName = 0;
	while (user->name[nbCharName] != '\0') {
		nbCharName ++;
	}
	printf("***********************************************************************************************\n");
	printf("*                                                                                             *\n");
	printf("* Name : %s",user->name);
	int j;
	for(j=10; j> nbCharName ;j--) printf(" ");
	printf("                                                                  LvL : %d",user->lvl);
	//int nbCharlvlMax; 
	//for(nbCharlvlMax=2; nbCharlvlMax > countNbCharLvl; nbCharlvlMax --) printf(" ");
	if(user->lvl <10) {
		printf(" ");
	}
	printf(" *\n"); 
	printf("*       ----------                                                                            *\n");
	printf("* HP : |"); 
	int nbLife;
	for (nbLife=0; nbLife<ratioHP/10; nbLife++)
		printf("#");
	for (nbLife=0; nbLife<10 - (ratioHP/10); nbLife++)
                printf(" ");
	printf("|                                                                           *\n");
	printf("*       ----------                                                                            *\n");
	printf("***********************************************************************************************\n");
/*	
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
*/
}
/*
 * Fonction qui rajout ".txt" à la chaine mise en parametre
 */

char * addTxt(char chaine[]) {
	int i = 0;
	while(chaine[i] != '\0') {
		i ++;
	}
	char * chainewithtxt = malloc(i+5 * sizeof(char));

	char txt[] = ".txt";
	i = 0;
	while(chaine[i] != '\0') {
		chainewithtxt[i] = chaine[i];
		i ++;
	}
	int j = i;
	i = 0;
	while(i < 5) {
		chainewithtxt[j] = txt[i];
		i ++;
		j ++;
	}
	return chainewithtxt;
}

/*
 * Fonction qui permet de renvoyer une chaine contenant "Quest.txt" à la fin de la chaine mise en paramètre
 */
char * addQuestTxt( char chaine[]) {
	
	int i = 0;
	while(chaine[i] != '\0') {
		i ++;
	}
	char * chaineWithQuestTxt = malloc(i+9 * sizeof(char));

	char txt[] = "Quest.txt";
	i = 0;
	while(chaine[i] != '\0') {
		chaineWithQuestTxt[i] = chaine[i];
		i ++;
	}
	int j = i;
	i = 0;
	while(i < 9) {
		chaineWithQuestTxt[j] = txt[i];
		i ++;
		j ++;
	}
	chaineWithQuestTxt[j] = '\0';
	return chaineWithQuestTxt;

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

/*
 * FOnction qui permet d'afficher la demande du nom du personnage
 */
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
					int c = 0;
					while(names[t][c] != '\0') {
						c++;
					}
					while(names[t][j] != '\0' && diff == 0 && name[n] != '\0') {
						if( name[n] != names[t][j]) {
							diff = 1;	
						}
						j++;
						n++;
					}
					if(diff == 0 && n == c) {
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

/*
 * FOnction qui affiche toutes les classes
 */
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
 * Fonction qui permet de créer le fichier de quêtes
 */

void creatQuest( char name[]) {
	char * chaineWithQuestTxt = addQuestTxt(name);

	FILE * fileQuest = fopen(chaineWithQuestTxt,"w");
	if( fileQuest != NULL) {
		FILE * fileQuests = fopen("quests.txt","r");
		if( fileQuests != NULL) {
			char tmp[999];
	//		do {
	//			if(tmp != EOF) {
	//				fgets(tmp,-1,fileQuests);
	//				fprintf(fileQuest,"%s",tmp);
	//			}
	//		}while(tmp != EOF);
			while (fgets(tmp, 999, fileQuests))
			{
				fprintf(fileQuest, "%s", tmp);
			}
			fclose(fileQuests);
		}
		else {
			printf("ERROR OPEN QUESTS.TXT\n");
		}
		fclose(fileQuest);
	}
	else {

		printf("ERROR OPEN USERQUEST.TXT\n");
	}

	free(chaineWithQuestTxt);	

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
			fprintf(characterFile, "%s;%s;%d;%d;%d;%d;%d;%d;%d;%d;%s;%s;%d;%d;%s;\n",name,className,agility,strenght,intellect,stamina,xp,lvl,hp,hp,bag1,map,x,y,"nodial");
			fprintf(charactersFile,"%s;",name);
			/*
			 	Creer un tableau 2 dimm pour les quêtes
			*/
			creatQuest(name);
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
	char action;
	while (boolean == 0) {
		scanf("%c",&action);
		if(action == 'd' || action == 's' || action == 'q' || action == 'z' || action == 'e' || action == 'o') {
			boolean = 1;
		}
	}
	return action;	
}

/*
 * Fonction qui permet de comparer 2 chaines de characteres
 */
int strcomp2(char * str1, char * str2) {
	int equal = 1;
	int i = 0;
	while(str1[i] != '\0' && equal) {
		if(str1[i] != str2[i]) {
			equal = 0;
		}
		i ++;
	}
	return equal;
}

/* 
 * Fonction qui permet de rajouter une quête dans le fichier {name}Quest.txt du personnage 
 * Parammetre : le nom du personnage name[], le numéro de la quête, le text contenant la mission de la quête, 
 *              le nbStart (surtout pour les quêtes demandant un nombre de chose) 0 souvant lorsque l'on commence la quête
 *              et pour finir nbEnd pour dire à cb de chose la quête se termine
 */ 
void addQuest(char name[],int nb,char chaine[],char nbStart[], char nbEnd[]) {
	char * nameWithQuestTxt = addQuestTxt(name);
	FILE * questFile = fopen (nameWithQuestTxt, "a");
	if(questFile != NULL) {
		fprintf(questFile,"%d;%s;%s;%s\n",nb,chaine,nbStart,nbEnd);
		fclose(questFile);

	}else {
		printf("ERROR QUEST FILE");
	}

}

void printDialog(char dialogName[], char name[],Quest* quests) {
		printf("On est dans la fonction printDial dial : %s\n",dialogName);
		if(strcomp2(dialogName,"dialoguemaison1a")) {
			printf("il detect que c'est le dialogue de la premier maison\n");
			int nbCharName = 0;
			while (name[nbCharName] != '\0') {
				nbCharName ++;
			}
			//char * testQuestMission = getQuestMission(name,6);
			//printf("QuestMission : %s  \n",testQuestMission);
			printf("***********************************************************************************************\n");
			printf("* Bonjour  %s,",name);
			int j;
			for(j=10; j> nbCharName ;j--) printf(" ");
			printf("                                                                        *\n");
			printf("*J'ai besoin de votre aide, une invasion de monstre est apparue dans les herdes,              *\n");
			printf("*pouvez-vous les éliminer pour moi s'il vous plaît ?                                          *\n");
			printf("***********************************************************************************************\n");
			printf("*  1. Oui pas de soucis !                  2. Non, désolé                                     *\n");
			printf("***********************************************************************************************\n");
			int tmp;
			do {
				scanf("%d",&tmp);
			}while(tmp <= 1 && tmp >= 2);
			if(tmp == 1) {
				//addQuest(name,1,"Tuez les monstres dans les hautes herbes dans startMap : ","0","10");
				quests[0].status = 1;
				printf("***********************************************************************************************\n"\
				"*  Merci, beaucoup ! A bientot !                                                              *\n");
				printf("***********************************************************************************************\n");
			}			
			else{
				printf("***********************************************************************************************\n");
				printf("*  C'est pas grâve, laissez nous mourir l'esprit serain                                       *\n");
				printf("***********************************************************************************************\n");
			}
		}	
}
/*
 * Fonction qui permet de bouger le perssonage dans le tableau map
 */
int deplacement(char action,Character * user, char ** map) {
	int x = user->x;
	int y = user->y;		
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
	}
	else if(action == 'o') {
		return 2;	
	}
	else if(action == 'e') {
		if(( map[y-1][x] == '2' 
			|| map[y-1][x-1] == '2' 
			|| map[y][x-1] == '2'
			|| map[y][x-2] == '2' 
			|| map[y+1][x-2] == '2' 
			|| map[y+2][x-2] == '2' 
			|| map[y+2][x-1] == '2' 
			|| map[y+3][x-1] == '2' 
			|| map[y+3][x] == '2'
			|| map[y+3][x+1] == '2' 
			|| map[y+2][x+1] == '2' 
			|| map[y+2][x+2] == '2' 
			|| map[y+1][x+2] == '2' 
			|| map[y][x+2] == '2' 
			|| map[y][x+1] =='2' 
			|| map[y-1][x+1] == '2' 
			 ) && strcomp2(user->map,"maison1")) {
			//setCharacter(nameTxt,"dialoguemaison1a",14);
			char dial[30] = "dialoguemaison1a";
			int i = 0;
			//while(map[i] != '\0') {
			while(map[i] != '\0') {
				user->dial[i] = dial[i];
				i++;
			}
			user->dial[i] = '\0';
			return 1;
		}
	}
	else {
		return 1;	
	}
	if ((map[y][x] == 'H' || map[y][x] == ' ') &&
		(map[y+1][x] == 'H' || map[y+1][x] == ' ') &&
			(map[y+1][x+1] == 'H' || map[y+1][x+1] == ' ') &&
				(map[y+1][x-1] == 'H' || map[y+1][x-1] == ' ') &&
					(map[y+2][x] == 'H' || map[y+2][x] == ' ')){
		/*char yIntToChar[10]; 
		sprintf(yIntToChar,"%d",y);
		char xIntToChar[10]; 
		sprintf(xIntToChar,"%d",x);
		setCharacter(nameTxt,xIntToChar,12);
		setCharacter(nameTxt,yIntToChar,13);
		setCharacter(nameTxt,"nodial",14);
		*/
		user->x = x;
		user->y = y;
		char nodial[7] = "nodial";
		int i = 0;
		while(nodial[i] != '\0') {
			user->dial[i] = nodial[i];
			i++;
		}
		user->dial[i] = '\0';
		if(map[y][x] == 'H' || map[y+1][x] == 'H' ||map[y+1][x-1] == 'H' || map[y+2][x] == 'H') {
			int alea = rand()%11;
		//	printf("%d\n",alea);
			if ( alea >=0 && alea <=3 ){
		//	printf("tu est dans le alea de deplacement\n");	
			fight(user);
				
			}
		}
		return 1;
	}
	else if((map[y][x] == '1' || map[y+1][x] == '1' ||map[y+1][x-1] == '1' || map[y+2][x] == '1') && strcomp2(user->map,"startMap")) {
		/*setCharacter(nameTxt,"maison1",11);
		setCharacter(nameTxt,"46",12);
		setCharacter(nameTxt,"29",13);
		setCharacter(nameTxt,"nodial",14);
		*/
		
		char map[30] = "maison1";
		int i = 0;
		while(map[i] != '\0') {
			user->map[i] = map[i];
			i++;
		}
		user->map[i] = '\0';
		user->x = 46;
		user->y = 29;
		return 1;
	}
	else if((map[y][x] == '1' || map[y+1][x] == '1' ||map[y+1][x-1] == '1' || map[y+2][x] == '1') && strcomp2(user->map,"maison1")) {
		/*setCharacter(nameTxt,"startMap",11);
		setCharacter(nameTxt,"32",12);
		setCharacter(nameTxt,"12",13);
		setCharacter(nameTxt,"nodial",14);
		*/
		char map[30] = "startMap";
		int i = 0;
		while(map[i] != '\0') {
			user->map[i] = map[i];
			i++;
		}
		user->map[i] = '\0';
		user->x = 32;
		user->y = 12;
		return 1;
	}
	else {
		return 1;
	}
}
/*
 * Fonction principal, celle qui va faire tourner le jeu
 */
void play(char name[]) {
	int dep;
	Character* user = getUser(name);
	char * userQuestTxt = addQuestTxt(name);
	int i =0;
	Quest quests[3];
	while(i < 2) {
		char * mission= getMissionQuest(userQuestTxt,i+1);
		char * start= getStartQuest(userQuestTxt,i+1);
		char * end= getEndQuest(userQuestTxt,i+1);
		char * status= getStatusQuest(userQuestTxt,i+1);
		int j=0;
		while(mission[j] != '\0') {
			quests[i].mission[j] =mission[j]; 
			j++;
		}
		quests[i].mission[j] = '\0';
		quests[i].start = atoi(start);
		quests[i].end = atoi(end);
		quests[i].status= atoi(status);
		i ++;
	}
	do {
		char * nameTxt = addTxt(name);
		char ** map = getMapFile(user->map);
		if(map[0][0] == 'e' && map[0][1] == 'r' && map[0][2] == 'r' && map[0][3] == 'o' && map[0][4] == 'r' ) {
			free(map[0]);
			free(map);
			//free(mapName);
			free(nameTxt);
			navigationMenu();
		}
		else {
			system("clear");
			printTop(user);
	 
			//char * xchar = user->x;
			//char * ychar = user->y;
			//int xint = atoi(xchar);
			//int yint = atoi(ychar);		
			map = mapWithMen(user->x ,user->y, map);
			printMap(map,user,quests);
			if(strcomp2(user->dial,"nodial") == 0) {
				printDialog(user->dial,user->name, quests);
			}
			char action = userAction();
			dep = deplacement(action,user,map);		
			//on clear tous les mallocs
			if(dep == 2) {
				int action;
				printMenuInGame();
				action = getActionMenuInGame();
				if(action == 0 ) {
					dep = 1;
				}
				else if (action == 1) {
					save(user,quests);
					dep = 1;
				}
				else if (action == 3) {
					save(user,quests);
				}
			}
			int i = 0;
			while(i <35) {
				free(map[i]);
				i++;
			}
			free(map);
			//free(mapName);
			free(nameTxt);
		}
	}while(dep == 1);
}

void save(Character* user, Quest* quests) {
	FILE * userFile = fopen(addTxt(user->name),"w");
	FILE * questFile = fopen(addQuestTxt(user->name),"w");
	if( userFile != NULL && questFile != NULL) {
		fprintf(userFile,"%s;%s;%d;%d;%d;%d;%d;%d;%d;%d;;%s;%d;%d;%s;",user->name,user->className,user->agility,user->strenght,user->intellect,user->stamina,user->xp,user->lvl,user->hp,user->hpMax,user->map,user->x,user->y,user->dial);	
		int i = 0;
		while(i < 2) {
			fprintf(questFile,"%d;%s;%d;%d;%d;\n",i,quests[i].mission,quests[i].start,quests[i].end,quests[i].status);
			i++;
		}
		fclose(userFile);
		fclose(questFile);
	}
	else {
		printf("ERROR OPEN FILE USERFILE OR QUESTFILE\n");
	}
}
int getActionMenuInGame() {
	int action;
	do {
		scanf("%d",&action);
	}while(action > 3 || action < 0);
	return action;	
}
void printMenuInGame() {
	system("clear");
	printf("*****************************************************\n");
        printf("*                     Menu                          *\n");
        printf("*****************************************************\n");
        printf("*               1.Sauvegarder                       *\n");
        printf("*               2.Quitter                           *\n");
        printf("*               3.Sauvegarder & quitter             *\n");
        printf("*                                                   *\n");
        printf("*                                                   *\n");
        printf("*               0.Continuer                         *\n");
        printf("*****************************************************\n");
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

void printMap(char **mapTab,Character * user,Quest* quests) {
	int i = 0;
	while( i < 35 ){
		int j = 0 ;
		while ( j < 96 ){
			if(strcomp2(user->map,"maison1")) {
				if(mapTab[i][j] == '1') {
					printf("-");
				}
				else if(mapTab[i][j] == '2') {
					printf(" ");
				}
				else if(i == 8 && j == 76) {
					//faire les tests, si quête prise , si elle est en cours ou si elle est terminée 
					//printf("!",mapTab[i][j]);
					if(quests[0].status == 0) {
						printf("!");
					}
					else if(quests[0].start == quests[0].end) {
						printf("?");
					}
					else {
						printf(" ");
					}
				}
				else {
					printf("%c",mapTab[i][j]);
				}
			}
			else if(strcomp2(user->map,"startMap")) {
				if(mapTab[i][j] == '1') {
					printf("_");
				}
				else {
					printf("%c",mapTab[i][j]);
				}

			}
			else {
				printf("%c",mapTab[i][j]);
			}
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
char ** getMapFile(char mapName[]) {
	FILE * map = NULL; 
	char * nameMapTxt = addTxt(mapName);
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


