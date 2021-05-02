#define TEMP_LENGTH 5


#include "lem-in.h"

int     open_file(int ac, char **av, int *fd)
{
    if (ac < 2)
        error_management("too few arguments\nusage:\n./lem_in filename");
    *fd = open(av[1], O_RDONLY);
    ft_printf("map name = %s\nfd = %d\n", av[1], *fd);
    if (*fd <= 2)
        return (-1);
    return (0);
}

void			read_whole_file(t_list **read_line, int ac, char **av)
{
	char        	*line;
	t_list			*tmp;
	int				fd;

	if (open_file(ac, av, &fd) != 0)
		error_management("open error");
	*read_line = NULL;
	while (get_next_line(fd, &line))
	{
		if (*read_line == NULL)
		{
			*read_line = ft_lstnew(&line, sizeof(char **));
			tmp = *read_line;
		}
		else
		{
			tmp->next = ft_lstnew(&line, sizeof(char **));
			tmp = tmp->next;
		}
		tmp->next = NULL;
	}
}

void		parser(t_list *whole_file, t_room ***rooms_res, unsigned int *length, unsigned int *ants)
{
	int     fd;

	//костыль, позже уберём
	if (rooms_res == NULL || length == NULL)
		error_management("parser: unexpected error");
//	read_whole_file(&whole_file, fd);
	read_map(whole_file, rooms_res, length, ants);
}
