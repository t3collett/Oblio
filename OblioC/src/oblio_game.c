#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "oblio_game.h"
#include "oblio_view.h"

void new_game(oblio_game* game, short size, short number_of_turns) {	
	if(game->answer	!= NULL) {
		clean_up_game(game);
	}
	game->number_of_guesses = 0;
	game->correct = 0;
	game->misplaced = 0;
	game->turns_left = number_of_turns;
	generate_answer(&(game->answer),size);	
}

void clean_up_game(oblio_game* game) {
	free(game->answer->digits);
	free(game->answer);
	game->answer = NULL;	
	return;
}

void generate_answer(oblio_answer** answer,short size) {
	short i, j, n;
	*answer = malloc(sizeof(oblio_answer));
	(*answer)->size = size;
	(*answer)->digits = malloc(sizeof(short) * size);
	for ( i=0 ; i < size ; i++ ) {
		n = rand() % 10;
		if (size < 10) {
			for ( j=0 ; j < i ; j++ ) {
				if (n == (*answer)->digits[j]) {
					break;
				} 
			}
			if( j == i){
				(*answer)->digits[i] = n;
			} else{
				i--;
			}
		} else {
			(*answer)->digits[i] = n;
		} 	
	}
	return;
}
int valid_turn(oblio_game* game, short* input, int size) {
	if (game->turns_left <= 0 || game->correct == game->answer->size) {
		return 0;
	}
	if (input == NULL || size != game->answer->size) {
		return 0;
	}
	return 1;	
}

int process_turn(oblio_game* game, short* input, int size) {
	int i,j;
	if (!valid_turn(game, input, size)) {
		return -1;
	}
	game->turns_left--;
	game->number_of_guesses++;	
	game->correct = 0;
	game->misplaced = 0;
	for ( i=0 ; i < size ; i++ ) {
		if ( input[i] == game->answer->digits[i]) {
			game->correct++;
		} else {
			for ( j=0 ; j < size ; j++ ) {
				if (input[i] == game->answer->digits[j]) {
					game->misplaced++;
					break;
				}	
			}
		}
	}
	return 1;
}

int is_game_over(oblio_game game) {
	if (game.turns_left <= 0 || game.correct == game.answer->size) {
		return 1;
	}
	return 0;
}	
