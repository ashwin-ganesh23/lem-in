#include "lem_in.h"

int		main(int ac, char **av)
{
	char *str;

	if (ac == 2)
		printf("%s\n", av[1]);

	while (get_next_line(1, &str) == 1)
	{
		printf("%s\n", str);
	}
	return (0);
}
