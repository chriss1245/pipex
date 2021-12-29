/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:01:52 by cmanzano          #+#    #+#             */
/*   Updated: 2021/12/29 17:12:31 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void free_all(t_command *cmds, int n);

static void deep_free(char **matrix)
{
	int	i;

	i = 0;
	while(matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

t_command	*command_parser(int nargs, char **vargs, char *path, char **env)
{
	char		**paths;
	int			i;
	char		*aux;
	char		**cmd;
	t_command	*cmds;
	int			j;

	cmds = (t_command *) ft_calloc(nargs - 3, sizeof(t_command));
	paths = ft_split(path, ':');
	i = 2;
	while (i < nargs - 1)
	{
		cmd = ft_split(vargs[i], ' ');
		j = 0;
		
		cmds[i - 2].vargs = cmd;
		cmds[i - 2].env = env;
		aux = ft_strjoin("/", cmd[0]);
		cmds[i - 2].cmd = ft_strjoin(paths[j], aux);
		while (access(cmds[i - 2].cmd, X_OK) == -1 && paths[j])
		{
			free(cmds[i - 2].cmd);
			j++;
			cmds[i - 2].cmd = ft_strjoin(paths[j], aux);
		}
		free(aux);
		if (!paths[j])
		{
			deep_free(paths);
			free_all(cmds, i - 1);
			perror(0);
			return (0);
		}
		i++;
	}
	deep_free(paths);
	return (cmds);
}

static void free_all(t_command *cmds, int n)
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
