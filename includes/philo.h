/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:13:57 by hcoutinh          #+#    #+#             */
/*   Updated: 2023/01/10 15:14:45 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

# define FALSE 0
# define TRUE 1

typedef struct s_prog		t_prog;
typedef struct s_philo		t_philo;
typedef struct s_time		t_time;
typedef struct s_forks		t_forks;
typedef struct s_death		t_death;

typedef unsigned long int	t_uli;

struct s_death
{
	int					dead;
	pthread_mutex_t		reaper;
};

struct s_prog
{
	int				av[5];
	int				*fork_status;
	pthread_mutex_t	*forks;
	t_uli			start;
	t_philo			*philos;
} ;

struct s_time
{
	t_uli	last_meal;
	t_uli	last_action;
} ;

struct s_philo
{
	t_uli		last_meal;
	int			forks_hold;
	int			index;
	int			num_meals;
	pthread_t	philo;
	t_time		time;
	t_death		*death;
};

t_prog	*this(void);
void	printerror(char *str, int error);
int		ft_atoi(const char *nptr);
void	parse(int ac, char **av);
void	init_philo(void);
void	init_threads(void);
int		dead(t_philo *philo);
int		gosleep(t_philo *philo);
int		eat(t_philo	*philo);

t_uli	current_time(void);
t_uli	time_diff(t_uli start, t_uli end);

#endif
