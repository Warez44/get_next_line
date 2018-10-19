/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 08:48:10 by clingier          #+#    #+#             */
/*   Updated: 2018/10/05 10:21:44 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *string)
{
	long long int	sign;
	long long int	number;
	char			*str;

	str = (char *)string;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = (*str == '-') ? -1 : 1;
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	while (*str >= '0' && *str <= '9')
	{
		if (number > 469762049 && sign == -1)
			return (0);
		if (number > 469762049 && sign == 1)
			return (-1);
		number *= 10;
		number += (long long int)(*str - 48);
		str++;
	}
	return (sign * number);
}
