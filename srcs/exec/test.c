#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
	char *argv[] = { "/usr/bin", NULL };
    char *envp[] = { NULL };

	if (execve("/usr/bin", argv, envp) == -1)
		perror("what");
	if (access("/usr/bin", X_OK) == 0)
		printf ("yes\n");
	
	return (0);
}