/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:15:36 by grebin            #+#    #+#             */
/*   Updated: 2023/01/04 17:30:23 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	gosleep(t_philo *philo)
{
	t_uli	sleeping;
	t_uli	start_sleep;

	start_sleep = current_time();
	sleeping = 0;
	if (!dead(philo))
		printf("[%lums] %i is sleeping.\n", time_diff(this()->start, current_time()), philo->index);
	while (!dead(philo) && sleeping <= (t_uli)this()->av[3])
	{
		sleeping = time_diff(start_sleep, current_time());
		usleep(100);
	}
	return (dead(philo));
}