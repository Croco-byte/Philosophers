/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:28:33 by user42            #+#    #+#             */
/*   Updated: 2021/04/01 13:41:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*check(void *stock)
{
	t_stock			*s;
	t_data			*data;
	t_philo			*philo;
	unsigned int	current_time;

	s = (t_stock *)stock;
	data = s->data;
	philo = s->philo;
	usleep(data->t_die * 1000);
	current_time = get_time(data->t_start_usec, data->t_start_sec);
	if (philo->life == TRUE && current_time - philo->last_meal >= data->t_die)
	{
		if (!data->one_died)
		{
			data->one_died = 1;
			sem_wait(philo->sem_display);
			display_status(s, "	has died");
			sem_post(philo->sem_display);
		}
		exit(2);
	}
	return (NULL);
}

void	action_manager(t_stock *s, t_data *data, t_philo *philo)
{
	int			i;
	pthread_t	check_thread;

	i = 0;
	pthread_create(&check_thread, NULL, &check, s);
	while (!data->one_died && (data->n_eat == -1 || i < data->n_eat))
	{
		pthread_detach(check_thread);
		pthread_create(&check_thread, NULL, &check, s);
		take_forks(s, philo);
		philo_eat(s, philo);
		i++;
		if (data->n_eat != -1 && i >= data->n_eat)
			break ;
		philo_sleep(s, philo);
		philo_think(s, philo);
	}
	philo->life = FALSE;
	pthread_join(check_thread, 0);
	if (data->n_eat != -1 && i >= data->n_eat)
		exit(3);
	exit(2);
}

void	live_philosopher(t_stock *s)
{
	t_data		*data;
	t_philo		*philo;

	data = s->data;
	philo = s->philo;
	philo->life = TRUE;
	action_manager(s, data, philo);
}
