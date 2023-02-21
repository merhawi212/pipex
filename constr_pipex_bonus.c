/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constr_pipex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:22:09 by mkiflema          #+#    #+#             */
/*   Updated: 2023/02/20 22:26:31 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

int	get_pid(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("pid error");
		exit(4);
	}
	return (pid);
}

void	ft_creat_pipe(int x, int *fd[])
{
	int	y;

	y = 0;
	while (y < x)
	{
		if (pipe(fd[y]) < 0)
		{
			perror("pipe error");
			exit(0);
		}
		y++;
	}
}

void	close_pipes(int *fd[], int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		close(fd[i][0]);
		close(fd[i++][1]);
	}
}
