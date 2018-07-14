#ifndef OBLIO_GAME_H
#define OBLIO_GAME_H


#define DEFAULT_GAME_SIZE 4
#define DEFAULT_NUM_TURNS 10

typedef struct {
	short*	digits;
	short 	size;
} oblio_answer;

typedef struct {
	oblio_answer*  answer;
	unsigned short number_of_guesses;
	unsigned short turns_left;
	unsigned short correct;
	unsigned short misplaced;
} oblio_game;


void new_game(oblio_game* game, short size, short number_of_turns);
void generate_answer(oblio_answer** answer, short size);
int process_turn(oblio_game* game, short* input, int size);
int is_game_over(oblio_game game);
void clean_up_game(oblio_game* game);

#endif
