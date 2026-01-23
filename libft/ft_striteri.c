/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:24:40 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/09/08 17:32:06 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void func(unsigned int i, char *str)
{
	*str = (*str) + i;
}
#include <stdio.h>
int main()
{
	char s[]="0123";
	ft_striteri(s, func);
	printf("%s|", s);
}*/
