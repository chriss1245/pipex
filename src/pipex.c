/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <cmanzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:30:13 by chris             #+#    #+#             */
/*   Updated: 2022/05/28 17:03:50 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// makes the required piping for the parent process
static void	parent_pipe(int *pipefd)
{
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	close(pipefd[1]);
}

// makis the piping for the child process
static void child_pipe(int *pipefd, int counter, int *fd, int ncmds)
{
	if (counter == 0)
		dup2(fd[0], 0);
	if (counter == ncmds - 1)
		dup2(fd[1], 1);
	else
	{
		dup2(pipefd[1], 1);
	}
	close_pipe(fd);
	close_pipe(pipefd);
}

/*this child process reads and seands using a pipe
the text from stdin until reaching the delimiter
using only read*/
static void head_document(int *pipefd, char *delimiter){
	char buffer[20];
	

	close(pipefd[0]);
	while (read(0, buffer, 20) > 0)
	{
		if (ft_strnstr(buffer, delimiter, 20) != 0)
			break;
		write(pipefd[1], buffer, 20);
	}
	close(pipefd[1]);
	exit(0);
}


/* Forks the child processes and pipes them to the main
program */
int	pipex(t_command *cmds, int ncmds, int *fd, char *delimiter)
{
	int			i;
	int			pipefd[2];
	pid_t		pid;

	i = 0;
	while (i < ncmds)
	{
		pipe(pipefd);
		pid = fork();
		if (pid == 0)
		{
			if (delimiter && i == 0)
				head_document(pipefd, delimiter);
			else
			{
				child_pipe(pipefd, i, fd, ncmds);
				execve(cmds[i].cmd, cmds[i].vargs, cmds[i].env);
			}
		}
		else
		{
			parent_pipe(pipefd);
			waitpid(pid, NULL, 0);
			if (delimiter && i == 0)
				delimiter = 0;
			else
				i++;
		}
	}
	return (0);
}

