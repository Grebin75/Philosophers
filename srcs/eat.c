/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:31:40 by grebin            #+#    #+#             */
/*   Updated: 2023/01/07 11:31:41 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_fork(t_philo *philo, pthread_mutex_t *mutex, int slot)
{
	pthread_mutex_lock(mutex);
	//printf("FORK: %i\n", this()->fork_status[slot]);
	if (this()->fork_status[slot] == TRUE)
	{
		this()->fork_status[slot] = FALSE;
		philo->forks_hold += 1;
		printf("[%lums] %i has taken a fork.\n", time_diff(this()->start, current_time()), philo->index);
	}
	pthread_mutex_unlock(mutex);	
}

int	start_eating(t_philo *philo)
{
	t_uli	eating;
	t_uli	start_eat;
	
	start_eat = current_time();
	eating = 0;
	printf("[%lums] %i is eating.\n", time_diff(this()->start, current_time()), philo->index);
	while (!dead(philo) && eating <= (t_uli)this()->av[2])
	{
		eating = time_diff(start_eat, current_time());
		usleep(100);
	}
	if (dead(philo))
		return (FALSE);
	philo->last_meal = current_time();
	philo->forks_hold = 0;
	philo->num_meals++;
	return (TRUE);
}

int		eat(t_philo	*philo)
{
	int	right;
	int	left;

	left = philo->index - 1;
	right = (philo->index != this()->av[0]) * (philo->index);
	while (!dead(philo))
	{
		check_fork(philo, &this()->forks[left], left);
		check_fork(philo, &this()->forks[right], right);
		//printf("%i FORKS: %i\n", philo->index, philo->forks_hold);
		if (philo->forks_hold == 2 && !dead(philo))
		{
			if (start_eating(philo))
			{
				pthread_mutex_lock(&this()->forks[left]);
				this()->fork_status[left] = TRUE;
				pthread_mutex_unlock(&this()->forks[left]);
				pthread_mutex_lock(&this()->forks[right]);
				this()->fork_status[right] = TRUE;
				pthread_mutex_unlock(&this()->forks[right]);
				break;
			}
		}
	}
	//printf("Philo %i: \nRIGHT: %i\nLEFT: %i\n\n", philo->index, right, left);
	return (1);
}