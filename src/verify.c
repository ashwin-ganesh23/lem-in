/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 21:36:48 by aganesh           #+#    #+#             */
/*   Updated: 2016/07/18 21:36:49 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	verify(t_env *env)
{
	t_list	*rm;
	t_list	*a;
	t_list	*b;

	if (!env->start || !env->end)
		put_error();
	rm = env->rooms;
	while (rm)
	{
		a = (t_room *)rm->content->links;
		while (a)
		{
			b = (t_room *)rm->content->links;
			while (b)
			{
				if (a != b && ft_strequ((t_room *)a->content->name,
				 (t_room *)b->content->name)
				 	put_error();
				b = b->next;
			}
			a = a->next;
		}
		rm = rm->next;
	}
}

void 	check_rooms(t_env *env)
{
	t_list	*a;
	t_list	*b;

	a = env->rooms;
	while (a)
	{
		b = env->rooms;
		while (b)
		{
			if (a == b)
			{
				b = b->next;
				continue;
			}
			if (ft_strcmp(a->content->name, b->content->name) != 0)
				put_error();
			b = b->next;
		}
		a = a->next;
	}
}
