/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:46:19 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/08/21 15:38:10 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
	{
		len++;
	}
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

/*#include <stdio.h>
int main()
{
	char s[5];
	char v[]= "hello";
	printf("%zu   %s \n",ft_strlcpy(s,v,0),s);
	printf("%zu   %s \n",ft_strlcpy(s,v,1),s);
	printf("%zu   %s \n",ft_strlcpy(s,v,5),s);
	printf("%zu   %s \n",ft_strlcpy(s,v,7),s);
	return (0);
}*/
