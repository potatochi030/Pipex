/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:17:52 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/09/08 15:57:21 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*sub;
	size_t	i;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && i < len && ft_strchr(set, s1[i]))
		i++;
	while (s1[--len] && i < len && ft_strchr(set, s1[len]))
		;
	sub = malloc(len - i + 2);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s1[i], len - i + 2);
	return (sub);
}
/*
#include <stdio.h>
int main()
{
	printf("%s", ft_strtrim("a+--jbc++c", "+-"));
}*/
