#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	receiver(int sig, siginfo_t *info, void *data)
{
	pid_t	pid;
	static int		c;
	int		i;

	(void)data;
	pid = info->si_pid;
	i = 0;
	if (sig == SIGUSR2)
		c += 128;
	if (i < 7)
		c >>= 1;
	i++ ;
	if (i == 8)
	{
		printf("%c\n", c);
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
	printf("%d\n", pid);
	while (1)
	{
		pause();
	}
	return (0);
}