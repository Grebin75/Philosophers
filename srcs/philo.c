/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:09:06 by grebin            #+#    #+#             */
/*   Updated: 2023/01/10 15:16:53 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_philo(void)
{
	int				i;
	static t_death	death;

	i = -1;
	pthread_mutex_init(&death.reaper, NULL);
	this()->philos = malloc(sizeof(t_philo) * this()->av[0]);
	if (!this()->philos)
		printerror("Error allocating PHILO ARRAY.", TRUE);
	while (++i < this()->av[0])
	{
		this()->philos[i].index = i + 1;
		this()->philos[i].forks_hold = 0;
		this()->philos[i].num_meals = 0;
		this()->philos[i].last_meal = 0;
		this()->philos[i].death = &death;
	}
}
