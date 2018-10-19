/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:39:31 by clingier          #+#    #+#             */
/*   Updated: 2018/10/16 16:47:29 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# define FD_LIMIT 4864
# define BUFF_SIZE 4096
# include <unistd.h>
# include <libft.h>

int		get_next_line(int fd, char **str);

#endif
