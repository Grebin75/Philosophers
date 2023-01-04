/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:09:06 by grebin            #+#    #+#             */
/*   Updated: 2023/01/04 09:42:42 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*create_philo(int index, t_death *death)
{
	t_philo	*philo;
	
	philo = malloc(sizeof(t_philo));
	if (!philo)
		printerror("Error allocating PHILO STRUCT.", TRUE);
	philo->index = index + 1;
	philo->is_death = FALSE;
	philo->num_meals = 0;
	philo->last_meal = 0;
	philo->death = death;
	return (philo);
}

void	init_philo()
{
	int	i;
	static	t_death	death;
	
	i = -1;
	pthread_mutex_init(&death.reaper, NULL);
	this()->philos = malloc(sizeof(t_philo *) * this()->av[0]);
	if (!this()->philos)
		printerror("Error allocating PHILO ARRAY.", TRUE);
	while (++i < this()->av[0])
		this()->philos[i] = create_philo(i, &death);
}
