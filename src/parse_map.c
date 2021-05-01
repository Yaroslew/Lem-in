//
// Created by Hugor Chau on 4/18/21.
//

#include "lem-in.h"

int     parse_comment(t_list **file)
{
	char	*line;

	line = *(char **)(*file)->content;
    if (!*line || (*line == '#' && line[1] != '#'))
	{
		(*file) = (*file)->next;
		return (1);
	}
    return (0);
}

int     is_a_room(char *line)
{
    static char     rooms_ended = 1;

    if (line == NULL)
        return (0);
    if (ft_strchr(line, '-'))
        rooms_ended = 0;
    return (rooms_ended);
}

//2) get_next_line - all file in tmp lst
//3) remember start and end
//4) fill boxes

int    read_map_rooms(t_list **file, t_list **tmp_lst, t_room **begin, t_room **end)
{
    char        	*line;
    t_room      	*cur;
    int	size;

    size = 0;
    while ((*file))
    {
    	line = *(char **)(*file)->content;
        if (parse_comment(&(*file)))
            continue ;
        if (is_a_room(line))
            new_room(begin, end, &cur, &(*file));
        else
            break ;
        fill_the_room(cur, &(*file));
        if (cur != *begin && cur != *end)
	        ft_lstadd(tmp_lst, ft_lstnew(&cur, sizeof(t_room **)));
        size++;
    }
    if (*tmp_lst == NULL && *begin == NULL && *end == NULL)
        error_management("Map is empty.");
    if (*begin == NULL)
		error_management("No start!");
	if (*end == NULL)
		error_management("No end!");
	return (size);
}

t_room	**create_array(t_list *tmp_lst, t_room *begin, t_room *end, unsigned int size)
{
	t_room			**rooms;
	int	i;

	i = 1;
	rooms = ft_memalloc((sizeof (t_room *)) * (size + 1));
	rooms[0] = begin;
	while (tmp_lst)
	{
		if (i >= size - 1)
			error_management("parser error");
		rooms[i] = *(t_room **)(tmp_lst->content);
		tmp_lst = tmp_lst->next;
		i++;
	}
	rooms[size - 1] = end;
	rooms[size] = NULL;
	return (rooms);
}

void	check_res(t_room **room, unsigned int length)
{
	int		i = 0;
	t_room	*res;
	while (i < length)
	{
		res = room[i];
		ft_printf("name = %s, count_ways = %d, x = %d, y = %d, status = %d, weight = %d\n",
			res->name, res->count_ways, res->x, res->y, res->status, res->weight);
		i++;
	}
}

int    read_map(t_list *whole_file, t_room ***rooms_res, unsigned int *length)
{
	t_list      *tmp_lst;
	t_room      *begin;
	t_room      *end;
	t_list		*tmp;

	tmp_lst = NULL;
	begin = NULL;
	end = NULL;
	tmp = whole_file;
	*length = read_map_rooms(&tmp, &tmp_lst, &begin, &end);
	*rooms_res = create_array(tmp_lst, begin, end, *length);
	check_res(*rooms_res, *length);
	parse_roommates(tmp, *rooms_res, *length);
	ft_putendl("Ok");
}
