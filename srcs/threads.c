/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:38:10 by grebin            #+#    #+#             */
/*   Updated: 2023/01/10 15:17:39 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = this()->start;
	if (philo->index % 2 == 0)
		usleep(10000);
	while (!dead(philo))
	{
		eat(philo);
		if (this()->av[4] != -1 && philo->num_meals == this()->av[4])
			break ;
		if (gosleep(philo))
			break ;
		printf("[%lums] %i is thinking.\n", time_diff(this()->start, \
		current_time()), philo->index);
	}
	return (NULL);
}

void	init_threads(void)
{
	int				i;

	this()->start = current_time();
	i = -1;
	while (++i < this()->av[0])
		if (pthread_create(&this()->philos[i].philo, NULL, &routine, \
		&this()->philos[i]) != 0)
			printerror("Error creating a thread", TRUE);
	i = -1;
	while (++i < this()->av[0])
		pthread_join(this()->philos[i].philo, NULL);
	i = -1;
	while (++i < this()->av[0])
		pthread_mutex_destroy(&this()->forks[i]);
}
