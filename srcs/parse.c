/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:44:08 by grebin            #+#    #+#             */
/*   Updated: 2023/01/10 15:16:18 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	parse(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 6 && ac != 5)
		printerror("Invalid number of arguments", TRUE);
	this()->av[4] = -1;
	while (av[++i])
		this()->av[i - 1] = ft_atoi(av[i]);
	if (this()->av[0] == 0 || this()->av[1] == 0 || this()->av[2] == 0 || \
		this()->av[3] == 0 || this()->av[4] == 0)
		printerror("Invalid arguments", TRUE);
	init_philo();
	this()->fork_status = malloc(sizeof(int) * this()->av[0]);
	if (!this()->fork_status)
		printerror("Error allocating INT ARRA", TRUE);
	i = -1;
	while (++i < this()->av[0])
		this()->fork_status[i] = TRUE;
	this()->forks = malloc(sizeof(pthread_mutex_t) * this()->av[0]);
	if (!this()->forks)
		printerror("Error allocating fork array", 1);
	i = -1;
	while (++i < this()->av[0])
		pthread_mutex_init(&this()->forks[i], NULL);
}
