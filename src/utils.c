/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <cmanzano@student.42Madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:20:00 by chris             #+#    #+#             */
/*   Updated: 2021/12/29 19:44:00 by chris            ###   ########.fr       */
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
