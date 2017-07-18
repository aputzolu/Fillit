/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:13:39 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/30 10:44:57 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((new_str = ft_strdup(s)) == NULL)
		return (NULL);
	while (new_str[i])
	{
		new_str[i] = f(i, new_str[i]);
		i++;
	}
	return (new_str);
}
