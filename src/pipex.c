/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <cmanzano@student.42Madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:30:13 by chris             #+#    #+#             */
/*   Updated: 2021/12/31 17:35:58 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	rec_pipex(t_list *node)
{
	int	pipefds[2];

	if (pipe(pipefds) != -1)
	{
			strerror(errno);
	}
}

int	pipex(t_list **lst, int *fd)
{
	int	pipefds[2];

	if (pipe(pipefds) != -1)
	{
			strerror(errno);
	}
}
