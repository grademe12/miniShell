#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv, char **envp)
{
	char *doc;

	doc = (char *)malloc(sizeof(strlen("/tmp/doc") + 1));
	strlcpy(doc, "/tmp/doc", strlen("/tmp/doc") + 1);
	printf ("%s\n", doc);
	return (0);
}