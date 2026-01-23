/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:35:41 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/08/21 14:31:06 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (!(c >= '0' && c <= '9'))
	{
		if (c < 'A' || c > 'z')
			return (0);
		if (c > 'Z' && c < 'a')
			return (0);
	}
	return (1);
}
/*
#include <stdio.h>
int main()
{
	printf("%d",ft_isalnum('9'));
	printf("%d",ft_isalnum('F'));
	printf("%d",ft_isalnum('i'));
	printf("%d",ft_isalnum('`'));
}
*/
