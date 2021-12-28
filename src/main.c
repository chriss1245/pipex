#include "../inc/pipex.h"

int main(int nargs, char **vargs, char **env)
{
	int pipe1[2];
	int pipe2[2];
	int fd = open("lol.txt", O_WRONLY);
	
	if (nargs < 1)
		return (0);
	pipe(pipe1);
	int pid = fork();
	if (pid)
	{
		wait(&pid);
		close(pipe1[1]);
	}
	else
	{
		dup2(pipe1[1], 1);
		close(pipe1[1]);
		close(pipe1[0]);
		execve("ls", vargs, env);
		write(2, "error", 5);
	}
	pipe(pipe2);
	pid = fork();
	if (pid)
	{
		wait(&pid);
	}
	else
	{
		dup2(pipe1[0], 0);
		dup2(fd, 1);
		close(pipe2[1]);
		close(pipe2[0]);
		execve("/usr/bin/grep", vargs, env);
		write(2, "error", 5);
	}
}
