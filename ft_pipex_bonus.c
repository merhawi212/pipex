/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:13:24 by mkiflema          #+#    #+#             */
/*   Updated: 2023/02/22 19:15:05 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

static void	ft_last_child_proc(int *fd[], char **argv, char *path, int len)
{
	int	fd2;

	if (get_pid() == 0)
	{
		fd2 = open(argv[len + 3], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		dup2(fd[len - 1][0], STDIN_FILENO);
		close_pipes(fd, len);
		dup2(fd2, STDOUT_FILENO);
		close(fd2);
		if (!ft_get_paths(path, argv[len + 2]))
		{
			ft_putstr_fd("cmd not found\n", 2);
			exit(4);
		}
		if (execve(ft_get_paths(path, argv[len + 2]),
				ft_split(argv[len + 2], ' '), NULL) == -1)
		{
			perror("execve error");
			exit(8);
		}
		exit(9);
	}
}

static void	ft_child_pro_middle(int *fd[], char **argv, char *path, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (get_pid() == 0)
		{
			dup2(fd[i - 1][0], 0);
			dup2(fd[i][1], 1);
			close_pipes(fd, len);
			if (!ft_get_paths(path, argv[i + 2]))
			{
				ft_putstr_fd("cmd not found\n", 2);
				exit(2);
			}
			if (execve(ft_get_paths(path, argv[i + 2]),
					ft_split(argv[i + 2], ' '), NULL) == -1)
			{
				perror("execve");
				exit(8);
			}
			exit(4);
		}
		i++;
	}
}

static int	open_file(char *str)
{
	int	fd1;

	fd1 = open(str, O_RDONLY, 0777);
	if (fd1 == -1)
	{
		ft_putstr_fd("cmd not found\n", 2);
		close(fd1);
		exit(7);
	}
	return (fd1);
}

static void	ft_child_pro_one(int *fd[], char **argv, char *path, int len)
{
	int	fd1;

	if (get_pid() == 0)
	{
		fd1 = open_file(argv[1]);
		dup2(fd1, STDIN_FILENO);
		dup2(fd[0][1], STDOUT_FILENO);
		close(fd1);
		close_pipes(fd, len);
		if (!ft_get_paths(path, argv[2]))
		{
			ft_putstr_fd("cmd not found\n", 2);
			exit(2);
		}
		if (execve(ft_get_paths(path, argv[2]),
				ft_split(argv[2], ' '), NULL) == -1)
		{
			perror("execve");
			exit(8);
		}
		exit(4);
	}
}

void	ft_pipex_bonus(char **argv, char *envp[], int len)
{
	int	**fd;
	int	i;

	fd = (int **)malloc(len * sizeof(int *));
	if (!fd)
		return ;
	i = 0;
	while (i < len)
		fd[i++] = (int *)malloc(2 * sizeof(int));
	ft_creat_pipe(len, fd);
	i = ft_search_path(envp, "PATH=");
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		argv = here_doc(fd, argv, envp[i], len);
	else
		ft_child_pro_one(fd, argv, envp[i], len);
	if (len > 1)
		ft_child_pro_middle(fd, argv, envp[i], len);
	ft_last_child_proc(fd, argv, envp[i], len);
	close_pipes(fd, len);
	i = -1;
	while (++i < (len + 1))
		wait(NULL);
}
