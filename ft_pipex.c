/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:22:39 by mkiflema          #+#    #+#             */
/*   Updated: 2023/02/22 17:16:23 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static int	ft_get_child_two_pid(int fd[])
{
	int		pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		close(fd[0]);
		exit(1);
	}
	return (pid);
}

void	ft_child_process_two(int fd[], char **argv, char **envp, int i)
{
	int	fd2;

	if (ft_get_child_two_pid(fd) == 0)
	{
		fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		dup2(fd[0], 0);
		dup2(fd2, 1);
		close(fd2);
		close(fd[1]);
		close(fd[0]);
		if (!ft_get_paths(envp[i], argv[3]))
		{
			ft_putstr_fd("cmd not found\n", 2);
			exit(1);
		}
		if (execve(ft_get_paths(envp[i], argv[3]),
				ft_split(argv[3], ' '), envp) == -1)
		{
			perror("execve");
			exit(1);
		}
		exit(0);
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
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork eror");
		close(fd[0]);
		exit(1);
	}
	return (pid);
}

static int	open_file(char *str)
{
	int	fd1;

	fd1 = open(str, O_RDONLY, 0777);
	if (fd1 == -1)
	{
		ft_putstr_fd("file is not valid or available\n", 2);
		exit(1);
	}
	return (fd1);
}

void	ft_child_process_one(int fd[], char **argv, char **envp, int i)
{
	int	fd1;

	if (ft_get_child_one_pid(fd) == 0)
	{
		fd1 = open_file(argv[1]);
		close(fd[0]);
		dup2(fd1, 0);
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd1);
		if (!ft_get_paths(envp[i], argv[2]))
		{
			ft_putstr_fd("cmd not found\n", 2);
			exit(1);
		}
		if (execve(ft_get_paths(envp[i], argv[2]), ft_split(argv[2], ' '),
				envp) == -1)
		{
			perror("execve");
			exit(1);
		}
		exit(0);
	}
	close(fd[1]);
}
