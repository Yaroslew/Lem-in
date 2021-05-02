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
	unsigned int 	number; // порядковый номер. Первый - комната старт, последний - финиш.
}					t_room;

//main
void            get_way(t_room **rooms, unsigned int length);
//breadth first search
void			check_ways(t_room *room, char **queue, unsigned int length);
void            set_queue(char **queue,  t_room *room, unsigned int length);
void            set_weight(char *name, t_room **rooms,unsigned int weight, unsigned int length);
t_room			*get_room_by_name(char *name, t_room **rooms, unsigned int length);
//matrix
void			create_matrix(t_room **rooms, int **matrix, unsigned int length);

// Тестовая хрень.
int         parser(int ac, char **av, t_room ***rooms_res, unsigned int *length, unsigned int *ants);
void		error_management(char *msg);

/*
**      parse_map.c
*/

int    		parse_comment(t_list **file);
int         read_map(t_list *whole_file, t_room ***rooms_res, unsigned int *length, unsigned int *ants);

/*
**      parse_room.c
*/

int     new_room(t_room **start, t_room **end, t_room **cur, t_list **file);
void    fill_the_room(t_room *room, t_list **file);

/*
** 		parse_roommates
*/

void	parse_roommates(t_list *file, t_room **rooms, unsigned int length);

#endif
