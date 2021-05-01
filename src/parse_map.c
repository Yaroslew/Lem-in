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

static void	skip_whitespaces(char **str, int i)
{
	while ((*str)[i] && (*str)[i] == ' ')
		i++;
	(*str) = (*str) + i;
}

void	parse_ants(t_list **tmp_file, unsigned int *ants)
{
	char	*ants_num;
	int		i;
	t_list	*tmp;
	int		j;

	i = 0;
	tmp = *tmp_file;
	while (tmp)
	{
		ants_num = *(char **)(tmp->content);
		tmp = tmp->next;
		if (!ants_num || !*ants_num)
			continue;
		i++;
		j = 0;
		skip_whitespaces(&ants_num, 0);
		ft_putendl(ants_num);
		while (ants_num[j])
		{
			if (!ft_isdigit(ants_num[j]))
				error_management("parse ants: forbidden symbol");
			j++;
		}
		if (j != 0)
		{
			*ants = ft_atoi(ants_num);
			break ;
		}
	}
	if (i == 0 || *ants == 0)
		error_management("Map is empty or no ants provided!");
	*tmp_file = tmp;
}

void	check_repeats(t_room **rooms_res, unsigned int length)
{
	int		i;
	int		j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length)
		{
			if (rooms_res[j] == rooms_res[i])
			{
				j++;
				continue ;
			}
			if (rooms_res[i]->x == rooms_res[j]->x &&
					rooms_res[i]->y == rooms_res[j]->y)
				error_management("check_repeats: Error: coordinates for 2 rooms are equal");
			j++;
		}
		i++;
	}
}

//как понять, что внутри есть цикл?
int	check_existing_way(t_room **rooms, unsigned int length, t_room *cur)
{
	int		j;

	j = 0;
	if (cur == rooms[length - 1])
	{
		cur->status = 0;
		return (1);
	}
	if (cur == NULL || cur->count_ways == 0)
	{
		cur->status = 0;
		return (0);
	}
	while (j < cur->count_ways)
	{
		if (cur->ways[j]->status == 1)
			return (0);
		cur->ways[j]->status = 1;
		if (check_existing_way(rooms, length, cur->ways[j]))
		{
			cur->ways[j]->status = 0;
			return (1);
		}
		j++;
	}
	cur->status = 0;
	return 0;
}

int    read_map(t_list *whole_file, t_room ***rooms_res, unsigned int *length, unsigned int *ants)
{
	t_list      *tmp_lst;
	t_room      *begin;
	t_room      *end;
	t_list		*tmp;

	tmp_lst = NULL;
	begin = NULL;
	end = NULL;
	tmp = whole_file;
	parse_ants(&tmp, ants);
	*length = read_map_rooms(&tmp, &tmp_lst, &begin, &end);
	*rooms_res = create_array(tmp_lst, begin, end, *length);
	check_res(*rooms_res, *length);
	parse_roommates(tmp, *rooms_res, *length);
	check_repeats(*rooms_res, *length);
	if (!check_existing_way(*rooms_res, *length, **rooms_res))
		error_management("read_map: No way from ##start to ##end");
	ft_putendl("Ok");
}
