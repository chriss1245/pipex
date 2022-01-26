#include "../inc/pipex.h"

int main(int nargs, char **vargs, char **env)
{
	t_command	*cmds;
	int **pipes;
	int fd[2];	
	t_auxiliar	temp;
	pid_t		pid;
	
	if (nargs < 5)
		return (0);
	fd[0] = open(vargs[1], O_RDONLY);
	fd[1] = open(vargs[nargs - 1], O_WRONLY | O_TRUNC);
	cmds = command_parser(nargs, vargs, env);
	pipes = (int **) ft_calloc(nargs - 4, sizeof(int*));
	temp.i = 0;
	while (temp.i < nargs - 4)
	{
		pipes[temp.i] = (int *) ft_calloc(2, sizeof(int));
		pipe(pipes[temp.i]);
		temp.i++;
	}
	pid = fork();
	if (pid)
		wait(&pid);
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		dup2(pipes[0][1], 1);
		close(pipes[0][1]);
		close(pipes[0][0]);
		close(pipes[1][1]);
		close(pipes[1][0]);
		execve(cmds[0].cmd, cmds[0].vargs, env);
		write(2, "error", 5);
	}
	temp.i = 0;
	while (temp.i < nargs - 5)
	{
		pid = fork();
		if (pid)
		{
			close(pipes[temp.i][1]);
			wait(&pid);
		}
		else
		{
	
			if (dup2(pipes[temp.i][0], 0) == -1)
				write(2, "error dup pipes stdin", 21);
			close(fd[0]);
			close(fd[1]);
			dup2(pipes[temp.i + 1][1], 1);
			close(pipes[0][1]);
			close(pipes[0][0]);
			close(pipes[temp.i + 1][1]);
			close(pipes[temp.i + 1][0]);
			execve(cmds[temp.i + 1].cmd, cmds[temp.i + 1].vargs, env);
			write(2, "error", 5);
		}
		ft_printf("Imprime \n");
		temp.i++;
	}

	pid = fork();

	if (pid)
	{

		close(pipes[temp.i][1]);
		wait(&pid);
		close(fd[0]);
		close(fd[1]);
	}
	else
	{
		if(dup2(pipes[temp.i][0], 0) == - 1)
			write(2, "error dup pipes stdin", 21);
		if(dup2(fd[1], 1)<0)
			write(2, "error dup fd stdin", 18);
		close(fd[1]);
		close(pipes[temp.i][1]);
		execve(cmds[1].cmd, cmds[1].vargs, env);
		write(2, "error", 5);
	}
}
