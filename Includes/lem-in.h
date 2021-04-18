#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "libft.h"

typedef struct		t_room{
    char			*name;
    struct t_room	**ways;
    int				count_ways;
    int				x;
    int				y;
	int				status;
	int				weight;
}					t_room;

void            get_way(t_room *rooms, int length);
void			check_ways(t_room room, char **queue, int length);
void            set_queue(char **queue,  t_room *room, int length);
void            set_weight(t_room room, int weight);


// Тестовая хрень.
void            parser(t_room *rooms);

#endif
