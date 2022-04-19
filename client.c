#include <unistd.h>
#include <signal.h>
#include "libft/ft_atoi.c"
#include "libft/ft_putstr_fd.c"

void	send_binary(int pid, char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++ ;
		usleep(42);
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		send_binary(pid, str[i]);
	send_binary(pid, 0);
}

int main(int argc, char **argv)
{
	pid_t pid;
	char *str;
	if (argc < 3)
	{
		ft_putstr_fd("No message inputted.\n", 1);
		exit(EXIT_FAILURE);
	}
	else if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		ft_putstr_fd("Sending Signals.\n", 1);
		send_message(pid, str);
		signal(SIGUSR1, received_message);
		signal(SIGUSR2, received_message);
	}
	return (0);
}