/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:49:27 by adrherna          #+#    #+#             */
/*   Updated: 2023/12/18 16:05:13 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

void	ft_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*ft_pathfinder(char **envp, char *cmd)
{
	char	**paths;
	char	*temp;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i] != 0)
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) == 0)
		{
			ft_free_arr(paths);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_arr(paths);
	return (NULL);
}

int	ft_exec(char *argv, char **envp)
{
    char	*path;
    char	**cmds;

    cmds = ft_split(argv, ' ');
    path = ft_pathfinder(envp, cmds[0]);
    if (path == NULL)
    {
        ft_free_arr(cmds);
        return -1;
    }
    if (execve(path, cmds, envp) != 0)
    {
        free(path);
        ft_free_arr(cmds);
        return -1;
    }
    free(path);
    ft_free_arr(cmds);
    return 0;
}
