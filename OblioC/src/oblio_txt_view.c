#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "oblio_game.h"
#include "oblio_view.h"
#include "oblio_strings.h"

void print_game_intro(){
	printf(GAME_TITLE);
}
void print_game_status(oblio_game game){
	if (game.answer == NULL) {
		printf("\nYou need to start a game to see its status");
		return;
	}
	printf("\nNumber of guesses: %u", game.number_of_guesses);
	printf("\nNumber of digits in answer: %u", game.answer->size);
	print_turn_results(game);
	return;
}

void print_turn_prompt(){
	printf("\nEnter 4 digits: ");
	return;
}
void print_input_error(short number_of_digits){
	printf(INPUT_ERROR,number_of_digits);
	return;
}
void print_goodbye(){
	printf("\nThanks for playing. Goodbye!\n");
}

void print_turn_results(oblio_game game){
	printf("\nNumber of turns left: %u", game.turns_left);
	printf("\nNumber Correct: %u", game.correct);
	printf("\nNumber Misplaced: %u", game.misplaced);
}

void print_game_results(oblio_game game) {
	char plural;
	if (game.turns_left <= 0) { 
		printf("\nYou Lose!");
	} else {
		printf("\nYou Win!");
	}
	if (game.number_of_guesses == 1) {
		plural = '!';
	} else {
		plural = 's';
	}
	printf("\nYou took %u turn%c", game.number_of_guesses, plural);
	print_answer(*(game.answer));
	return;
}

void print_answer(oblio_answer answer) {
	int i;
	printf("\nThe answer is:");
	for ( i=0 ; i < answer.size ; i++ ) {
		printf(" %d", answer.digits[i]);	
	}
	printf("\n");	
	return;
}
