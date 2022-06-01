/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <cmanzano@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:59:19 by cmanzano          #+#    #+#             */
/*   Updated: 2022/05/31 13:50:42 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/inc/libft.h"
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

enum e_pipex_error
{
	END = 1,
	CMD_NOT_FOUND = 0,
	NO_FILE = -1,
	NO_PERM = -2,
	INV_ARGS = -3,
	NO_MEMORY = -4,
	PIPE_ERR = -5,
	DUP_ERR = -6,
	FORK_ERR = -7,
	NO_PATH = -8,
	CMD_FAIL = -9
};

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
int			pipex(t_command *cmds, int nargs, int *fd, char *delimiter);
int			close_pipe(int *pipefd);
void		exit_failure(char *message, int status);
void		free_all(t_command *cmds, int nargs);
#endif