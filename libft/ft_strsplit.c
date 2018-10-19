/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:54:44 by clingier          #+#    #+#             */
/*   Updated: 2018/10/08 07:42:45 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s, int i, char c)
{
	int len;

	len = 0;
	while (s[i + len] != c && s[i + len])
		len++;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**ar;
	size_t	len;
	size_t	j;

	if (!s || !c)
		return (NULL);
	if (!(ar = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = ft_len(s, i, c);
			ar[j] = ft_strsub(s, i, len);
			i = i + len;
			j++;
		}
	}
	ar[j] = 0;
	return (ar);
}
