/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:59:49 by user42            #+#    #+#             */
/*   Updated: 2021/04/01 12:16:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	monitor_death(t_data *data, t_philo *philo)
{
	while (!data->one_died)
		usleep(10);
	if (data->one_died)
		kill_philosophers(data, philo);
}

void	monitor_meals(t_data *data, t_philo *philo)
{
	while (!data->one_died && data->all_meals < data->n_philo)
		usleep(10);
	if (!data->one_died && data->all_meals >= data->n_philo)
	{
		sem_wait(philo->sem_display);
		display_all_ate(data);
		sem_post(philo->sem_display);
	}
	if (data->one_died || data->all_meals >= data->n_philo)
		kill_philosophers(data, philo);
}

void	monitor(t_data *data, t_philo *philo)
{
	if (data->n_eat <= 0)
		monitor_death(data, philo);
	else
		monitor_meals(data, philo);
}
