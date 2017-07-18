/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:51:09 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/30 10:44:50 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		size;
	size_t		i;
	char		*new_str;

	i = 0;
	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	if ((new_str = ft_strnew(size + 1)) == NULL)
		return (NULL);
	while (*s)
	{
		new_str[i] = f(*s);
		s++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
