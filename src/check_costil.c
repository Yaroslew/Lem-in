//
// Created by Hugor Chau on 5/2/21.
//
#include "lem-in.h"
#define TEMP_LENGTH 5


int		run_hardcode(t_room ***rooms_res, unsigned int *length, unsigned int *ants)
{
	t_room **rooms;

	rooms = ft_memalloc(sizeof(t_room *) * (TEMP_LENGTH + 1));
	for (unsigned int i = 0; i < TEMP_LENGTH; i++)
	{
		rooms[i] = ft_memalloc(sizeof(t_room));
	}
	for(int i = 0; i < TEMP_LENGTH; i++)
		rooms[i]->name = (char *)malloc(sizeof (char)*2);
	rooms[0]->name = "R0";
	rooms[1]->name = "R1";
	rooms[2]->name = "R2";
	rooms[3]->name = "R3";
	rooms[4]->name = "R4";

	rooms[0]->ways = (t_room**)malloc(sizeof(t_room*) * 2);
	rooms[0]->ways[0] = rooms[1];
	rooms[0]->ways[1] = rooms[2];
	rooms[0]->count_ways = 2;

	rooms[1]->ways = (t_room**)malloc(sizeof(t_room*) * 2);
	rooms[1]->ways[0] = rooms[0];
	rooms[1]->ways[1] = rooms[4];
	rooms[1]->count_ways = 2;

	rooms[2]->ways = (t_room**)malloc(sizeof(t_room*) * 2);
	rooms[2]->ways[0] = rooms[0];
	rooms[2]->ways[1] = rooms[3];
	rooms[2]->count_ways = 2;

	rooms[3]->ways = (t_room**)malloc(sizeof(t_room*) * 2);
	rooms[3]->ways[0] = rooms[2];
	rooms[3]->ways[1] = rooms[4];
	rooms[3]->count_ways = 2;

	rooms[4]->ways = (t_room**)malloc(sizeof(t_room*) * 2);
	rooms[4]->ways[0] = rooms[1];
	rooms[4]->ways[1] = rooms[3];
	rooms[4]->count_ways = 2;
	rooms[5] = NULL;
	*rooms_res = rooms;
	*length = TEMP_LENGTH;
	*ants = 10;
	return (0);
}

int				check_costil(int ac, char **av, t_room ***rooms_res, unsigned int *length, unsigned int *ants)
{
	if (ac > 1 && ft_strequ(av[1], "-1"))
	{
		run_hardcode(rooms_res, length, ants);
		return (1);
	}
	return (0);
}
