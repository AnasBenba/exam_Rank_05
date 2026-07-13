#include "life.h"

int main(int ac, char **av){
    if (ac != 4)
        return 0;
    if (!validInput(av))
        return 1;
    char *grid = make_grid(av);
    if (!grid)
        return 1;
    fill_grid(grid, atoi(av[1]) ,atoi(av[2]));
    char *new_grid = make_grid(av);
    if (!new_grid)
    return 1;
    game_of_life(grid, new_grid, atoi(av[1]), atoi(av[2]), atoi(av[3]));
    print_grid(grid, atoi(av[1]), atoi(av[2]));
}