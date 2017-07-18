/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:28:08 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/30 16:44:44 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*new_str;

	i = 0;
	if ((new_str = (char*)malloc(size + 1)) == NULL)
		return (NULL);
	while (i < size)
	{
		new_str[i] = '\0';
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
