#include "lem-in.h"

void            parser(s_room *rooms)
{
    for(int i = 0; i < 5; i++)
    {
        rooms[i].name = (char *)malloc(sizeof (char)*2);
    }
    rooms[0].name = "R0";
    rooms[1].name = "R1";
    rooms[2].name = "R2";
    rooms[3].name = "R3";
    rooms[4].name = "R4";

    rooms[0].ways = (char **)malloc(sizeof(char*) * 2);
    rooms[0].ways[0] = (char *) malloc(sizeof(char) * 2);
    rooms[0].ways[0][0] = "R1";
    rooms[0].ways[0][1] = "R2";

    rooms[1].ways = (char **)malloc(sizeof(char*) * 2);
    rooms[1].ways[0] = (char *) malloc(sizeof(char) * 2);
    rooms[1].ways[0][0] = "R0";
    rooms[1].ways[0][1] = "R4";

    rooms[2].ways = (char **)malloc(sizeof(char*) * 2);
    rooms[2].ways[0] = (char *) malloc(sizeof(char) * 2);
    rooms[2].ways[0][0] = "R0";
    rooms[2].ways[0][1] = "R3";

    rooms[2].ways = (char **)malloc(sizeof(char*) * 2);
    rooms[2].ways[0] = (char *) malloc(sizeof(char) * 2);
    rooms[2].ways[0][0] = "R2";
    rooms[2].ways[0][1] = "R4";

    rooms[2].ways = (char **)malloc(sizeof(char*) * 2);
    rooms[2].ways[0] = (char *) malloc(sizeof(char) * 2);
    rooms[2].ways[0][0] = "R1";
    rooms[2].ways[0][1] = "R3";

}


int				main(void){
    // тестовые данные.
    int         length = 5; // количество комнат.

    // парсер и проверки правильности карт. Получение массива комнат.
    s_room rooms[length];
    parser((s_room *)rooms);

    // Поиск в ширину и Эдмондс-Карп.
    get_way((s_room *)rooms, 5);

    // Отрисовка муравьев(без принтф желательно => скорость).
    return 0;
}

void            get_way(s_room *rooms, int length){

    int         q = 0;
    int         r = 0;
    char        **queue = (char**)malloc(sizeof (char*) * length);
    s_vertex    *vertexs = (t_vertex*) malloc(sizeof(t_vertex)*length);

    insert_in_queue(queue, rooms[0], length);

    // Поиск в ширину.
    while(q < length){

    }
    // Матрица смежности.
    // repeat пока есть пути.

    // Комнаты-призраки??..?....
    return 0;
}

void            insert_in_queue(char **queue,  t_room room, int length){

    int         q = 0;

    while(q < length){
        if (queue[q] == null)
            break;
    }
    queue[q] = room.name;
}

void            insert_in_vertexs(){

}
//int     ft_free_ind(int **arr){
//    int q = 0;
//
//    while (q < arr.length)
//    {
//        if (arr[q] != null)
//            return q;
//        q++;
//    }
//}
