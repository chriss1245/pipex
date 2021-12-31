#include "../inc/pipex.h"

int main(int nargs, char **vargs, char **env)
{
	t_command	*cmds;
	int **pipes;
	int fd[2];	
	t_auxiliar	temp;
	pid_t		pid;
	
	fd[0] = open("lol.txt", O_RDONLY);
	fd[1] = open("carlitos.txt", O_WRONLY | O_TRUNC);
	cmds = command_parser(nargs, vargs, env);
	if (nargs < 5)
		return (0);
	pipes = (int **) ft_calloc(nargs - 4, sizeof(int*));
	temp.i = 0;
	while (temp.i < nargs - 4)
	{
		pipes[temp.i] = (int *) ft_calloc(2, sizeof(int));
		pipe(pipes[temp.i]);
		temp.i++;
	}
	temp.i = 0;
	pid = fork();
	if (pid)
	{
		wait(&pid);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		dup2(pipes[0][1], 1);
		close(pipes[0][1]);
		close(pipes[0][0]);
		execve(cmds[0].cmd, cmds[0].vargs, env);
		write(2, "error", 5);
	}
	pid = fork();
	if (pid)
	{
		close(pipes[0][0]);
		close(pipes[0][1]);
		wait(&pid);
		close(fd[0]);
		close(fd[1]);
	}
	else
	{
		if(dup2(pipes[0][0], 0) == - 1)
			write(2, "error dup pipes stdin", 21);
		close(pipes[0][1]);
		if(dup2(fd[1], 1)<0)
			write(2, "error dup fd stdin", 18);
		close(fd[1]);
		execve(cmds[1].cmd, cmds[1].vargs, env);
		write(2, "error", 5);
	}
/*
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
*/
}
