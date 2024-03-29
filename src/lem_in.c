/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 21:36:48 by aganesh           #+#    #+#             */
/*   Updated: 2016/07/18 21:36:49 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(int ac, char **av)
{
	t_env	*env;
	char	**lines;

	env = (t_env *)ft_memalloc(sizeof(t_env));
	if (ac != 2)
		put_error();
	parse_lines(env);
	verify(env);
	solver(env);
}

void 	solver(t_env *env)
{
	t_room	*s;
	t_list	*cl;

	if (!env->end || !env->start)
		put_error();
	s = env->start;
	cl = s->links;

}

t_list		lem_in(t_env *env, t_link *curr)
{
	t_list	*tmp;

	if (!curr)
		return (NULL);
	if (!seen)
		seen = ft_lstnew();
	tmp = curr->links;
	while (tmp)
	{
		if (*(t_room **)tmp)
	}
}
