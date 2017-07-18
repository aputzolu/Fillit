/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:13:33 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/12/12 16:28:12 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static void		bufclr(char *buf)
{
	int		i;

	i = 0;
	while (i < BUF_SIZE)
	{
		buf[i] = 0;
		i++;
	}
}

t_pattern		*reader(int fd, t_tool *tool)
{
	char		buf[BUF_SIZE];
	t_pattern	*begin_list;
	t_pattern	*pattern;

	begin_list = NULL;
	bufclr(buf);
	while ((read(fd, buf, BUF_SIZE)) > 0)
	{
		if ((pattern = add_link(begin_list)) == NULL)
			return (NULL);
		if (pattern->str == NULL || pattern->coord == NULL)
			return (NULL);
		ft_memcpy(pattern->str, buf, 21);
		pattern->letter = tool->index++;
		if (begin_list == NULL)
			begin_list = pattern;
		bufclr(buf);
	}
	return (begin_list);
}
