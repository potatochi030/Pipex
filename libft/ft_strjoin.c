/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:09:09 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/09/08 13:29:18 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sub;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len && s1[i])
	{
		sub[i] = s1[i];
		i++;
	}
	while (i < len && s2[j])
		sub[i++] = s2[j++];
	sub[len] = 0;
	return (sub);
}
/*
#include <stdio.h>
int main()
{
	char s[]= "hello", d[] = "world!";
	printf("%s",ft_strjoin(s,d));
}*/
