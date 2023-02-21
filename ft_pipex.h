/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:04:43 by mkiflema          #+#    #+#             */
/*   Updated: 2023/02/13 13:33:31 by mkiflema         ###   ########.fr       */
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

void	ft_pipex(char **argv, char*envp[]);
char	*split_prog(char *arg);
char	*ft_get_paths(char *envp, char *arg);
int		ft_search_path( char **s1, char *s2);
// char	**ft_split(char const *s, char c);
// char	*ft_strjoin(char const *s1, char const *s2);
// size_t	ft_strlcat(char *dst, const char *src, size_t size);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// size_t	ft_strlen(const char *s);

#endif