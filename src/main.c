#include "lem-in.h"

int				main(int ac, char **av){
    // тестовые данные.
    unsigned int        length; // количество комнат.
    t_room				**rooms;


    // парсер и проверки правильности карт. Получение массива комнат.
	if (parser(ac, av, &rooms, &length) == -1)
    	error_management("msg");

    // Поиск в ширину и Эдмондс-Карп.
    get_way(rooms, length);

	for(unsigned int i = 0; i < length; i++)
	{
		ft_printf("название комнаты: %s  вес: %d \n", rooms[i]->name, rooms[i]->weight);
		ft_printf("Путь 1: %s\n", rooms[i]->ways[0]->name);
		ft_printf("Путь 2: %s\n", rooms[i]->ways[1]->name);
	}

    // Отрисовка муравьев(без принтф желательно => скорость).
    return 0;
}


void            get_way(t_room **rooms, int length){

    int         q = 0;
    char        **queue;

    queue =  (char**)malloc(sizeof (char*) * length);
    for(int i = 0; i < length; i++)
		ft_bzero(queue, length * sizeof(char *));
	set_queue(queue, rooms[0], length);

    // Поиск в ширину.
    while(q < length){
		set_weight(queue[q], rooms, q, length);
		check_ways(rooms[q], queue, length);
    	q++;
    }
    // Поиск пути и заполнение матрицы сложности.


    // Матрица смежности.

    // repeat пока есть пути.

    // Комнаты-призраки??..?....
    return;
}







