/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:42:57 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/30 19:33:27 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*map;
	t_list		*add;
	t_list		*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	map = f(lst);
	tmp = map;
	lst = lst->next;
	while (lst)
	{
		add = f(lst);
		if (add == NULL)
			return (NULL);
		tmp->next = add;
		tmp = add;
		lst = lst->next;
	}
	return (map);
}
