/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:26:45 by mkiflema          #+#    #+#             */
/*   Updated: 2023/02/22 19:10:47 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

int	ft_search_path( char **s1, char *s2)
{
	int	i;
	int	j;
	int	c;

	j = 0;
	c = 0;
	while (s1[j])
	{
		i = 0;
		while (s1[j][i] && i < 5)
		{
			if (s1[j][i] != s2[i])
			{
				c = 0;
				break ;
			}
			c++;
			i++;
		}
		if (c == 5)
			return (j);
		j++;
	}
	return (0);
}

int	ft_double_strlen(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char	*copy_prog(char *arg, int i, int j)
{
	char	*res;
	int		k;

	k = 0;
	res = malloc(sizeof(char) * (j + 2));
	if (!res)
		return (NULL);
	i = i - j;
	res[k++] = '/';
	while (arg[i] && j--)
		res[k++] = arg[i++];
	res[k] = '\0';
	return (res);
}

char	*split_prog(char *arg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arg[i] && (arg[i] == ' '))
		i++;
	while (arg[i] && (arg[i] != ' '))
	{
		j++;
		i++;
	}
	return (copy_prog(arg, i, j));
}

char	*ft_get_paths(char *envp, char *arg)
{
	char	*joined;
	char	**result;
	char	*prog;
	int		i;

	if (!arg || !arg[0])
		return (0);
	if (access(arg, F_OK) == 0)
		return (arg);
	result = ft_split(envp + 5, ':');
	prog = split_prog(arg);
	i = 0;
	while (result[i])
	{
		joined = ft_strjoin(result[i++], prog);
		if (access(joined, F_OK) == 0)
			return (joined);
		free(joined);
	}
	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
	free(prog);
	return (0);
}
