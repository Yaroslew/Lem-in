#include "lem-in.h"

int				main(int ac, char **av){
    // тестовые данные.
    unsigned int        length; // количество комнат.
    t_room				**rooms;
    unsigned int		ants;


    // парсер и проверки правильности карт. Получение массива комнат.
	if (parser(ac, av, &rooms, &length, &ants) == -1)
    	error_management("msg");

    // Поиск в ширину и Эдмондс-Карп.
    get_way(rooms, length);

//	for(unsigned int i = 0; i < length; i++)
//	{
//		ft_printf("название комнаты: %s  вес: %d \n", rooms[i]->name, rooms[i]->weight);
//		ft_printf("Путь 1: %s\n", rooms[i]->ways[0]->name);
//		ft_printf("Путь 2: %s\n", rooms[i]->ways[1]->name);
//	}

    // Отрисовка муравьев(без принтф желательно => скорость).
    return 0;
}


void            get_way(t_room **rooms, unsigned int length){

    unsigned int         q = 0;
    char        **queue;
    int 		**matrix;

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
	create_matrix(rooms, matrix, length);

    // Матрица смежности.

    // repeat пока есть пути.

    // Комнаты-призраки??..?....
    return;
}

void		create_matrix(t_room **rooms, int **matrix, unsigned int length){
	unsigned int q = 0;

	// 1 = путь вперед.
	// -1 = путь назад.
	// 0 = отставить путь.
	matrix = ft_memalloc(sizeof (int*)*length);
	while (q < length)
	{
		matrix[q] = ft_memalloc(sizeof(int) * length);
		ft_bzero(matrix[q], sizeof(int) * (length));
		q++;
	}

	for(unsigned i = 0; i < length; i++){
		ft_printf("r0=%d\n", matrix[i][0]);
		ft_printf("r1=%d\n", matrix[i][1]);
		ft_printf("r2=%d\n", matrix[i][2]);
		ft_printf("r3=%d\n", matrix[i][3]);
		ft_printf("r4=%d\n", matrix[i][4]);
	}
	return;

}

void 		find_path(t_room **rooms, int** matrix){
	//	Найти путь от начала до конца.
	//  Путь не должен повторяться.
	// 	Сохранить новый путь в матрицу.

}

int 		check_path_by_matrix(int** matrix, t_room *current_room, t_room *next_room, unsigned int length){
	unsigned int q = 0;
	int			*next_row;

	while (q < length){
		if (matrix[q][0] == next_room->number){
			next_row = matrix[q];
			break;
		}
		q++;
	}
	if (current_room->weight < next_room->weight && next_row[current_room->number] == 1)
		return 1;
	else if (current_room->weight > next_room->weight && next_row[current_room->number] == -1)
		return 1;
	else
		return 0;
}

void		add_new_path_to_matrix(){

}






