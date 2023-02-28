#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_WORD_SIZE 10

int check_lowercase(int c, int start, int end);
int play_wordle(char target[], int size_of_word, char *username);
int get_target(int cnt, char *target, int size_of_word);

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

int play_wordle(char target[], int size_of_word, char *username)
{
	char user_input[26] = {0};

	for(int i=0; i < size_of_word; i++){
		char guess[100];
		printf("Enter your guess : ");
		scanf("%s", guess);

		if( strlen(guess)!= size_of_word){
			printf("This is not %d characters. Please learn to play the game correctly.\n",size_of_word);
			continue;
		}

		int green_count = 0;
        int yellow_count = 0;

		// When the user guessed correctly
		if ( strcmp(target, guess) == 0 ){
			char cowwsay[200] ;
			strcpy(cowwsay, "cowsay \"YOU WIN\" !! Congratulations, ") ;
			strcat(cowwsay, username);
			system(cowwsay);
			return 0;
		}	

		for(int j=0; j < size_of_word; j++){
			user_input[guess[j]-97]++;

			if( target[j]==guess[j] )
			{
				printf("\x1b[32mO\x1b[0m"); // green
                green_count++;
			}
			else if( strchr(target, guess[j]) != NULL )
			{
				printf("\x1b[33mA\x1b[0m"); // yellow
                yellow_count++;
			}
			else //means not found
			{
				printf("\x1b[30mX\x1b[0m"); // gray
			}
		}

		printf("\nLetters you have used ::: ");
		// print out guessed letter 
		for ( int i = 0 ; i < 26; i++){
			if( user_input[i] > 0 ){
				printf("%c", i+97);
			}
		}
		

		printf("\nYou have used %d times! %d chances left \n", i+1, size_of_word-(i+1));
	}

	printf("Unfortunately, the correct answer is [%s], %s", target, username);
	return 0;
}


int get_target(int cnt, char *target, int size_of_word){

	FILE *file_select = fopen("temp", "r");
	if ( file_select == NULL ){
		perror("fopen for selecting words");
	}
	// 4. Get Random number from 'temp' file
	srand(time(NULL));		   // always should add if we want to get random num,b
	int random = rand() % cnt; // default
	int idx    = 1 ; // index to get keyword from 'temp'
	// printf("count  number is %d \n", cnt);

	char line[1024];
	while( fgets(line, 500, file_select) != NULL ){
		int len = strlen(line);

		// If selected random number matches current idx, we set that word as target
		if( idx == random ){
			strncpy( target, line, size_of_word);
			break;
		}
		idx++;
	}
	
	fclose(file_select);
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

	//get opt of word size
	int size_of_word = 5;//default size
	
	int c;
    opterr = 0;

    while ((c = getopt(argc, argv, "l:")) != -1) {
		 switch (c) {
            case 'l':{
                //convert num_string to an actual integer
			
                char *end;
                size_of_word = (int) strtol(optarg, &end, 10);
				if ( size_of_word > MAX_WORD_SIZE ){
					fprintf(stderr, "argument is too big. It is allowed from 2 to %d letters of word. \n", MAX_WORD_SIZE);
                    return 1;
				}

                if (end == optarg) {
                    fprintf(stderr, "argument is not a number\n");
                    return 1;
                }
            }
                break;
			default:
				if (optarg == NULL) {
					printf("please add am argument after -l flag \n");
					return 1;	
				}
				break;
		 }
	}
		

	int  cnt 	   = 0  ; // total count of size_of_word letters words
	char target[ MAX_WORD_SIZE +1] = "" ; // Wordle Keyword

	// 2. Write 'temp' file to keep size_of_word letters words only
	char line[500];
	FILE *file_temp = fopen("temp", "w+");
	if ( file_temp == NULL ){
		perror("fopen for temp");
	}

	while( fgets(line, 500, file) != NULL ){
		if( strlen(line) == size_of_word + 1 ){
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

	// 3. Get Random number from 'temp' file
	get_target(cnt, target, size_of_word);

	
	/* =================================== GAME START =================================== */

	char username[50];
	printf("Please enter your name: ");
	fgets(username, 50, stdin);
	printf("Welcome ! %s", username);

	char answer[50] = {0};
	strcpy(answer, "Y");
	while ( strcmp( answer, "Y") == 0 ) {
		get_target(cnt, target, size_of_word);
		play_wordle(target, size_of_word, username);
		printf("\nDo you want to play again? [Y/N] :::: ");
		scanf("%s" , answer);
	}
	
}