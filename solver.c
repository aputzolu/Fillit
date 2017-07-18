/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:59:59 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/12/10 18:56:00 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static int		position(t_pattern *pattern, t_tool *tool, char *str, int i)
{
	int		n;
	char	*coord;

	n = 0;
	coord = pattern->coord;
	while (str[i + n] || n < i + coord[4] + coord[5] * tool->back_n)
		n++;
	if (n < i + coord[4] + coord[5] * tool->back_n)
		return (1);
	if (str[i] != '.' ||
			(str[i + coord[0] + coord[1] * tool->back_n] != '.') ||
				(str[i + coord[2] + coord[3] * tool->back_n] != '.') ||
					(str[i + coord[4] + coord[5] * tool->back_n] != '.'))
		return (1);
	else
		return (0);
}

static void		place(t_pattern *pattern, t_tool *tool, char *str, int i)
{
	char	*coord;

	coord = pattern->coord;
	str[i] = pattern->letter;
	str[i + coord[0] + coord[1] * tool->back_n] = pattern->letter;
	str[i + coord[2] + coord[3] * tool->back_n] = pattern->letter;
	str[i + coord[4] + coord[5] * tool->back_n] = pattern->letter;
}

static int		ft_solver(t_tool *tool,
			t_pattern *pattern, char *str, int index)
{
	int success;

	index = 0;
	success = 0;
	if (pattern)
	{
		while (str[index])
		{
			if (position(pattern, tool, str, index) == 0)
			{
				place(pattern, tool, str, index);
				success = ft_solver(tool, pattern->next, str, index);
				if (success == 1)
					return (1);
				clean_position(tool, pattern, str, index);
			}
			index++;
		}
		return (0);
	}
	return (1);
}

void			solve(t_tool *tool, t_pattern *pattern)
{
	int		success;
	char	*str;

	success = 0;
	str = NULL;
	while (success == 0)
	{
		if ((str = create_str(tool->height, tool->back_n)) == NULL)
			return ;
		success = ft_solver(tool, pattern, str, 0);
		if (success == 0)
		{
			free(str);
			tool->height++;
			tool->back_n++;
		}
		if (success == 1)
			ft_putstr(str);
	}
}
