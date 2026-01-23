/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:45:34 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/09/08 17:50:13 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		size;
	char	*num;

	num = ft_itoa(n);
	if (num)
	{
		size = ft_strlen(num);
		write(fd, num, size);
		free(num);
	}
}
/*
int main()
{
	ft_putnbr_fd(-2147, 1);
}*/
