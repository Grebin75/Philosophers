/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:31:08 by grebin            #+#    #+#             */
/*   Updated: 2022/12/19 14:44:27 by grebin           ###   ########.fr       */
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
	int	i;

	i = -1;
    if (str)
        printf("%s\n", str);
	while (++i < this()->av[0])
			free(this()->philos[i]);
		free(this()->philos);
	exit(error);
}

int main(int ac, char **av)
{	
	parse(ac, av);
	init_threads();
	printerror(NULL, FALSE);
}