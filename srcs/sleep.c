/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:15:36 by grebin            #+#    #+#             */
/*   Updated: 2022/12/22 20:38:30 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	gosleep(t_philo *philo)
{
	t_uli	sleeping;
	t_uli	start_sleep;

	start_sleep = current_time();
	sleeping = 0;
	while (!dead(philo) && sleeping <= (t_uli)this()->av[3])
	{
		sleeping = time_diff(start_sleep, current_time());
		usleep(100);
	}
	return (dead(philo));
}