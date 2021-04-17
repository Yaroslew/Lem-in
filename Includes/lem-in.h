#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "libft.h"

typedef struct  s_vertex
{
    int         status; // 1- уже есть в очереди.
    int         weight;
} s_vertex;

typedef struct  s_room{
    char        *name;
    char        **ways;
    int         x;
    int         y;
}               s_room;

int             get_way(int **matrix, int rooms_count);
int             ft_free_ind(int **arr);
#endif
