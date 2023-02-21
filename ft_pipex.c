/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:22:39 by mkiflema          #+#    #+#             */
/*   Updated: 2023/02/21 12:39:41 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include <stdio.h>

static int	ft_get_child_two_pid(int fd[])
{
	int		pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		close(fd[0]);
		exit(10);
	}
	return (pid);
}

static void	ft_child_process_two(int fd[], char **argv, char **envp, int i)
{
	int fd2;

	if (ft_get_child_two_pid(fd) == 0)
	{
		fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (fd2 == -1)
		{
			ft_putstr_fd("cmd not foun\n", 2);
			exit(7);

		}
		ft_printf("f2 %d:\n", fd2);
		dup2(fd[0], 0);
		dup2(fd2, 1);
		close(fd2);
		close(fd[0]);
		close(fd[1]);
		if (!ft_get_paths(envp[i], argv[3]))
		{
			ft_putstr_fd("cmd not foun\n", 2);
			exit(7);
		}
		else
		{
			if (execve(ft_get_paths(envp[i], argv[3]),
					ft_split(argv[3], ' '), envp) == -1)
			{
				perror("execve");
				exit(8);
			}
		}
		exit(9);
	}
	close(fd[0]);
}

static int	ft_get_child_one_pid(int fd[])
{
	int		pid;

	if (pipe(fd) == -1)
	{
		perror("pipe error");
		close(fd[0]);
		exit(5);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork eror");
		close(fd[0]);
		exit(6);
	}
	return (pid);
}

static void	ft_child_process_one(int fd[], char **argv, char **envp, int i)
{
	int	fd1;
	char *temp;

	if (ft_get_child_one_pid(fd) == 0)
	{
		fd1 = open(argv[1], O_RDONLY, 0777);
		if (fd1 == -1)
		{
			ft_putstr_fd("cmd not foun\n", 2);
			exit(7);

		}
		ft_printf("f1 %d:\n", fd1);
		close(fd[0]);
		dup2(fd1, 0);
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd1);
		temp = ft_get_paths(envp[i], argv[2]);
		if (!temp)
		{
			free(temp);
			ft_putstr_fd("cmd not foun\n", 2);
			exit(2);
		}
		if (execve(temp, ft_split(argv[2], ' '),
					envp) == -1)
		{
			perror("execve");
			exit(3);
		}
		free(temp);
		exit(4);
	}
	close(fd[1]);
}

void	ft_pipex(char **argv, char*envp[])
{
	int	fd[2];
	int	i;

	i = ft_search_path(envp, "PATH=");
	ft_child_process_one(fd, argv, envp, i);
	ft_child_process_two(fd, argv, envp, i);
	close(fd[0]);
	close(fd[1]);
	// close(fd1);
	// close(fd2);
	wait(NULL);
	wait(NULL);
}
