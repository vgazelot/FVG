#include <stdio.h>
#include <stdlib.h>

int main() {
	
	char map[40][80];
	int i=1;
	int j=1;
	for( i = 0 ; i<40 ;i++) {
		for(j=0 ; j<80 ; j++) {
			if( i == 0 || i == 39) {
				map[i][j] = '*';
			}
			else if(i == 20 && j == 40) {
				map[i][j] = '#';
			}
			else {
				if(j == 0 || j == 79) {
					map[i][j] = '*';
				}
				else {
					map[i][j]= ' ';
				}
		
			}
		}
	}

	for(i = 0; i < 40;i++) {
		for(j= 0; j < 80; j++) {
			if(i == 0 || i == 39) {
				printf("%c",map[i][j]);
			}
			else {
				printf("%c",map[i][j]);
			}
		}
		printf("\n");	
	}	

return 0;
}
