/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:31:08 by grebin            #+#    #+#             */
/*   Updated: 2022/12/16 16:59:53 by grebin           ###   ########.fr       */
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
	while (i < this()->av[0])
	{
		while (this()->philos[++i])
			free(this()->philos[i]);
		free(this()->philos);
	}
	exit(error);
}

int main(int ac, char **av)
{
	int i;
	
	parse(ac, av);
	i = -1;
	printerror(NULL, FALSE);
}