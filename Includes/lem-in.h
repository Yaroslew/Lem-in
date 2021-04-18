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
void            set_weight(char *name, t_room *rooms, int weight, int length);
t_room			*get_room_by_name(char *name, t_room **rooms, int length);


// Тестовая хрень.
int		parser(t_room ***rooms_res, unsigned int *length);
void		error_management(char *msg);

#endif
