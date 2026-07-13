#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int validInput(char **av);
char *make_grid(char **av);
void fill_grid(char *grid, int width, int height);
void print_grid(char *grid, int width, int height);
void game_of_life(char *grid, char *new_grid, int width, int height, int iter);

#endif