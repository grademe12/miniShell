#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	// char *argv[] = { "/usr/bin", NULL };
    // char *envp[] = { NULL };

	// if (execve("/usr/bin", argv, envp) == -1)
	// 	perror("what");
	// if (access("/usr/bin", X_OK) == 0)
	// 	printf ("yes\n");
	int	fd[2];
	pipe(fd);
	pid_t pid;
	pid = fork();
	if (pid == 0) {
		printf ("this is\n");
		return (0);
	}
	return (0);
}