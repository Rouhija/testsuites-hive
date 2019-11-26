#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	test_read(char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
}

void	test_return(char *file)
{
	int		fd;
	int		ret;
	char	*line;

	printf("%d\n", get_next_line(42, &line));
	fd = open(file, O_RDONLY);
	printf("%d\n", get_next_line(fd, &line));
	while ((ret = get_next_line(fd, &line)));
	printf("%d\n", ret);
}

void	test_bonus(char *f1, char *f2)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open(f1, O_RDONLY);
	fd2 = open(f2, O_RDONLY);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
}

int		main(int ac, char **av)
{
	char *str = malloc(sizeof(char) * 10);
	*str = 'A';
	if (ac == 2)
		test_read(av[1]);
	if (ac == 3)
		test_return(av[1]);
	if (ac == 4)
		test_bonus(av[1], av[2]);
	if (ac == 5)
		while (1);
	return (0);
}