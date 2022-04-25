/*
	==================================================
	Workshop #5 (Part-1):
	==================================================
	Name    : Anna Shin
	ID      : 131283210
	Email   : ashin8@myseneca.ca
	Section : NHH
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_GAME_LEN 70
#define MIN_GAME_LEN 10
#define MAX_LIVES 10
#define MIN_LIVES 1
#define MAX_PATH_LEN 100
#define MULTIPLE 5

typedef struct{
	int live;
	char player_symbol;
	int treasure;
	int position[MAX_PATH_LEN];
} PlayerInfo;

typedef struct{
	int move;
	int path_length;
	int bomb[MAX_PATH_LEN];
	int gtreasure[MAX_PATH_LEN];
} GameInfo;

void configPlayer(PlayerInfo *);
void configGame(GameInfo *, PlayerInfo *);
void bombPlacement(GameInfo *);
void treasurePlacement(GameInfo *);
void displayConfig(PlayerInfo, GameInfo);

int main(){
	PlayerInfo player = { 0, '\0', 0, {0}};
	GameInfo game = {0, 0, {0}, {0}};
	configPlayer(&player);
	configGame(&game, &player);
	bombPlacement(&game);
	treasurePlacement(&game);
	displayConfig(player, game);
	return 0;

}
void configPlayer(PlayerInfo *p){
	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");

	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf("%c", &p->player_symbol);

    do {
		printf("Set the number of lives: ");
		scanf("%d", &p->live);

		if(p->live < MIN_LIVES || p->live > MAX_LIVES)
			printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
	}
	while (p->live < MIN_LIVES || p->live > MAX_LIVES);
		printf("Player configuration set-up is complete");
	return;
}

void configGame(GameInfo *g, PlayerInfo *p){
	printf("\n\nGAME Configuration\n");
	printf("------------------\n");

	int done = 1, flag = 1; 
	while (done){
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &g->path_length);
        done = g->path_length % MULTIPLE != 0 || g->path_length < MIN_GAME_LEN || g->path_length > MAX_GAME_LEN;
        if (done){
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_GAME_LEN, MAX_GAME_LEN);
        }
    }   

	int MIN_MOVES = p->live;
    int MAX_MOVES;
	MAX_MOVES = 0.75 * g->path_length;

	while (flag){
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &g->move);
        flag = g->move<MIN_MOVES || g->move>MAX_MOVES;
        if (flag){
            printf("    Value must be between %d and %d\n", MIN_MOVES,MAX_MOVES);
        }

    }
	printf("\n");
	return;
}

void bombPlacement(GameInfo *g){
	printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",g->path_length);
	
	int i, j;
    for (i = 0; i < g->path_length; i += MULTIPLE){
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        for (j = 0; j < MULTIPLE; j++){
            scanf(" %d", &g->bomb[i + j]);
        }
    }
	printf("BOMB placement set\n\n");
	return;
}

void treasurePlacement(GameInfo *g){
	printf("TREASURE Placement\n");
    printf("------------------\n");
	printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLE);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",g->path_length);

	int i, j;
	for (i = 0; i < g->path_length; i += MULTIPLE){
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        for (j = 0; j < MULTIPLE; j++){
            scanf(" %d", &g->gtreasure[i + j]);
        }
    }
    printf("TREASURE placement set\n");
	return;
}

void displayConfig(PlayerInfo p, GameInfo g){
	printf("\nGAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", p.player_symbol);
    printf("   Lives      : %d\n", p.live);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

	int i;
    printf("Game:\n");
    printf("   Path Length: %d\n", g.path_length);
    printf("   Bombs      : ");
    for (i = 0; i < g.path_length; i++){
        printf("%d", g.bomb[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < g.path_length; i++){
        printf("%d", g.gtreasure[i]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return;
}

