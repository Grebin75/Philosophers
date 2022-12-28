#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
 #include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

#define FALSE 0
#define TRUE 1

typedef struct s_prog	t_prog;
typedef struct s_philo	t_philo;
typedef struct s_time	t_time;
typedef struct s_forks	t_forks;

typedef unsigned long int t_uli;


struct s_prog
{
	t_uli	start;
	pthread_mutex_t **forks;
	int		av[5];
	t_philo	**philos;
} ;

struct s_time
{
	t_uli last_meal;
	t_uli last_action;
} ;

struct s_philo
{
	int			is_death;
	t_uli		last_meal;
	int			index;
	int			num_meals;
	pthread_t 	philo;
	t_time		time;
};

t_prog *this();
void    printerror(char *str, int error);
int	ft_atoi(const char *nptr);
void	parse(int ac, char **av);
void	init_philo();
void	init_forks();
void	init_threads();
int		dead(t_philo *philo);
int		gosleep(t_philo *philo);

t_uli current_time();
t_uli time_diff(t_uli start, t_uli end);

#endif