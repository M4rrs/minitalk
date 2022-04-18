#include <unistd.h>
#include "libft/ft_atoi.c"
#include <stdio.h>
#include <signal.h>

void	send_binary(int pid, char *str)
{
	int i;
	int j;
	int	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		j = 0;
		while (j < 8)
		{
			if (c % 2 == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			j++;
			c >>= 1;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	pid_t pid;
	char *str;
	if (argc > 1)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_binary(pid, str);
		printf("pid = %d, str = %s\n", pid, str);
	}
	return (0);
}