/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:03:09 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/09/08 18:40:42 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*sr;
	char		*ds;
	size_t		i;

	sr = (const char *) src;
	ds = (char *) dest;
	i = 0;
	if (sr < ds)
		while (n-- > 0)
			ds[n] = sr[n];
	else if (sr > ds)
	{
		while (n > i)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	return (ds);
}
/*
#include <stdio.h>
int main()
{
	char arr1[] = "world";
	char arr[] = "hello";
	ft_memmove(arr1, arr, 2);
	printf("%s",arr1);
}
*/
