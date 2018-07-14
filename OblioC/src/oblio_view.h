
#ifndef OBLIO_VIEW_H
#define OBLIO_VIEW_H

#include "oblio_game.h"

void print_game_intro();
void print_answer(oblio_answer answer);
void print_game_status(oblio_game game);
void print_game_results(oblio_game game);
void print_turn_prompt();
void print_input_error(short number_of_digits);
void print_goodbye();
void print_turn_results(oblio_game game);

#endif
