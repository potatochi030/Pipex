/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:14:17 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/09/08 15:48:35 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		start = i;
		while (big[i] == little[j] && little[j] && i < len)
		{
			i++;
			j++;
			if (little[j] == 0)
				return ((char *)&big[start]);
		}
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
int main()
{
	printf("%s", ft_strnstr("hello world","wo",10));
}*/
