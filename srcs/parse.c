/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:44:08 by grebin            #+#    #+#             */
/*   Updated: 2022/12/23 20:23:44 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void	init_forks()
{
	int	i;
	pthread_mutex_t *f;

	i = -1;
	this()->forks = malloc(sizeof(pthread_mutex_t *) * this()->av[0]);
	if (!this()->forks)
		printerror("Error allocating MUTEX ARRAY", 1);
	while (+i < this()->av[0])
	{
		f = malloc(sizeof(pthread_mutex_t));
		printerror("Error allocating MUTEX", 1);
		this()->forks[0] = f;
		pthread_mutex_init(f, NULL);
	}
}

void	parse(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac != 6 && ac != 5)
		printerror("Invalid number of arguments", TRUE);
	this()->av[4] = -1;
	while (av[++i])
        this()->av[i - 1] = ft_atoi(av[i]);
	if (this()->av[0] == 0 || this()->av[1] == 0 || this()->av[2] == 0 || \
		this()->av[3] == 0 || this()->av[4] == 0)
	printerror("Invalid arguments", 1);
	init_philo();
	//init_forks();
}