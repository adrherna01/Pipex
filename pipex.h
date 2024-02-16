/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:10:17 by adrherna          #+#    #+#             */
/*   Updated: 2023/12/18 16:05:31 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

char		*ft_pathfinder(char **envp, char *cmd);

int		ft_exec(char *argv, char **envp);

void		ft_error(char *message);

void		ft_free_arr(char **arr);

#endif
