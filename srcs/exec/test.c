#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
	int i = 0;
	while (envp[i] != 0)
	{
		printf ("%s\n", envp[i]);
		i++;
	}
	printf ("%c\n", envp[i][0]);
	return (0);
}