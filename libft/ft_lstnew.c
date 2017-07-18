/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:15:54 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/30 17:02:23 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list)
	{
		if (content == NULL)
		{
			list->content = NULL;
			list->content_size = 0;
			return (list);
		}
		else
		{
			list->content = malloc(sizeof(content_size));
			if (list->content == NULL)
				return (NULL);
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
