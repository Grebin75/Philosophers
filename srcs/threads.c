/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:38:10 by grebin            #+#    #+#             */
/*   Updated: 2022/12/23 21:44:44 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"\

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	philo->last_meal = this()->start;
	while (!dead(philo))
	{
		//eat
		//printf("AV[4] = %i\n", this()->av[4]);
		if (this()->av[4] != -1 && philo->num_meals == this()->av[4])
			break;
		printf("[%lums] %i is sleeping.\n", time_diff(this()->start, current_time()), philo->index);
		if (gosleep(philo))
			break ;
		usleep(100);
		philo->num_meals++;
		printf("[%lums] %i is eating.\n", time_diff(this()->start, current_time()), philo->index);
		philo->last_meal = current_time();
	}
	if (dead(philo))
		printf("[%lums] %i died.\n",time_diff(this()->start, current_time()), philo->index);
	printerror(NULL, 0);
	return (NULL);
}


void	init_threads()
{
	int				i;

	this()->start = current_time();
	i = -1;
	while (++i < this()->av[0])
		if (pthread_create(&this()->philos[i]->philo, NULL, &routine, this()->philos[i]) != 0)
			printerror("Error creating a thread", TRUE);
	i = -1;
	while (++i < this()->av[0])
		pthread_join(this()->philos[i]->philo, NULL);
	i = -1;
/* 	while (++i < this()->av[0])
		pthread_mutex_destroy(this()->forks[i]); */
}