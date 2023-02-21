/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:30:47 by mkiflema          #+#    #+#             */
/*   Updated: 2023/02/21 12:15:02 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char *envp[])
{
	int	fd[2];
	int	i;

	if (argc != 5)
	{
		ft_printf("Usage: %s input_file cmd1 cmd2 output_file\n", argv[0]);
		return (1);
	}
	i = ft_search_path(envp, "PATH=");
	ft_child_process_one(fd, argv, envp, i);
	ft_child_process_two(fd, argv, envp, i);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}
