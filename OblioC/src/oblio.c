#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "oblio_game.h"
#include "oblio_view.h"

int get_user_input(short* input, short size);

int main(int args, char* argv[]){
	oblio_game game;
	short* input;
	short size;
	short num_turns;
	int game_number;

	game_number = 1;
	game.answer = NULL;
	size = DEFAULT_GAME_SIZE;
	num_turns = DEFAULT_NUM_TURNS;
	input= malloc(size * sizeof(short));
	srand(time(NULL));

	print_game_intro();
	new_game(&game, size, num_turns);
	print_answer(*(game.answer));
	printf("\nRound %d", game_number);
	while(1){
		if (is_game_over(game)) {
			print_game_results(game);
			clean_up_game(&game);
			new_game(&game, size, num_turns);
			printf("\n\nRound %d", ++game_number);
		} 
		print_turn_prompt();
		switch (get_user_input(input, size)) {
		case 1:
			if (!process_turn(&game, input, size)) {
				printf("THIS SHOULD NOT PRINT");
				print_input_error(size);
				break;
			}
		case 2:
			print_turn_results(game);
			break;
		case 3:
			print_goodbye();
			free(input);
			clean_up_game(&game);
			exit(EXIT_SUCCESS);
		default:
			print_input_error(size);
		}
		
	}

}

int get_user_input(short* input, short size){
	int i;
	short n;
	int len;
	int offset;
	char* user_input = NULL;
	size_t user_input_size;
	char* cursor;
	getline(&user_input, &user_input_size,stdin);
	if(user_input_size < 4 ){
		len = user_input_size;
	}else{
		len = 4;
	}
	if ( !strncmp("exit", user_input, len) || !strncmp(user_input, "quit", len) || user_input[0] == 'q') {
		free(user_input);
		return 3;
	}
	if ( !strncmp("hint", user_input, len) || !strncmp("help", user_input, len) || user_input[0] == 'h') {
		free(user_input);
		return 2;
	}

	i = 0;
	cursor = user_input;
	while (sscanf(cursor, " %hd%n", &n, &offset) == 1) {
		if(i == size){
			break;
		}
		if (i > size) {
			free(user_input);
			return -1;
		}

        cursor += offset;
		if (cursor > user_input + user_input_size){
			free(user_input);
			return -1;
		}
        input[i++] = n;

    }
	if( i == size){
		free(user_input);
		return 1;
	}
	free(user_input);
	return -1;

}