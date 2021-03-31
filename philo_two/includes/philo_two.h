/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:21:30 by user42            #+#    #+#             */
/*   Updated: 2021/03/29 16:14:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

#include "philosophers.h"


#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include "philosophers.h"

typedef struct		s_philo
{
	unsigned int	id;
	unsigned int	last_meal;
	unsigned int	life;
	pthread_t		thread;
	sem_t			*sem_forks;
	sem_t			*sem_display;
}					t_philo;

/* MAIN */
void	kill_philosophers(t_data *data, t_philo *philo);

/* INIT */
void	init_philosophers(int n_philo, t_philo *philo);

/* TIME */
unsigned int	get_time(unsigned int start_usec, unsigned int start_sec);
unsigned int	get_start_time(int which);

/* ACTIONS */
void	take_forks(t_stock *s, t_philo *philo);
void	philo_eat(t_stock *s, t_philo *philo);
void	philo_sleep(t_stock *s, t_philo *philo);
void	philo_think(t_stock *s, t_philo *philo);

/* DISPLAY */
void	display_status(t_stock *stock, char *str);
void	display_all_ate(t_data *data);

/* MONITOR */
void	monitor(t_data *data, t_philo *philo);

/* DEBUG */
void	test_display(t_data *data, t_philo *philo);

#endif



#endif
