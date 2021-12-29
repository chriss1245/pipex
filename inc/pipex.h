/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:59:19 by cmanzano          #+#    #+#             */
/*   Updated: 2021/12/29 17:11:37 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/inc/libft.h"
# include <sys/wait.h>
# include <string.h>
#include <stdio.h>

typedef struct s_command 
{
	char	*cmd;
	char	**vargs;
	char	**env;
} t_command;
t_command	*command_parser(int nargs, char **vargs, char *path, char **env);
#endif
