/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:58:27 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 17:15:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include "philosophers.h"

typedef struct s_philo
{
	pid_t			pid;
	sem_t			*sem_forks;
	sem_t			*sem_display;
	unsigned int	id;
	unsigned int	last_meal;
	unsigned int	life;
}					t_philo;

/* INIT */
void			init_philosophers(int n_philo, t_philo *philo);

/* TIME */
unsigned int	get_time(unsigned int start_usec, unsigned int start_sec);
unsigned int	get_start_time(int which);

/* LIVE */
void			live_philosopher(t_stock *s);

/* ACTIONS */
void			take_forks(t_stock *s, t_philo *philo);
void			philo_eat(t_stock *s, t_philo *philo);
void			philo_sleep(t_stock *s, t_philo *philo);
void			philo_think(t_stock *s, t_philo *philo);

/* DISPLAY */
void			display_status(t_stock *stock, char *str);
void			display_all_ate(t_data *data);

/* MONITOR */
void			monitor(t_data *data, t_philo *philo);
void			kill_philosophers(t_data *data, t_philo *philo);

#endif
