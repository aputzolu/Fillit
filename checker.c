/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:47:07 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/12/16 15:26:50 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static char		recurse_hashtag(t_pattern *pattern, int i, int limit)
{
	int		n;

	n = 0;
	if (pattern->str[i] == '#' && i >= 0 && i <= 19 && limit < 5)
	{
		n++;
		pattern->str[i] = pattern->letter;
		n += recurse_hashtag(pattern, i - 5, limit + 1);
		n += recurse_hashtag(pattern, i - 1, limit + 1);
		n += recurse_hashtag(pattern, i + 5, limit + 1);
		n += recurse_hashtag(pattern, i + 1, limit + 1);
	}
	return (n);
}

static void		len_checker(t_tool *tool, t_pattern *pattern)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (pattern->next && pattern->str[20] != '\n')
		tool->error = -7;
	if (!(pattern->next) && pattern->str[20] != 0)
		tool->error = -8;
	if (pattern->str[4] != '\n' || pattern->str[9] != '\n' ||
			pattern->str[14] != '\n' || pattern->str[19] != '\n')
		tool->error = -3;
	while (pattern->str[i])
	{
		if (pattern->str[i] == '#')
			n++;
		if (pattern->str[i] != '#' && pattern->str[i] != '.' &&
				pattern->str[i] != '\n')
			tool->error = -2;
		i++;
	}
	if (n != 4)
		tool->error = -9;
}

static void		checker(t_tool *tool, t_pattern *pattern)
{
	int		i;
	int		m;

	i = 0;
	m = 0;
	len_checker(tool, pattern);
	if (tool->error != 0)
		return ;
	while (pattern->str[i])
	{
		m = recurse_hashtag(pattern, i, 0);
		if (!(tool->n))
			tool->n = m;
		if (m != 0 && m != tool->n)
			tool->error = -4;
		i++;
	}
	if (tool->n != 4)
		tool->error = -5;
	tool->n = 0;
}

static int		lstlen(t_pattern *pattern)
{
	int		i;

	i = 0;
	while (pattern)
	{
		i++;
		pattern = pattern->next;
	}
	return (i);
}

void			checker_map(t_tool *tool, t_pattern *pattern)
{
	int		lst_len;

	lst_len = lstlen(pattern);
	if (lst_len < 1 || lst_len > 26)
		tool->error = -1;
	while (pattern)
	{
		checker(tool, pattern);
		pattern = pattern->next;
	}
}
