//
// Created by Hugor Chau on 4/18/21.
//
#include "lem-in.h"

static void	skip_whitespaces(char **str, int i)
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

void    fill_the_room(t_room *room, t_list **file)
{
    char    *line;
    char    *poses;

    if (file == NULL || *file == NULL)
        error_management("Map error - room is not defined correctly");
    line = *(char **)(*file)->content;
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
    room->count_ways = 0;
    room->status = 0;
    room->ways = NULL;
    room->weight = 0;
	(*file) = (*file)->next;
	fill_coordinates(&room->x, &room->y, poses);
}

int	define_directive(t_room **def, t_room **cur, t_list **file, char *directive_name)
{
	char	*line;

	line = *(char **)(*file)->content;
	if (ft_strequ(line, directive_name))
	{
		if (*def == NULL)
			*def = *cur;
		else
			return (-1);
		*file = (*file)->next;
	}
	return (0);
}

int     new_room(t_room **start, t_room **end, t_room **cur, t_list **file)
{
    if (cur == NULL || end == NULL || start == NULL || file == NULL || *file == NULL)
        return (-1);
    *cur = ft_memalloc(sizeof(t_room));
    if (*cur == NULL)
        error_management("Malloc error. Shut down.");
	if (define_directive(start, cur, file, "##start"))
		error_management("Two start directive. Please, change map.");
	else if (define_directive(end, cur, file, "##end"))
		error_management("Two end directive. Please, change map.");
//	fill_the_room(cur, fd);
	return (0);
}
