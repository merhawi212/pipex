/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:17:36 by mkiflema          #+#    #+#             */
/*   Updated: 2023/02/22 18:51:37 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

static char	**update_argv(char **argv)
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

static void	first_child(int *fd[], char **argv, char *path, int len)
{
	int	fd1;

	if (get_pid() == 0)
	{
		fd1 = open("tmp.txt", O_RDWR);
		dup2(fd1, STDIN_FILENO);
		dup2(fd[0][1], STDOUT_FILENO);
		close(fd1);
		close_pipes(fd, len);
		if (!ft_get_paths(path, argv[3]))
		{
			ft_putstr_fd("cmd not foun\n", 2);
			exit(2);
		}
		if (execve(ft_get_paths(path, argv[3]),
				ft_split(argv[3], ' '), NULL) == -1)
		{
			perror("execve");
			exit(8);
		}
	}
}

char	**here_doc(int *fd[], char **argv, char *path, int len)
{
	int		fd1;
	char	*line;

	fd1 = open("tmp.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	while (get_next_line(STDIN_FILENO, &line))
	{
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			break ;
		}
		write(fd1, line, ft_strlen(line));
		write(fd1, "\n", 1);
		free(line);
	}
	free(line);
	close(fd1);
	first_child(fd, argv, path, len);
	return (update_argv(argv));
}
