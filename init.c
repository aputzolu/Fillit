/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:41:04 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/12/11 11:09:02 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static void		init_pattern(t_pattern *pattern)
{
	if ((pattern->str = ft_strnew(20)) == NULL)
		return ;
	if ((pattern->coord = (char*)malloc(sizeof(int) * 6)) == NULL)
		return ;
	pattern->letter = 0;
	pattern->next = NULL;
}

static void		init_str(char *str, int height, int back_n)
{
	int		i;

	i = 0;
	while (i < (height * back_n))
	{
		if (i && ((i % back_n) == 0))
			str[i - 1] = '\n';
		str[i] = '.';
		i++;
	}
	str[i - 1] = '\n';
	str[i] = '\0';
}

char			*create_str(int height, int back_n)
{
	char	*str;
	int		i;

	i = 0;
	if ((str = (char*)malloc((sizeof(char)) * (height * back_n))) == NULL)
		return (NULL);
	while (i < (height * back_n))
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	init_str(str, height, back_n);
	return (str);
}

t_pattern		*add_link(t_pattern *pattern)
{
	t_pattern	*tmp;

	if ((tmp = (t_pattern*)malloc(sizeof(t_pattern))) == NULL)
		return (NULL);
	init_pattern(tmp);
	if (!pattern)
		return (tmp);
	while (pattern->next)
		pattern = pattern->next;
	pattern->next = tmp;
	return (tmp);
}

t_tool			*init_tool(void)
{
	t_tool		*tool;

	if ((tool = (t_tool*)malloc(sizeof(t_tool))) == NULL)
		return (NULL);
	tool->error = 0;
	tool->index = 'A';
	tool->n = 0;
	tool->height = 2;
	tool->back_n = 3;
	return (tool);
}
