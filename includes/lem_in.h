#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <libft.h>
# include <get_next_line.h>

typedef	struct	s_room
{
    char	*name;
	t_list	*links;
    int		x;
	int		y;

}				t_room;

typedef	struct	s_env
{
	int		ants;
	t_room	*start;
	t_room	*end;
	t_list	*rooms;
	t_list	*path;
}				t_env;

#endif
