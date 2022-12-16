/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:38:10 by grebin            #+#    #+#             */
/*   Updated: 2022/12/16 16:53:25 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"\

void	routine(t_philo philo)
{

		
}


void	create_threads()
{
	int				i;

	this()->start = current_time();
	i = -1;
	while (++i < this()->av[0])
		if (pthread_create(this()->philos[i]->philo, NULL, &routine, NULL) != 0);
			printerror("Error creating a thread", TRUE);
	i = -1;
	while (++i < this()->av[0])
		pthread_join(this()->philos[i]->philo, NULL);
}