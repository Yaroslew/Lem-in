#include "lem-in.h"

void            set_weight(char *name, t_room **rooms, int weight, int length){

	t_room 		*current_room;

	current_room = get_room_by_name(name, rooms, length);
	current_room->status = 1;
	current_room->weight = weight;
}

t_room			*get_room_by_name(char *name, t_room **rooms, int length){
	int			q = 0;

	while (q < length){
		if (ft_strcmp(rooms[q]->name, name) == 0)
			return rooms[q];
		q++;
	}
	return NULL;
}

void			check_ways(t_room *room, char **queue, int length){
	int q = 0;

	while(q < room->count_ways)
	{
		if (room->ways[q]->status != 1)
			set_queue(queue, room->ways[q], length);
		q++;
	}
}

void            set_queue(char **queue,  t_room *room, int length){
	int         q = 0;

	while(q < length){
		if (queue[q] == NULL)
			break;
		q++;
	}
	queue[q] = room->name;
}


