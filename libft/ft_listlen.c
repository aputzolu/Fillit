/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:20:13 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/30 18:00:03 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_listlen(t_list *begin_list)
{
	size_t		i;
	t_list		*list;

	i = 1;
	list = begin_list;
	if (!begin_list)
		return (0);
	while ((list = list->next))
		i++;
	return (i);
}
