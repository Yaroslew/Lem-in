#include "lem-in.h"

void parser(s_room *rooms)
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


int main(void){

    int graf[5][2] = {{1,2}, {0,4}, {0,3}, {2,4},{1,3}};
    s_room rooms[5];
    parser((s_room *)rooms);

    int steps = get_way((int **)graf, 5);

    return 0;
}

int get_way(int **graf, int rooms_count){

    int q = 0;
    int r = 0;
    char *queue[rooms_count];
    s_vertex verts[rooms_count];

    queue[0] = 0;

    while(q < rooms_count){

        verts[queue[q]].status = 1;
        verts[queue[q]].weight = q;
        r = 0;
        while(r < graf[queue[q]].length)
        {
            queue[ft_free_ind(queue)] =
        }
    }
    // создать очередь.
    // Создать матрицу
    // Найти путь.

    return 0;
}

int     ft_free_ind(int **arr){
    int q = 0;

    while (q < arr.length)
    {
        if (arr[q] != null)
            return q;
        q++;
    }
}
