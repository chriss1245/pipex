/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <cmanzano@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:20:00 by chris             #+#    #+#             */
/*   Updated: 2022/05/30 13:13:47 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*get_environ_val(char **environ, char *var)
{
	int		i;
	char	*val;
	char	*temp;
	char	*temp2;	
	i = 0;
	val = 0;
	temp = ft_strjoin(var, "=");
	temp2 = 0;
	while (environ[i] && !temp2)
	{
		temp2 =  ft_strnstr(environ[i], temp, ft_strlen(temp));
		i++;
	}	
	if (!temp2)
		ft_printf("(environ[i] && !val)F \n");
	val = ft_strjoin("", temp2 + ft_strlen(temp));
	free(temp);
	return (val);
}

int close_pipe(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}


void	exit_failure(char *param, int err)
{
	ft_putstr_fd("pipex: ", 2);
	if (err == CMD_NOT_FOUND)
		ft_putstr_fd("command not found: ", 2);
	if (err == NO_FILE)
		ft_putstr_fd("no such file or directory: ", 2);
	if (err == NO_PERM)
		ft_putstr_fd("permission denied: ", 2);
	if (err == CMD_FAIL)
		ft_putstr_fd("command failed: ", 2);
	if (err == INV_ARGS)
		ft_putstr_fd("invalid number of arguments", 2);
	if (err == NO_MEMORY)
		ft_putstr_fd("no memory left on device", 2);
	if (err == DUP_ERR)
		ft_putstr_fd("could not dup fd", 2);
	if (err == PIPE_ERR)
		ft_putstr_fd("could not create pipe", 2);
	if (err == FORK_ERR)
		ft_putstr_fd("could not fork process", 2);
	if (err == NO_PATH)
		ft_putstr_fd("PATH variable is not set", 2);
	if (param && (err == CMD_NOT_FOUND || err == NO_FILE || err == NO_PERM || \
			err == CMD_FAIL))
		ft_putstr_fd(param, 2);
	ft_putstr_fd("\n", 2);
	system("leaks pipex");
	exit(EXIT_FAILURE);
}