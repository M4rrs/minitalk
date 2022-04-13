#include <unistd.h>
#include "libft/ft_atoi.c"
#include <stdio.h>
#include <signal.h>

int main(int argc, char **argv)
{
	pid_t pid;
	char *str;

	pid = ft_atoi(argv[1]);
	str = argv[2];
	kill(pid, SIGUSR1);
	printf("pid = %d, str = %s\n", pid, str);
	return (0);
}