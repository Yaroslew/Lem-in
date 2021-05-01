//
// Created by Hugor Chau on 4/18/21.
//

#include "lem-in.h"

int     parse_comment(const char *line)
{
    if (!*line || (*line == '#' && line[1] != '#'))
        return (1);
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

unsigned int    read_map_rooms(int fd, t_list **tmp_lst, t_room **begin, t_room **end)
{
    char        	*line;
    t_room      	*cur;
    unsigned int	size;

    size = 0;
    while (get_next_line(fd, &line))
    {
        if (parse_comment(line))
            continue ;
        if (is_a_room(line))
            new_room(begin, end, &cur, line);
        else
            break ;
        fill_the_room(cur, fd);
        if (cur != *begin && cur != *end)
	        ft_lstadd(tmp_lst, ft_lstnew(cur, sizeof(t_room *)));
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
	unsigned int	i;

	i = 1;
	rooms = ft_memalloc((sizeof (t_room *)) * (size + 1));
	rooms[0] = begin;
	while (tmp_lst)
	{
		if (i >= size - 1)
			error_management("parser error");
		rooms[i] = tmp_lst->content;
		tmp_lst = tmp_lst->next;
		i++;
	}
	rooms[size - 1] = end;
	rooms[size] = NULL;
	return (rooms);
}

int    read_map(int fd, t_room ***rooms_res, unsigned int *length)
{
	t_list      *tmp_lst;
	t_room      *begin;
	t_room      *end;

	tmp_lst = NULL;
	begin = NULL;
	end = NULL;
	*length = read_map_rooms(fd, &tmp_lst, &begin, &end);
	*rooms_res = create_array(tmp_lst, begin, end, *length);
}