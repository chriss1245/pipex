/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <cmanzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:20:00 by chris             #+#    #+#             */
/*   Updated: 2022/05/28 13:46:38 by cmanzano         ###   ########.fr       */
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
