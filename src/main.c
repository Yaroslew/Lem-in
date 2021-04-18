#include "lem-in.h"

void            parser(t_room *rooms)
{
    for(int i = 0; i < 5; i++)
        rooms[i].name = (char *)malloc(sizeof (char)*2);
    rooms[0].name = "R0";
    rooms[1].name = "R1";
    rooms[2].name = "R2";
    rooms[3].name = "R3";
    rooms[4].name = "R4";

    rooms[0].ways = (t_room**)malloc(sizeof(t_room*) * 2);
    rooms[0].ways[0] = &rooms[1];
    rooms[0].ways[1] = &rooms[2];
    rooms[0].count_ways = 2;

	rooms[1].ways = (t_room**)malloc(sizeof(t_room*) * 2);
	rooms[1].ways[0] = &rooms[0];
	rooms[1].ways[1] = &rooms[4];
	rooms[1].count_ways = 2;

	rooms[2].ways = (t_room**)malloc(sizeof(t_room*) * 2);
	rooms[2].ways[0] = &rooms[0];
	rooms[2].ways[1] = &rooms[3];
	rooms[2].count_ways = 2;

	rooms[3].ways = (t_room**)malloc(sizeof(t_room*) * 2);
	rooms[3].ways[0] = &rooms[2];
	rooms[3].ways[1] = &rooms[4];
	rooms[3].count_ways = 2;

	rooms[4].ways = (t_room**)malloc(sizeof(t_room*) * 2);
	rooms[4].ways[0] = &rooms[1];
	rooms[4].ways[1] = &rooms[3];
	rooms[4].count_ways = 2;
}


int				main(void){
    // тестовые данные.
    int         length = 5; // количество комнат.


    // парсер и проверки правильности карт. Получение массива комнат.
    t_room rooms[length];
    parser((t_room *)rooms);


    // Поиск в ширину и Эдмондс-Карп.
    get_way(rooms, 5);


    // Отрисовка муравьев(без принтф желательно => скорость).
    return 0;
}

void            get_way(t_room *rooms, int length){

    int         q = 0;
    char        **queue = (char**)malloc(sizeof (char*) * length);

	ft_bzero(queue, length);
	set_queue(queue, &rooms[0], length);

    // Поиск в ширину.
    while(q < length){
		set_weight(rooms[q], q);
		check_ways(rooms[q], queue, length);
    	q++;
    }
    for(int i = 0; i < length; i++)
	{
    	ft_printf("название комнаты: %s  вес: %d \n", rooms[i].name, rooms[i].weight);
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

void            set_weight(t_room room, int weight){
	room.status = 1;
	room.weight = weight;
}


