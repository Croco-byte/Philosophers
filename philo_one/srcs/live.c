/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:00:56 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 16:01:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
			pthread_mutex_lock(philo->display);
			display_status(s, "	has died");
			pthread_mutex_unlock(philo->display);
		}
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
		{
			data->all_meals++;
			break ;
		}
		philo_sleep(s);
		philo_think(s);
	}
	pthread_detach(check_thread);
}

void	*live_philosopher(void *stock)
{
	t_stock		*s;
	t_data		*data;
	t_philo		*philo;

	s = (t_stock *)stock;
	data = s->data;
	philo = s->philo;
	philo->life = TRUE;
	action_manager(s, data, philo);
	pthread_mutex_unlock(&philo->l_fork->lock);
	pthread_mutex_unlock(&philo->r_fork->lock);
	philo->life = FALSE;
	return (NULL);
}
