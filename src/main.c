/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <cmanzano@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:24:49 by cmanzano          #+#    #+#             */
/*   Updated: 2022/05/30 12:56:55 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int main(int nargs, char **vargs, char **env)
{
	t_command	*cmds;
	int			fd[2];
	char		*delimiter;
	
	if (nargs < 5)
			exit_failure("", INV_ARGS);
	

	delimiter = 0;
	if (ft_strnstr(vargs[1], "head_document", ft_strlen(vargs[1])) != 0)
	{
		if (nargs < 6)
			exit_failure("", INV_ARGS);
		delimiter = vargs[2];
		cmds = command_parser(nargs - 1, vargs + 1, env);
		
		fd[1] = open(vargs[nargs - 1], O_APPEND | O_TRUNC);
		pipex(cmds, nargs - 4, fd, delimiter);
	}
	else
	{
		cmds = command_parser(nargs, vargs, env);
		fd[0] = open(vargs[1], O_RDONLY);
		fd[1] = open(vargs[nargs - 1], O_WRONLY | O_TRUNC);
		pipex(cmds, nargs - 3, fd, delimiter);
	}
	close_pipe(fd);
	return (0);
}