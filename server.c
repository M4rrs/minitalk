#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	sig_handling(int sig)
{
	printf("Hi Jordan\n");
}

int main()
{
	pid_t pid;

	signal(SIGUSR1, sig_handling);
	pid = getpid();
	printf("%d\n", pid);
	while (1)
	{
		pause();
	}
	return (0);
}