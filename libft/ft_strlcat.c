/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:52:57 by clingier          #+#    #+#             */
/*   Updated: 2018/10/07 19:52:58 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t destsize)
{
	size_t len_d;
	size_t len_s;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	if (destsize < len_d)
		return (destsize + len_s);
	if (len_s < destsize - len_d)
		ft_strncat(dst, src, len_s + 1);
	else
	{
		ft_strncat(dst, src, destsize - len_d - 1);
		dst[destsize] = '\0';
	}
	return (len_d + len_s);
}
