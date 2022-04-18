#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	receiver(int sig, siginfo_t *info, void *data)
{
	pid_t	pid;
	static int		c;
	static int		i;

	(void)data;
	pid = info->si_pid;
	if (sig == SIGUSR2)
		c += 128;
	if (i < 7)
		c >>= 1;
	i++ ;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	// if (sig == SIGUSR1)
	// 	printf("0\n");
	// else
	// 	printf("1\n");
}

int main()
{
	pid_t pid;
	struct sigaction	sa;
	
	sa.sa_sigaction = receiver;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		pause();
	}
	return (0);
}