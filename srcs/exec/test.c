#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

void	abc(int **fd)
{
	int fds[2];

	printf ("new fds : %p\n", fds);

	*fd = fds;
}

int main(int argc, char **argv, char **envp)
{
	int	*fd[2];
	
	printf ("%p\n", *fd);
	printf ("%p\n", fd);

	abc(fd);

	printf ("%p\n", *fd);
	printf ("%p\n", fd);
	return (0);
}