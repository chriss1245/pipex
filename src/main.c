/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <cmanzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:24:49 by cmanzano          #+#    #+#             */
/*   Updated: 2022/05/28 18:05:13 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int main(int nargs, char **vargs, char **env)
{
	t_command	*cmds;
	int			fd[2];	

	if (nargs < 5)
		return (0);
	if (ft_strnstr(vargs[1], "head_document", ft_strlen(vargs[1])) != 0)
	{
		if (nargs < 6)
			return(0);
		fd[0] = dup(0);
	}
	fd[0] = open(vargs[1], O_RDONLY);
	fd[1] = open(vargs[nargs - 1], O_WRONLY | O_TRUNC);
	cmds = command_parser(nargs, vargs, env);
	pipex(cmds, nargs - 3, fd);
	close_pipe(fd);
	return (0);
}