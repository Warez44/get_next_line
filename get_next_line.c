/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:21:40 by clingier          #+#    #+#             */
/*   Updated: 2018/10/19 13:06:37 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_getline(int fd, char **files, char **line)
{
	char *temp;
	char *cur;

	cur = ft_strchr(files[fd], '\n');
	temp = files[fd];
	*cur = '\0';
	*line = ft_strdup(files[fd]);
	files[fd] = ft_strdup(cur + 1);
	free(temp);
}

static void		ft_get_content(int fd, char **files)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = files[fd];
		if (!(files[fd] = ft_strjoin(files[fd], buf)))
			return ;
		free(temp);
		if (ft_strchr(files[fd], '\n'))
			break ;
	}
}

int				get_next_line(int fd, char **line)
{
	static char *files[FD_LIMIT];

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, files, 0) < 0)
		return (-1);
	if (!files[fd])
		files[fd] = ft_strnew(1);
	ft_get_content(fd, files);
	if (files[fd] == NULL)
		return (-1);
	if (ft_strchr(files[fd], '\n'))
	{
		ft_getline(fd, files, line);
		return (1);
	}
	if (*files[fd])
	{
		*line = ft_strdup(files[fd]);
		files[fd] = ft_strnew(1);
		return (1);
	}
	return (0);
}
