/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:04:43 by mkiflema          #+#    #+#             */
/*   Updated: 2023/02/22 12:52:04 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>
# include "./libft/libft.h"

char	*split_prog(char *arg);
char	*ft_get_paths(char *envp, char *arg);
int		ft_search_path( char **s1, char *s2);
void	ft_child_process_one(int fd[], char **argv, char **envp, int i);
void	ft_child_process_two(int fd[], char **argv, char **envp, int i);

#endif