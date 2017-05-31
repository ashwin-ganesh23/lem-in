#include "../includes/lem_in.h"

int		main()
{
	//int fd = 0;
	char	*buffer;
	// fgets(buffer, BUFFERSIZE, stdin);
	// printf("%s\n", buffer);
	//int		r;

	printf("test\n");
	while (get_next_line(0, &buffer) == 1)
		printf("%s\n", buffer);
	// if (ac == 2)
	// 	printf("%s\n", av[1]);
	//
	// while (get_next_line(0, &str))
	// {
	// 	printf("test\n");
	// }
	return (0);
}
