#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>

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

int play_wordle(char target[], int size_of_word)
{
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

		for(int j=0; j < size_of_word; j++){
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

		if ( strcmp(target, guess) == 0 ){
			system("cowsay \"YOU WIN\"");
			return 0;
		}		

		printf("\nYou have used %d times! %d chances left \n", i+1, size_of_word-(i+1));
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
                if (end == optarg) {
                    puts("HERE______0_______");
                    fprintf(stderr, "argument is not a number\n");
                    return 1;
                }
            }
                break;
			default:
                abort();
		 }
	}
		

	int  cnt 	   = 0  ; // total count of size_of_word letters words
	char target[6] = "" ; // Wordle Keyword

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
			strncpy( target, line, size_of_word);
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
		
		play_wordle(target, size_of_word);
		printf("Do you want to play again? :::: ");
		while ( fgets(answer, 50, stdin) != NULL ) {
			continue;
		}
	}
	
}