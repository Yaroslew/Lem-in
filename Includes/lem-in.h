#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "libft.h"

typedef struct  t_vertex
{
    char        *name;
    int         status; // 1- уже есть в очереди.
    int         weight;
} t_vertex;

typedef struct  t_room{
    char        *name;
    char        **ways;
    int         x;
    int         y;
}               t_room;

int             get_way((s_room *)rooms, int length);
//int             ft_free_ind(int **arr);
void            insert_in_queue(char **queue,  t_room room, int length)
#endif
