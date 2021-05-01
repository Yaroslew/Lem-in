#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

# include "libft.h"

# include <stdlib.h>
# include <stdio.h>
#include <sys/fcntl.h>

typedef struct		s_room
{
    char			*name;
    struct s_room	**ways;
    int				count_ways;
    int				x;
    int				y;
	int				status;
	int				weight;
}					t_room;

void            get_way(t_room **rooms, int length);
void			check_ways(t_room room, char **queue, int length);
void            set_queue(char **queue,  t_room *room, int length);
void            set_weight(char *name, t_room *rooms, int weight, int length);
t_room			*get_room_by_name(char *name, t_room **rooms, int length);


// Тестовая хрень.
int         parser(int ac, char **av, t_room ***rooms_res, unsigned int *length);
void		error_management(char *msg);

/*
**      parse_map.c
*/

int         read_map(int fd, t_room ***rooms_res, unsigned int *length);

/*
**      parse_room.c
*/

int     new_room(t_room **start, t_room **end, t_room **cur, char *line);
void    fill_the_room(t_room *room, int fd);

#endif
