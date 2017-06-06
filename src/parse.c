/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 21:36:48 by aganesh           #+#    #+#             */
/*   Updated: 2016/07/18 21:36:49 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void 	parse_lines(t_env *env)
{
	char 	*str;
	int		mode;
	int		start;
	int		end;

	mode = 0;
	start = 0;
	end = 0;
	while (get_next_line(1, &str) == 1)
	{
		if (mode++ == 0)
			env->ants = parse_num_ants(str);
		else if (mode == 1)
			parse_rooms(env, str, start, end, mode);
		if (mode == 2)
		{
			if (ft_get_size(str, '-') == 2 &&
			 str[0] != '-' && str[ft_strlen(str) - 1] != '-')
			 	put_error();
			parse_links(env, str);
		}
		ft_putendl(str);
		free(str);
	}
}

int		parse_num_ants(char	*str)
{
	if (!valid_int(str))
		put_error();
	if (ft_atoi(str) <= 0)
		put_error();
	return (ft_atoi(str));
}

int		parse_rooms(t_env *env, char *str, int start, int end, int mode)
{
	if (str[0] == 'L')
		put_error();
	if (ft_strcmp(str, "##start") == 0)
		start += 1;
	else if (ft_strcmp(str, "##end") == 0)
		end += 1;
	else if (ft_get_size(str, '-') == 2 && ft_get_size(str, ' ') == 1)
	{
		if (!env->start || !env->end)
			put_error();
		if (mode == 1)
			check_rooms(env);
		map->mode++;
	}
	else
		parse_room(env, str, start, end, mode);
}

int		parse_room(t_env *env, char *str, int start, int end, int mode)
{
	char	**details;

	if ((start == 1 || end == 1) && ft_get_size(str, ' ') != 3)
	 	put_error();
	else if (str[i] == '#')
		;
	else if (ft_get_size(str, ' ') == 3)
	{
		details = ft_strsplit(str, ' ');
		if (!valid_int(details[1] || !valid_int(details[2]))
			put_error();
		create_room(env, &start, &end, details);
	}
	else
		put_error();
	return (1);
}

void	parse_links(t_env *env, char *str)
{
	t_room	*a;
	t_room	*b;
	t_list	*tmp;
	char	**details;

	details = ft_strsplit(str, '-');
	tmp = env->rooms;
	a = 0;
	b = 0;
	while (tmp)
	{
		if (ft_strequ(details[0], (*(t_room **)tmp->content->name)))
			a = *(t_room **)tmp->content;
		if (ft_strequ(details[1], (*(t_room **)tmp->content->name)))
   			b = *(t_room **)tmp->content;
		tmp = tmp->next;
	}
	if (a && b && a != b)
	{
		ft_lstadd(&(a->links), ft_lstnew(&b, sizeof(t_room *)));
		ft_lstadd(&(a->links), ft_lstnew(&b, sizeof(t_room *)));
	}
	else
		put_error();
}
