/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:53:04 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/22 20:02:15 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strlinen(char **buf)
{
	int				i;
	int				j;
	char			*str;
	char			*str_copy;

	i = 0;
	j = 0;
	str_copy = *buf;
	if (str_copy == '\0')
		return (NULL);
	while (str_copy[i] != '\0' && str_copy[i] != '\n')
		++i;
	if (!(str = (char*)malloc(sizeof(char) + i + 1)))
		return (NULL);
	while (i >= j)
	{
		str[j] = str_copy[j];
		j++;
	}
	str_copy = ft_strdup(&str_copy[j]);
	free(*buf);
	*buf = str_copy;
	str[j - 1] = '\0';
	return (&str[0]);
}

static char		*ft_copyread(const int fd)
{
	char				str_buf[BUFF_SIZE + 1];
	char				*str_text;
	char				*str_free;
	int					ret;

	if (!(str_text = (char*)malloc(sizeof(char) + BUFF_SIZE + 1)))
		return (NULL);
	*str_text = '\0';
	if ((ret = read(fd, str_buf, 0) < 0))
		return (NULL);
	while ((ret = read(fd, str_buf, BUFF_SIZE)) > 0)
	{
		str_buf[ret] = '\0';
		str_free = str_text;
		str_text = ft_strjoin(str_text, str_buf);
		free(str_free);
	}
	return (str_text);
}

int				ft_refund(char **buf)
{
	char	*str;
	int		i;

	i = 0;
	str = *buf;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	if (str[i] == '\0')
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char			*buf[FD_MAX];
	int					refund;

	if (0 > fd || fd > 11000 || !line)
		return (-1);
	if (!buf[fd])
	{
		if (!(buf[fd] = ft_copyread(fd)))
			return (-1);
	}
	refund = ft_refund(&buf[fd]);
	if (*buf[fd] == '\0')
	{
		free(buf[fd]);
		buf[fd] = NULL;
		return (0);
	}
	if (!(*line = ft_strlinen(&buf[fd])))
		return (-1);
	if (refund == 0)
	{
		*buf[fd] = '\0';
		return (1);
	}
	return (1);
}
