/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:31:08 by grebin            #+#    #+#             */
/*   Updated: 2023/01/10 15:16:00 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_prog	*this(void)
{
	static t_prog	prog;

	return (&prog);
}

void	printerror(char *str, int error)
{
	if (str)
		printf("%s\n", str);
	free(this()->philos);
	if (this()->fork_status)
		free(this()->fork_status);
	exit(error);
}

int	main(int ac, char **av)
{
	parse(ac, av);
	init_threads();
	printerror(NULL, FALSE);
}
