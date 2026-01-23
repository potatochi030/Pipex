/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:51:29 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/09/08 17:22:02 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	flag;
	int	ans;

	i = 0;
	flag = 1;
	ans = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		i++;
	}
	return (ans * flag);
}
/*#include <stdio.h>
int main()
{
	printf("%d  ",ft_atoi("	  -2147483648hvkj"));
	printf("%d  ",ft_atoi("  +0hvkj"));
	printf("%d  ",ft_atoi("  -09653 ")); 
	printf("%d  ",ft_atoi("  -39653hvkj"));
	return (0);
}*/
