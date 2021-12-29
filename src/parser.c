/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:01:52 by cmanzano          #+#    #+#             */
/*   Updated: 2021/12/29 12:30:01 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

t_command	*command_parser(int nargs, char **vargs, char *path)
{
	char		**paths;
	int			i;
	char		**cmd;
	t_command	*cmds;

	cmds = (t_command *) ft_calloc(nargs - 3, sizeof(t_command));
	paths = ft_split(path, ':');
	i = 2;
	
	while (i < nargs - 1)
	{
		cmd = ft_split(vargs[i], ' ');
		while (access(cmds -> cmd) == -1)
		{
			cmds -> 
		}
		ft_printf("%s ", *cmd);
		while (*++cmd)
		{
			ft_printf("%s ", *cmd);
		}
		ft_printf("\n");
		i++;
	}
	return (cmds);
}
