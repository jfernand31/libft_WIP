/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:11:26 by jfernand          #+#    #+#             */
/*   Updated: 2025/10/27 11:23:49 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_safe_atoi(const char *str, int *out)
{
	int	i;
	int	is_neg;
	int	result;

	i = 0;
	is_neg = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			is_neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result * is_neg) > INT_MAX || (result * is_neg) < INT_MIN)
			return (1);
		result = result * 10 + str[i] - '0';
		i++;
	}
	*out = result * is_neg;
	return (0);
}
