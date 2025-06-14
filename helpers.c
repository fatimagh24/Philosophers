/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:23:09 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/14 17:09:44 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *s)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{
		if ((s[i] >= '0' && s[i] <= '9'))
			res = res * 10 + (s[i] - '0');
		else if (!(s[i] >= '0' && s[i] <= '9') || res > INT_MAX)
			printf("Error\n");
		i++;
	}
	return (res * sign);
}
