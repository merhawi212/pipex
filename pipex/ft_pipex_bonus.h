/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:44:57 by mkiflema          #+#    #+#             */
/*   Updated: 2023/02/20 22:49:51 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdlib.h>

# include "./libft/libft.h"

int		ft_double_strlen(char **str);
int		ft_search_path( char **s1, char *s2);
char	*ft_get_paths(char *envp, char *arg);
void	ft_creat_pipe(int x, int **fd);
int		get_pid(void);
void	close_pipes(int *fd[], int len);
void	ft_pipex_bonus(char **argv, char *envp[], int len);
char	**here_doc(int *fd[], char **argv, char *path, int len);

#endif