#include "structs.h"

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void draw(void);
extern void delay(unsigned int frameLimit);
extern void loadGame(void);
//fonction update pour scroll
extern void updatePlayer(void);
extern void initializePlayer(void);

t_input   input;
t_gestion jeu;
t_map     map;
t_hero    player;
