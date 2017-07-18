/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:59:59 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/12/11 11:01:53 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>

void	clean_str(t_pattern *pattern)
{
	while (pattern)
	{
		free(pattern->str);
		pattern = pattern->next;
	}
}

void	clean_position(t_tool *tool, t_pattern *pattern, char *str, int i)
{
	char	*c;

	c = pattern->coord;
	str[i] = '.';
	str[i + c[0] + c[1] * tool->back_n] = '.';
	str[i + c[2] + c[3] * tool->back_n] = '.';
	str[i + c[4] + c[5] * tool->back_n] = '.';
}
