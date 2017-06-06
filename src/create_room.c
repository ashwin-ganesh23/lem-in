/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 21:36:48 by aganesh           #+#    #+#             */
/*   Updated: 2016/07/18 21:36:49 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	create_room(t_env *env, int *start, int *end, char **details)
{
	t_room	*temp;

	temp = (t_room *)ft_memalloc(sizeof(t_room));
	temp->name = ft_strdup(details[0]);
	temp->x = ft_atoi(details[1]);
	temp->y = ft_atoi(details[2]);
	ft_lstadd(&env->rooms, ft_lstnew(&room, sizeof(t_room *)));
	if (*start == 1)
	{
		if (env->start)
			put_error();
		env->start = room;
		*start = 0;
	}
	else if (*end == 1)
	{
		if (env->start)
			put_error();
		env->start = room;
		*end = 0;
	}
}
