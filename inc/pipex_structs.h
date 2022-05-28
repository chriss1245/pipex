/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <cmanzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:59:19 by cmanzano          #+#    #+#             */
/*   Updated: 2022/05/28 13:41:24 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCTS_H
# define PIPEX_STRUCTS_H

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

typedef struct s_pipe
{
	int	in;
	int	out;
	int	**pipes;
} t_pipe;

#endif
