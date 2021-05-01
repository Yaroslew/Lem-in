//
// Created by Hugor Chau on 5/1/21.
//
#include "lem-in.h"

static void	skip_whitespaces(char **str, int i)
{
	while ((*str)[i] && (*str)[i] == ' ')
		i++;
	(*str) = (*str) + i;
}

static void	parse_names(char *line, char **name, char **roommate_name)
{
	int		i;

	i = 0;
	skip_whitespaces(&line, 0);
	*name = line;
	while (line[i] && line[i] != '-')
		i++;
	if (!line[i])
		error_management("parse_roommates: name error");
	line[i] = '\0';
	*roommate_name = line + i + 1;
}

static void	connect_roommates(t_room *room, t_room *roommate)
{
	t_room	**tmp;
	int		i;

	i = 0;
	tmp = ft_memalloc((room->count_ways + 2) * (sizeof(t_room *)));
	while (i < room->count_ways)
	{
		tmp[i] = room->ways[i];
		i++;
	}
	tmp[i] = roommate;
	if (room->count_ways != 0)
		free(room->ways);
	room->ways = tmp;
	room->count_ways++;
}

static void	get_roommate(char *line, t_room **rooms, unsigned int length)
{
	t_room	*room;
	t_room	*roommate;
	char	*name;//on stack
	char	*roommate_name;//on stack
	int		i;

	i = 0;
	room = NULL;
	roommate = NULL;
	parse_names(line, &name, &roommate_name);
	if (ft_strequ(name, roommate_name))
		error_management("get_roommate: room cannot be roommate to itself");
	while (i < length)
	{
		if (room && roommate)
			break ;
		if (ft_strequ(rooms[i]->name, name))
			room = rooms[i];
		if (ft_strequ(rooms[i]->name, name))
			roommate = rooms[i];
		i++;
	}
	if (!room || !roommate)
		error_management("get_roommate: roommate parse error");
	connect_roommates(room, roommate);
}

void	parse_roommates(t_list *file, t_room **rooms, unsigned int length)
{
	while (file && file->content && **(char **)(file->content))
	{
		if (parse_comment(&file))
			;
		else
		{
			get_roommate(*(char **)file->content, rooms, length);
			file = file->next;
		}
	}
}
