/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:11:50 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/09/08 17:00:39 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	intlen(long ln)
{
	int	len;

	len = 0;
	if (ln < 0)
	{
		ln *= -1;
		len++;
	}
	ln /= 10;
	len++;
	while (ln > 0)
	{
		ln /= 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char	*num;
	long	ln;
	int		i;

	ln = (long) n;
	i = intlen(ln) - 1;
	num = malloc(intlen(n));
	if (!num)
		return (NULL);
	if (ln < 0)
	{
		ln = -ln;
		num[0] = '-';
	}
	num[i] = 0;
	num[--i] = (ln % 10) + 48;
	ln = ln / 10;
	while (ln > 0)
	{
		num[--i] = (ln % 10) + 48;
		ln = ln / 10;
	}
	return (num);
}
/*
#include <stdio.h>
int main()
{
	char *res = ft_itoa(-2147483648LL);
	int	i = 0;

	while (res[i])
		i++;
	write(1, res, i);
	printf("%s",res);
}*/
