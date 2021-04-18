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



int    read_map(int fd)
{
    t_list      *tmp_lst;
    t_room      *begin;
    t_room      *end;
    char        *line;
    t_room      *cur;

    tmp_lst = NULL;
    begin = NULL;
    end = NULL;
    while (get_next_line(fd, &line))
    {
        if (parse_comment(line))
            continue ;
        if (is_a_room(line))
            new_room(&begin, &end, &cur, line);
        else
            break ;
        fill_the_room(cur, fd);
        ft_lstadd(&tmp_lst, ft_lstnew(cur, sizeof(t_room *)));
    }
    if (tmp_lst == NULL)
        error_management("Map is empty.");
    return (0);
}
