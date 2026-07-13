#include "life.h"


int validInput(char **av){
    int i = 1;
    int y;
    while (av[i]){
        y = 0;
        while (av[i][y]){
            if (av[i][y] < '0' || av[i][y] > '9'){
                return 0;
            }
            y++;
        }
        i++;
    }
    return (1);
}

char *make_grid(char **av){
    int width = atoi(av[1]);
    int height = atoi(av[2]);
    int len = width * height;
    int i = 0;

    char *grid = malloc(len + 1);
    if (!grid)
        return NULL;
    grid[len] = '\0';
    while (i < len){
        grid[i] = ' ';
        i++;
    }
    return grid;
}

void fill_grid(char *grid, int width, int height){
    int draw = 0;
    int pen_x = 0;
    int pen_y = 0;
    int index = 0;
    char action;
    while (read(0, &action, 1)){
        if (action == 'w'){
            if (pen_y > 0)
                pen_y--;
        }
        else if (action == 'a'){
            if (pen_x > 0)
                pen_x--;
        }
        else if (action == 's'){
            if (pen_y < height - 1)
                pen_y++;
        }
        else if (action == 'd'){
            if (pen_x < width - 1)
                pen_x++;
        }
        else if (action == 'x'){
            if (draw == 0)
                draw = 1;
            else
                draw = 0;
        }
        index = (pen_y * width) + pen_x;
        if (draw == 1)
            grid[index] = 'O';
    }
}

void print_grid(char *grid, int width, int height){
    int index = 0;
    for (int i = 0; i < height; i++){
        for (int y = 0; y < width; y++){
            index = (i * width) + y;
            if (index < (width * height))
                putchar(grid[index]);
        }
        putchar('\n');
    }
}

static int *make_x(){
    int *x = malloc(8 * sizeof(int));
    if (!x)
        return NULL;
    x[0] = 0;
    x[1] = 0;
    x[2] = -1;
    x[3] = 1;
    x[4] = -1;
    x[5] = 1;
    x[6] = -1;
    x[7] = 1;
    return x;
}

static int *make_y(){
    int *y = malloc(8 * sizeof(int));
    if (!y)
        return NULL;
    y[0] = -1;
    y[1] = 1;
    y[2] = 0;
    y[3] = 0;
    y[4] = -1;
    y[5] = -1;
    y[6] = 1;
    y[7] = 1;
    return y;
}

static int alive(char *g, int W, int H, int x, int y){
    int *x_offs = make_x();
    int *y_offs = make_y();
    int nx, ny, index, count = 0;

    for (int i = 0; i < 8; i++){
        nx = x + x_offs[i];
        ny = y + y_offs[i];
        if ((nx >= 0 && nx < W)
            && (ny >= 0 && ny < H)){
            index = (ny * W) + nx;
            if (g[index] == 'O')
                count++;
        }
    }
    if (count < 2 || count > 3)
        return 0;
    return 1;
}

static int dead(char *g, int W, int H, int x, int y){
    int *x_offs = make_x();
    int *y_offs = make_y();
    int nx, ny, index, count = 0;

    for (int i = 0; i < 8; i++){
        nx = x + x_offs[i];
        ny = y + y_offs[i];
        if ((nx >= 0 && nx < W)
            && (ny >= 0 && ny < H)){
            index = (ny * W) + nx;
            if (g[index] == 'O')
                count++;
        }
    }
    if (count != 3)
        return 0;
    return 1;
}

void game_of_life(char *grid, char *new_grid, int W, int H, int iter){
    int index = 0;
    for (int i = 0; i < iter; i++){
        for (int row = 0; row < H; row++){
            for (int col = 0; col < W; col++){
                index = (row * W) + col;
                if (index < (W * H)){
                    if (grid[index] == 'O'){
                        if (alive(grid, W, H, col, row))
                            new_grid[index] = 'O';
                    }
                    else{
                        if (dead(grid, W, H, col, row))
                            new_grid[index] = 'O';
                    }
                }
            }
        }
    }
}

