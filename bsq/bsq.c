#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct  node
{
    char empty;
    char obstacle;
    char full;
    int height;
    int width;
    char **map;
} t_map;

void free_map(t_map *map, int rows) {
    int i = 0;
    if (map->map) {
        while (i < rows) {
            free(map->map[i]);
            i++;
        }
        free(map->map);
        map->map = NULL;
    }
}

int ft_strlen(char *line){
    int i = 0;
    while (line[i]){
        i++;
    }
    return i;
}

int valid_header(char *header, t_map *map){
    int len = ft_strlen(header);
    int i = 0;
    map->height = 0;
    while (i <= len-5){
        if (header[i] >= '0' && header[i] <= '9'){
            map->height = (map->height * 10) + (header[i] - '0');
        }
        else
            return 0;
        i++;
    }
    if (len < 5 || map->height == 0)
        return 0;
    map->empty = header[len-4];
    map->obstacle = header[len-3];
    map->full = header[len-2];
    if (map->empty == map->obstacle || map->empty == map->full
        || map->full == map->obstacle)
        return 0;
    return 1;
}

int map_check(t_map *map){
    int i = 0;
    int j;
    while (map->map[i]){
        j = 0;
        while (map->map[i][j]){
            if (map->map[i][j] != map->empty
                && map->map[i][j] != map->obstacle)
                return 0;
            j++;
        }
        if (map->width != j)
            return 0;
        i++;
    }
    return 1;
}

int pars_stdin(t_map *map){
    char *line = NULL;
    int i = 0;
    size_t len = 0;
    int header = 0;
    int width = 0;
    ssize_t read_bytes = getline(&line, &len, stdin);
    while (read_bytes != -1){
        if (line[read_bytes - 1] != '\n'){
            free(line);
            if (header) free_map(map, i);
            return 0;
        }
        if (header == 0){
            if (!valid_header(line, map)){
                free(line);
                return 0;
            }
            header = 1;
            map->map = malloc((map->height + 1) * sizeof(char *));
            if (!map->map){
                free(line);
                return 0;
            }
            map->map[map->height] = NULL;
        }
        else{
            if (i >= map->height){
                free(line);
                free_map(map, i);
                return 0;
            }
            if (width == 0){
                map->width = ft_strlen(line) - 1;
                width = 1;
                if (map->width == 0){
                    free(line);
                    free_map(map, i);
                    return 0;
                }
            }
            map->map[i] = malloc(read_bytes * sizeof(char));
            if (!map->map[i]){
                free(line);
                free_map(map, i);
                return 0;
            }
            int j = 0;
            while (j < read_bytes - 1){
                map->map[i][j] = line[j];
                j++;
            }
            map->map[i][j] = '\0';
            i++;
        }
        read_bytes = getline(&line, &len, stdin);
    }
    free(line);
    if (header == 0)
        return 0;
    if (i != map->height){
        free_map(map, i);
        return 0;
    }
    if (!map_check(map)){
        free_map(map, i);
        return 0;
    }
    return 1;
}

int pars_file(t_map *map, char *file){
    char *line = NULL;
    int i = 0;
    size_t len = 0;
    int header = 0;
    int width = 0;
    FILE *fptr = fopen(file, "r");
    if (!fptr)
        return 0;
    ssize_t read_bytes = getline(&line, &len, fptr);
    while (read_bytes != -1){
        if (line[read_bytes - 1] != '\n'){
            free(line);
            if (header) free_map(map, i);
            fclose(fptr);
            return 0;
        }
        if (header == 0){
            if (!valid_header(line, map)){
                free(line);
                fclose(fptr);
                return 0;
            }
            header = 1;
            map->map = malloc((map->height + 1) * sizeof(char *));
            if (!map->map){
                free(line);
                fclose(fptr);
                return 0;
            }
            map->map[map->height] = NULL;
        }
        else{
            if (i >= map->height){
                free(line);
                free_map(map, i);
                fclose(fptr);
                return 0;
            }
            if (width == 0){
                map->width = ft_strlen(line) - 1;
                width = 1;
                if (map->width == 0){
                    free(line);
                    free_map(map, i);
                    fclose(fptr);
                    return 0;
                }
            }
            map->map[i] = malloc(read_bytes * sizeof(char));
            if (!map->map[i]){
                free(line);
                free_map(map, i);
                fclose(fptr);
                return 0;
            }
            int j = 0;
            while (j < read_bytes - 1){
                map->map[i][j] = line[j];
                j++;
            }
            map->map[i][j] = '\0';
            i++;
        }
        read_bytes = getline(&line, &len, fptr);
    }
    fclose(fptr);
    free(line);
    if (header == 0)
        return 0;
    if (i != map->height){
        free_map(map, i);
        return 0;
    }
    if (!map_check(map)){
        free_map(map, i);
        return 0;
    }
    return 1;
}

void print_error(){
    fprintf(stderr, "%s\n", "map error");
}

int ft_min(int a, int b, int c){
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

int solve(t_map *map){
    int max_size = 0;
    int max_x = 0;
    int max_y = 0;
    int i = 0;
    int j = 0;

    int **db = malloc(map->height * sizeof(int *));
    if (!db)
        return 0;
    while (i < map->height){
        db[i] = malloc(map->width * sizeof(int));
        if (!db[i])
            return 0;
        i++;
    }
    i = 0;
    while (i < map->height){
        j = 0;
        while (j < map->width){
            if (map->map[i][j] == map->obstacle)
                db[i][j] = 0;
            else if (i == 0 || j == 0)
                db[i][j] = 1;
            else
                db[i][j] = ft_min(db[i - 1][j], db[i][j - 1], db[i - 1][j - 1]) + 1;
            if (map->map[i][j] == map->empty && db[i][j] > max_size){
                max_size = db[i][j];
                max_y = i;
                max_x = j;
            }
            j++;
        }
        i++;
    }
    int y = max_y;
    while (y > max_y - max_size){
        int x = max_x;
        while (x > max_x - max_size){
            map->map[y][x] = map->full;
            x--;
        }
        y--;
    }
    i = 0;
    while (i < map->height){
        free(db[i]);
        i++;
    }
    free(db);
    return 1;
}

void print(t_map *map){
    int i = 0;
    while (i < map->height){
        fprintf(stdout, "%s\n", map->map[i]);
        i++;
    }
}

int main (int ac, char **av){
    int i = 1;
    t_map m;

    if (ac == 1){
        if (!pars_stdin(&m)) {
            print_error();
            return 1;
        }
        if (!solve(&m)) {
            free_map(&m, m.height);
            return 1;
        }
        print(&m);
        free_map(&m, m.height);
    }
    else{
        while (av[i]){
            if (!pars_file(&m, av[i])){
                print_error();
                i++;
                continue;
            }
            if (!solve(&m)){
                free_map(&m, m.height);
                i++;
                continue;
            }
            print(&m);
            free_map(&m, m.height);
            i++;
        }
    }
    return 0;
}