/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:05:35 by grebin            #+#    #+#             */
/*   Updated: 2023/01/10 15:14:56 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_atoi(const char *nptr)
{
	int	n;
	int	s;
	int	i;

	n = 0;
	s = 1;
	i = -1;
	while ((nptr[++i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		s = (nptr[i] != '-') - (nptr[i] == '-');
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		n = (n * 10) + (s * (nptr[i++] - '0'));
	return (n);
}
