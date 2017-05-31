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

	s = env->start;
	cl = s->links;
	if (s == env->end)

}

int		lem_in(t_env *env, t_room *curr)
{
	t_list	*tmp;

	if (curr == env->end)
		return (lst);
	tmp = curr->links;
	while (tmp)
	{
		if (*(t_room **)tmp)
	}
}

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

int		parse_num_ants(char	*str)
{
	if (!valid_int(str))
		put_error();
	if (ft_atoi(str) <= 0)
		put_error();
	return (ft_atoi(str));
}

int		parse_line(t_env *env, char *str, int mode)
{
	int		mode;
	int		start;
	int		end;

	start = 0;
	if (mode == 0)
	{
		if (!valid_int(str))
			put_error();
		env->ants = ft_atoi(str);
		mode == 1;
	}
	else if (mode == 1)
	{

	}
	else if (mode == 2)
	{

	}
}

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
