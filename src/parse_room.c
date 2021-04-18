//
// Created by Hugor Chau on 4/18/21.
//
#include "lem-in.h"

void    fill_coordinates(int *x, int *y, char *str)
{
    int     i;

    i = 0;
    while (str[i] && str[i] != ' ')
    {
        if (!ft_isdigit(str[i]))
            error_management("Forbidden symbol.");
        i++;
    }
    *x = ft_atoi(str);
    str += i + 1;
    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != ' ')
            error_management("Forbidden symbol.");
        i++;
    }
    *y = ft_atoi(str);
}

void    fill_the_room(t_room *room, int fd)
{
    char    *line;
    char    *poses;

    if (get_next_line(fd, &line) != 1)
        error_management("Map error");
    if (line == NULL)
        error_management("Malloc error. Shut down.");
    poses = ft_strchr(line, ' ');
    if (poses == NULL)
    {
        error_management("No coordinates for room. Change map.");
        return ;
    }
    *poses = '\0';
    room->name = ft_strnew(line);
    *poses = ' ';
    fill_coordinates(&room->x, &room->y, poses);
}

int     new_room(t_room **start, t_room **end, t_room **cur, char *line)
{
    if (cur == NULL || end == NULL || start == NULL || line == NULL)
        return (-1);
    *cur = ft_memalloc(sizeof(t_room));
    if (*cur == NULL)
        error_management("Malloc error. Shut down.");
    if (ft_strequ(line, "##start"))
    {
        if (*start == NULL)
            *start = *cur;
        else
            error_management("Two start directive. Please, change map.");
    }
    if (ft_strequ(line, "##end"))
    {
        if (*end == NULL)
            *end = *cur;
        else
            error_management("Two end directive. Please, change map.");
    }
    return (0);
}
