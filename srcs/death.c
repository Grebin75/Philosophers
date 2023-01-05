/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:03:30 by grebin            #+#    #+#             */
/*   Updated: 2023/01/05 10:46:10 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_death(t_philo *p)
{
	int	dead;

	pthread_mutex_lock(&p->death->reaper);
	dead = p->death->dead;
	pthread_mutex_unlock(&p->death->reaper);
	return (dead);
}

int	dead(t_philo *philo)
{
	if(check_death(philo))
		return (TRUE);
	if (time_diff(philo->last_meal, current_time()) >= (t_uli)this()->av[1])
	{
		pthread_mutex_lock(&philo->death->reaper);
		philo->death->dead++;
		if (philo->death->dead == 1)
			printf("[%lums] %i died.\n",time_diff(this()->start, current_time()), philo->index);
		pthread_mutex_unlock(&philo->death->reaper);
	}
	return (time_diff(philo->last_meal, current_time()) >= (t_uli)this()->av[1]);
}