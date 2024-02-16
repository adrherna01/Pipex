/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:34:03 by adrherna          #+#    #+#             */
/*   Updated: 2023/12/18 16:02:01 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	child_p(char **argv, char **envp, int *fd)
{
	int	file_one;

	file_one = open(argv[1], O_RDONLY);
	if (file_one == -1)
		ft_error("Error opening file in child");
	dup2(file_one, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	if (ft_exec(argv[2], envp) == -1)
    {
        close(file_one);
        ft_error("Error executing in child");
    }
    close(file_one);
}

void	parent_p(char **argv, char **envp, int *fd)
{
	int	file_two;

	file_two = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_two == -1)
		ft_error("Error opening file in parent");
	dup2(file_two, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	ft_exec(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	pid;
	int	fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			exit(-1);
		pid = fork();
		if (pid == -1)
			exit(-1);
		if (pid == 0)
			child_p(argv, envp, fd);
		waitpid(pid, NULL, 0);
		parent_p(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
		exit(0);
	}
}
