/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:31:08 by grebin            #+#    #+#             */
/*   Updated: 2023/01/07 12:03:14 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


t_prog *this()
{
    static t_prog 	prog;
    
    return(&prog);
}

void    printerror(char *str, int error)
{
    if (str)
        printf("%s\n", str);
	//pthread_mutex_destroy(&this()->forks);
	if (this()->philos)
		pthread_mutex_destroy(&this()->philos[0].death->reaper);
	free(this()->philos);
	if (this()->fork_status)
		free(this()->fork_status);
	exit(error);
}

int main(int ac, char **av)
{	
	parse(ac, av);
	init_threads();
	printerror(NULL, FALSE);
}