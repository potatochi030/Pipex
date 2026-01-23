/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:45:42 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/09/08 18:06:47 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;

	if (nmemb == 0 || size == 0)
		p = malloc(1);
	else
		p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
/*#include <stdio.h>
int main()
{
	unsigned int *pt;

	pt = ft_calloc(4,4);
	pt[0] = 1;
	pt[1] = 2;
	pt[3] = 0;
	int i = 0;
	while (i < 4)
	{
		printf("%d", pt[i]);
		i++;
	}
	free(pt);
}*/
