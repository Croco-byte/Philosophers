/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:58:27 by user42            #+#    #+#             */
/*   Updated: 2021/04/01 11:40:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include "philosophers.h"

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	last_meal;
	unsigned int	life;
	unsigned int	full;
	pthread_t		thread;
	sem_t			*sem_forks;
	sem_t			*sem_display;
}					t_philo;

/* MAIN */
void			kill_philosophers(t_data *data, t_philo *philo);

/* INIT */
void			init_philosophers(int n_philo, t_philo *philo);

/* TIME */
unsigned int	get_time(unsigned int start_usec, unsigned int start_sec);
unsigned int	get_start_time(int which);

/* LIFE */
void			*live_philosopher(void *stock);

/* ACTIONS */
void			take_forks(t_stock *s, t_philo *philo);
void			philo_eat(t_stock *s, t_philo *philo);
void			philo_sleep(t_stock *s);
void			philo_think(t_stock *s);

/* DISPLAY */
void			display_status(t_stock *stock, char *str);
void			display_all_ate(t_data *data);

/* MONITOR */
void			monitor(t_data *data, t_philo *philo);

#endif
