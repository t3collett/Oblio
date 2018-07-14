#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "oblio_game.h"
#include "oblio_view.h"


int main(int args, char* argv[]){
	oblio_game game;
	
	srand(time(NULL));
	new_game(&game, 4, 10);
	print_game_intro();
	print_answer(*(game.answer));
		
}



