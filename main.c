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
	int	fd1;
	int	fd2;

	if (argc != 5)
	{
		ft_printf("Usage: %s input_file cmd1 cmd2 output_file\n", argv[0]);
		return (1);
	}
	fd1 = open(argv[1], O_RDONLY, 0777);
	if (fd1 == -1)
	{
		perror("open input file is not exits or file is not readable");
		exit(0);
	}
	fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd2 == -1)
	{
		perror("open output file is not exits or file is not readable");
		exit(1);
	}
	ft_pipex(fd1, fd2, argv, envp);
	close(fd1);
	close(fd2);
	return (0);
}
