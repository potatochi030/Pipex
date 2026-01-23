/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:11:13 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/08/21 18:43:01 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	ch;
	size_t	i;

	i = 0;
	ch = (char) c;
	str = (char *) s;
	while (i < n)
	{
		if (str[i] == ch)
			return (&str[i]);
		else
			i++;
	}
	return (NULL);
}
/*#include <stdio.h>
int main()
{
	printf("%s",((char *)ft_memchr("hello",'l',5)));
}*/
