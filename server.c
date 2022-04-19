#include <signal.h>
#include <unistd.h>
#include "libft/ft_putchar_fd.c"
#include "libft/ft_putnbr_fd.c"
#include "libft/ft_putstr_fd.c"

// void	receiver(int sig, siginfo_t *info, void *data)
// {
// 	pid_t	client_pid;
// 	static int		c;
// 	static int		i;

// 	(void)data;
// 	client_pid = info->si_pid;
// 	if (sig == SIGUSR2)
// 		c += 128;
// 	if (i < 7)
// 		c >>= 1;
// 	i++ ;
// 	if (i == 8)
// 	{
// 		write(1, &c, 1);
// 		c = 0;
// 		i = 0;
// 	}
// }
void	sig_handler(int sig, siginfo_t *info, void *data)
{
	int	i;
	int	bit;
	static int	c;

	(void)data;
	if (sig == SIGUSR2)
		bit = 0;
	else
		bit = 1;
	if (i < 7)
	{
		c += bit;
		c <<= i;
	}
	i ++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
		{
			write(1, '\n', 1);
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
		c = 0;
	}
}

int main()
{
	pid_t pid;
	struct sigaction	sa;
	
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putstr_fd("Talk to me!\n", 1);
	ft_putstr_fd("Sever PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}