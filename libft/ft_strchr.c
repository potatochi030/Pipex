/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:02:19 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/09/08 15:48:10 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	ch;
	int		i;

	ch = (char) c;
	str = (char *) s;
	i = 0;
	while (str[i] && str[i] != ch)
		i++;
	if (str[i] == ch)
		return (&str[i]);
	else
		return (NULL);
}
/*
#include <stdio.h>
int main()
{
	printf("%p", ft_strchr("hello", 'e'));
}*/
