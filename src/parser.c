/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <cmanzano@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:01:52 by cmanzano          #+#    #+#             */
/*   Updated: 2022/06/01 19:53:26 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void deep_free(char **matrix)
{
	int	i;

	i = 0;
	ft_printf("deep_free of %p\n", matrix);
	while(matrix[i])
	{
		ft_printf("freeing %p\n", matrix[i]);
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void free_all(t_command *cmds, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(cmds[i].cmd);
		deep_free(cmds[i].vargs);
		i++;
	}
	free(cmds);
}

t_command	*command_parser(int nargs, char **vargs, char **env)
{
	char		**paths;
	t_auxiliar	aux;
	char		**cmd;
	t_command	*cmds;

	cmds = (t_command *) ft_calloc(nargs - 3, sizeof(t_command));
	aux.str	= get_environ_val(env, "PATH");
	paths = ft_split(aux.str, ':');
	free(aux.str);
	aux.i = 2;
	while (aux.i < nargs - 1)
	{
		cmd = ft_split(vargs[aux.i], ' ');
		aux.j = 0;
		ft_printf("parsing %s\n", vargs[aux.i]);
		
		cmds[aux.i - 2].vargs = cmd;
		cmds[aux.i - 2].env = env;
		aux.str = ft_strjoin("/", cmd[0]);
		cmds[aux.i - 2].cmd = ft_strjoin(paths[aux.j], aux.str);
		while (access(cmds[aux.i - 2].cmd, X_OK) == -1 && paths[aux.j])
		{
			free(cmds[aux.i - 2].cmd);
			aux.j++;
			cmds[aux.i - 2].cmd = ft_strjoin(paths[aux.j], aux.str);
		}
		free(aux.str);
		if (!paths[aux.j])
		{
			deep_free(paths);
			
			ft_printf("%s: command not found\n", cmd[0]);
			free_all(cmds,  aux.i - 1);

			
			exit_failure("", CMD_NOT_FOUND);
		}
		aux.i++;
	}
	deep_free(paths);
	return (cmds);
}