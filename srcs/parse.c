/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:44:08 by grebin            #+#    #+#             */
/*   Updated: 2022/12/16 15:09:45 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


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
}