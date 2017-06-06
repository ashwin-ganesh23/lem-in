/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 21:36:48 by aganesh           #+#    #+#             */
/*   Updated: 2016/07/18 21:36:49 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	put_error()
{
	ft_putstr("Error\n");
	exit (0);
}

ssize_t		ft_max_atoi(char *str)
{
	size_t	num;
	int		sign;
	int		p;

	num = 0;
	sign = 1;
	p = 0;
	while (space(*str))
		str++;
	if (str[p] == '-')
	{
		sign = -1;
		p++;
	}
	else if (str[p] == '+')
		p++;
	while ((str[p] >= '0') && (str[p] <= '9'))
	{
		num = num * 10 + (str[p] - '0');
		p++;
	}
	num = num * sign;
	return (num);
}

int     valid_int(char *str)
{
	if (ft_max_atoi(str) > INT_MAX || ft_max_atoi(str) < INT_MIN)
		return (0);
	if (*str == '-')
		str++;
	while (*str != 0)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
