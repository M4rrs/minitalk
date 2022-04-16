#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	sig_handling(int sig, siginfo_t *siginfo, void *data)
{
	(void)siginfo;
	(void)data;
	printf("Received:");
	
}

int main()
{
	pid_t pid;
	struct sigaction	sa;
	
	sa.sa_sigaction = sig_handling;
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