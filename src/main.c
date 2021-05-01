#include "lem-in.h"

int				main(int ac, char **av){
    // тестовые данные.
    unsigned int        length; // количество комнат.
    t_room				**rooms;


    // парсер и проверки правильности карт. Получение массива комнат.
	if (parser(ac, av, &rooms, &length) == -1)
    	error_management("msg");

    // Поиск в ширину и Эдмондс-Карп.
    get_way(rooms, 5);

	for(unsigned int i = 0; i < length; i++)
	{
		ft_printf("название комнаты: %s  вес: %d \n", rooms[i]->name, rooms[i]->weight);
		ft_printf("Путь 1: %s\n", rooms[i]->ways[0]->name);
		ft_printf("Путь 2: %s\n", rooms[i]->ways[1]->name);
	}

    // Отрисовка муравьев(без принтф желательно => скорость).
    return 0;
}


void            get_way(t_room **ptr_rooms, int length){

    int         q = 0;
    char        **queue = (char**)malloc(sizeof (char*) * length);
    t_room		*rooms;

    rooms = *ptr_rooms;
    for(int i = 0; i < length; i++)
		ft_bzero(queue, length * sizeof(char *));
	set_queue(queue, &rooms[0], length);

    // Поиск в ширину.
    while(q < length){
		set_weight(queue[q], rooms, q, length);
		check_ways(rooms[q], queue, length);
    	q++;
    }

    // Матрица смежности.
    // repeat пока есть пути.

    // Комнаты-призраки??..?....
    return;
}

void			check_ways(t_room room, char **queue, int length){
	int q = 0;

	while(q < room.count_ways)
	{
		if (room.ways[q]->status != 1)
			set_queue(queue, room.ways[q], length);
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

void            set_weight(char *name, t_room *rooms, int weight, int length){

	t_room *room = get_room_by_name(name, &rooms, length);
	room->status = 1;
	room->weight = weight;
}

t_room			*get_room_by_name(char *name, t_room **ptr_rooms, int length){
	int			q = 0;
	t_room		**rooms;

	rooms = ptr_rooms;
	while (q < length){
		if (ft_strcmp(rooms[q]->name, name) == 0)
			return &rooms[q];
		q++;
	}
	return NULL;
}


