#include "lem-in.h"

int				main(int ac, char **av){
    // тестовые данные.
    unsigned int        length; // количество комнат.
    t_room				**rooms;
    unsigned int		ants;
    t_list				*red_file;


    // парсер и проверки правильности карт. Получение массива комнат.
    if (!check_costil(ac, av, &rooms, &length, &ants))
	{
    	read_whole_file(&red_file, ac, av);
		parser(red_file, &rooms, &length, &ants);
	}

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
	matrix = create_matrix(length);
	find_path(rooms, matrix, length);
    // Матрица смежности.

    // repeat пока есть пути.

    // Комнаты-призраки??..?....
    return;
}

int		**create_matrix(unsigned int length){
	unsigned int q = 0;
	unsigned int r = 0;
	int matrix[length][length];

	while(q < length){
		while (r < length){
			matrix[q][r] = 0;
			r++;
		}
		r = 0;
		q++;
	}
	return matrix;

}

int 		*find_path(t_room **rooms, int* matrix, unsigned int length){
	int 	*path;
	int 	length_path;
	int 	q;
	t_room	*current_room;


	length_path = 1;
	q = 0;
	path = ft_memalloc(sizeof (int));
	path[0] = rooms[0]->number;
	current_room = rooms[0];

	clean_status(rooms, length);

	while(current_room->number != length - 1){
		while(q < current_room->count_ways)
		{
			if (current_room->ways[q]->status != -1	&&
			check_path_by_matrix(matrix, current_room, current_room->ways[q], length) == 1){
				path = ft_realloc_int(path, length_path);
				path[length_path] = current_room->ways[q]->number;
				length_path++;
				current_room = current_room->ways[q];
				break;
			}
			if (q + 1 == current_room->count_ways){
				current_room->status = -1;
				current_room = get_last_room(rooms, length, path);
			}
			if (current_room->number == 0){
				if (check_end_find_path(current_room, length) == 1){
					length_path = 0;
					free(path);
					break;
				}
			}
			q++;
		}
		q = 0;
	}

	for(unsigned int i = 0; i < length_path; i++){
		ft_printf("-%d", path[q]);
	}

	return path;

	//	Найти путь от начала до конца.
	//  Путь не должен повторяться.
	// 	Сохранить новый путь в матрицу.
}

int 		check_end_find_path(t_room *curr, unsigned int length){
	unsigned q;

	q = 0;
	while(q < length){
		if(curr->ways[q]->status != -1)
			return (0);
		q++;
	}
	return 1;
}

t_room		*get_last_room(t_room **rooms, unsigned int length, int last_room_num){
	unsigned int q;

	q = 0;
	while(q < length){
		if (rooms[q]->number == last_room_num){
			return rooms[q];
			break;
		}
		q++;
	}
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

int		*ft_realloc_int(int **exist_arr, unsigned int length){
	unsigned q;
	int		*res;
	int		*arr;

	q = 0;
	arr = *exist_arr;
	res = ft_memalloc(sizeof (int) * (length + 1));
	while (q < length){
		res[q] = arr[q];
		q++;
	}
	free(arr);
	return res;
}

void clean_status(t_room **rooms, unsigned int length){
	unsigned int q;

	q = 0;
	while(q < length){
		rooms[q]->status = 0;
		q++;
	}
}





