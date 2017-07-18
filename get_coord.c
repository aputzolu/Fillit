/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:58:54 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/12/10 18:42:08 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		get_coord(t_pattern *pattern)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	while (pattern->str[i] != pattern->letter)
		i++;
	j = i;
	while (pattern->str[j] && n < 6)
	{
		j++;
		if (pattern->str[j] && pattern->str[j] == pattern->letter)
		{
			pattern->coord[n] = ((j % 5) - (i % 5));
			pattern->coord[n + 1] = ((j / 5) - (i / 5));
			n += 2;
		}
	}
}

void			coord_map(t_pattern *pattern)
{
	while (pattern)
	{
		get_coord(pattern);
		pattern = pattern->next;
	}
}
