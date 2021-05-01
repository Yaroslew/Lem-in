//
// Created by Hugor Chau on 4/18/21.
//
#include "lem-in.h"

void	skip_whitespaces(char **str, int i)
{
	while ((*str)[i] && (*str)[i] == ' ')
		i++;
	(*str) = (*str) + i;
}

void    fill_coordinates(int *x, int *y, char *str)
{
    int     i;

    i = 0;
	skip_whitespaces(&str, i);
    while (str[i] && str[i] != ' ')
    {
        if (!ft_isdigit(str[i]))
            error_management("Forbidden symbol.");
        i++;
    }
    *x = ft_atoi(str);
	skip_whitespaces(&str, i);
    i = 0;
    while (str[i] && str[i] != ' ')
    {
        if (!ft_isdigit(str[i]))
            error_management("Forbidden symbol.");
        i++;
    }
    *y = ft_atoi(str);
	skip_whitespaces(&str, i);
	if (*str)
		error_management("Forbidden symbol.");
}

void    fill_the_room(t_room *room, int fd)
{
    char    *line;
    char    *poses;

    if (get_next_line(fd, &line) != 1)
        error_management("Map error - room is not defined correctly");
    if (line == NULL)
        error_management("Malloc error. Shut down.");
    poses = ft_strchr(line, ' ');
    if (poses == NULL)
    {
        error_management("No coordinates for room. Change map.");
        return ;
    }
    *poses = '\0';
    room->name = ft_strdup(line);
    *poses = ' ';
    fill_coordinates(&room->x, &room->y, poses);
}

int	define_directive(t_room **def, t_room **cur, char *line, char *directive_name)
{
	if (ft_strequ(line, directive_name))
	{
		if (*def == NULL)
			*def = *cur;
		else
			return (-1);
	}
	return (0);
}

int     new_room(t_room **start, t_room **end, t_room **cur, char *line)
{
    if (cur == NULL || end == NULL || start == NULL || line == NULL)
        return (-1);
    *cur = ft_memalloc(sizeof(t_room));
    if (*cur == NULL)
        error_management("Malloc error. Shut down.");
	if (define_directive(start, cur, line, "##start"))
		error_management("Two start directive. Please, change map.");
	else if (define_directive(end, cur, line, "##end"))
		error_management("Two end directive. Please, change map.");
//	fill_the_room(cur, fd);
	return (0);
}
