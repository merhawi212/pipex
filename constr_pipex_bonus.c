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

char	**update_argv(char **argv)
{
	char	**temp;
	int		i;
	int		j;

	temp = malloc(ft_double_strlen(argv) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	j = 0;
	while (i < 2)
		temp[j++] = argv[i++];
	i++;
	while (argv[i])
		temp[j++] = argv[i++];
	temp[j] = 0;
	return (temp);
}
