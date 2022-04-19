#include <unistd.h>
#include <signal.h>
#include "libft/ft_atoi.c"
#include "libft/ft_putstr_fd.c"

void	received_message(int sig)
{
	static int	received;
	if (sig == SIGUSR1)
		received++ ;
	
}
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
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		ft_putstr_fd("Sending Signals.\n", 1);
		send_binary(pid, str);
		signal(SIGUSR1, received_message);
		signal(SIGUSR2, received_message);
	}
	return (0);
}