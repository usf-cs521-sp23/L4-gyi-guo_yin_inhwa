#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int check_lowercase(int c, int start, int end){
    // check if start-end is correct range
    if ( start > end  || start == end ){
        // [ERROR] Start of range greater than end
        return -2;
    }
    
    // 3) check the character is in a range of start and end
    if( c >= start && c <= end ){
        return 0;
    }else{
        // [ERROR] Out of bound
        return -1;
    }

}

int play_wordle(char target[])
{
	for(int i=0; i < 5; i++){
		char guess[100];
		printf("Enter your guess : ");
		scanf("%s", guess);

		if( strlen(guess)!= 5){
			printf("This is not 5 characters. Please learn to play the game correctly.\n");
			continue;
		}

		for(int j=0; j < 5; j++){
			if( target[j]==guess[j] )
			{
				printf("O");
			}
			else if( strchr(target, guess[j]) != NULL )
			{
				printf("A");
			}
			else //means not found
			{
				printf("X");
			}
		}

		if ( strcmp(target, guess) == 0 ){
			system("cowsay \"YOU WIN\"");
			return 0;
		}		

		printf("\nYou have used %d times! %d chances left \n", i+1, 5-(i+1));
	}
	return 0;
}


int main(int argc, char *argv[])
{
	/* =================================== GAME SETTING =================================== */
	// 1. Open the file with argument that contains a lot of English words
	FILE *file = fopen(argv[1], "r");
	if ( file == NULL ){
		perror("fopen for choosing wordle words");
	}

	int  cnt 	   = 0  ; // total count of 5 letters words
	char target[6] = "" ; // Wordle Keyword

	// 2. Write 'temp' file to keep 5 letters words only
	char line[500];
	FILE *file_temp = fopen("temp", "w+");
	if ( file_temp == NULL ){
		perror("fopen for temp");
	}

	while( fgets(line, 500, file) != NULL ){
		if( strlen(line) == 6 ){
			bool flag = 0;

			for (int i =0 ; i < strlen(line)-1; i++) {
				if( check_lowercase(line[i], 'a', 'z') == 0 ){
					continue;
				}else{
					flag = 1;
					break;
				}
			}

			if( flag == 0  ){
				fputs(line, file_temp);
				cnt++;
			}
		}
	}
	fclose(file);
	fclose(file_temp);

	// 3. Read 'temp' to randomly select the target word
	FILE *file_select = fopen("temp", "r");
	if ( file == NULL ){
		perror("fopen for selecting words");
	}

	// 4. Get Random number from 'temp' file
	srand(time(NULL));		   // always should add if we want to get random num,b
	int random = rand() % cnt; // default
	int idx    = 1 ; // index to get keyword from 'temp'
	// printf("count  number is %d \n", cnt);
	// printf("random number is %d \n", random);


	while( fgets(line, 500, file_select) != NULL ){
		int len = strlen(line);

		// If selected random number matches current idx, we set that word as target
		if( idx == random ){
			strncpy( target, line, 5);
			break;
		}
		idx++;
	}

	// printf("TARGET WORD ::: [%s] \n", target);
	fclose(file_select);
	
	/* =================================== GAME START =================================== */
	char answer[50];
	strcpy(answer, "yes");
	while ( strcmp( answer, "yes") == 0 ) {
		
		play_wordle(target);
		printf("Do you want to play again? :::: ");
		while ( fgets(answer, 50, stdin) != NULL ) {
			continue;
		}
	}
	
}
