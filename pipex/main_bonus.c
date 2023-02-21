/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:37:06 by mkiflema          #+#    #+#             */
/*   Updated: 2023/02/20 22:49:10 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"
#include <stdio.h>

int	main(int argc, char **argv, char *envp[])
{
	int	len;

	if (argc < 5)
	{
		ft_printf("Usage: %s inputfile cmd1 ....cmdn outputfile", argv[0]);
		exit(0);
	}
	len = argc - 4;
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		len--;
	ft_pipex_bonus(argv, envp, len);
	return (0);
}
