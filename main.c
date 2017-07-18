/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:33:14 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/12/16 16:32:52 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>

void	ft_exit(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int		main(int ac, char **av)
{
	t_tool		*tool;
	t_pattern	*pattern;
	int			fd;

	if (ac != 2)
		ft_exit();
	if (!(tool = init_tool()))
		return (0);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_exit();
	pattern = reader(fd, tool);
	if (close(fd) < 0)
		ft_exit();
	checker_map(tool, pattern);
	if (tool->error != 0)
		ft_exit();
	coord_map(pattern);
	clean_str(pattern);
	solve(tool, pattern);
	return (0);
}
