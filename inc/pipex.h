/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:59:19 by cmanzano          #+#    #+#             */
/*   Updated: 2021/12/31 16:47:46 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/inc/libft.h"
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_command 
{
	char	*cmd;
	char	**vargs;
	char	**env;
} t_command;

typedef struct s_auxiliar
{
	char	*str;
	char	**strs;
	int		i;
	int		j;
	int		k;
	char	c;
} t_auxiliar;

char		*get_environ_val(char **env, char *var);
t_command	*command_parser(int nargs, char **vargs, char **env);
#endif
