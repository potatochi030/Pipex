/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:16:27 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/08/21 14:13:29 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if (c < 'A' || c > 'z')
		return (0);
	if (c > 'Z' && c < 'a')
		return (0);
	return (1);
}
/*
#include <stdio.h>
int main()
{
	printf("%d", ft_isalpha('c'));
	printf("%d", ft_isalpha('4'));
	printf("%d", ft_isalpha('-'));
}
*/
