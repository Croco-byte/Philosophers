/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:18:23 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 16:22:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	take_forks(t_stock *s, t_philo *philo)
{
	if (s->data->one_died)
		return ;
	sem_wait(philo->sem_forks);
	sem_wait(philo->sem_forks);
	sem_wait(philo->sem_display);
	if (!s->data->one_died)
	{
		display_status(s, "	has taken a fork");
		display_status(s, "	has taken a fork");
	}
	sem_post(philo->sem_display);
}

void	philo_eat(t_stock *s, t_philo *philo)
{
	if (s->data->one_died)
		return ;
	sem_wait(philo->sem_display);
	if (!s->data->one_died)
		display_status(s, "	is eating");
	sem_post(philo->sem_display);
	philo->last_meal = get_time(s->data->t_start_usec, s->data->t_start_sec);
	usleep(s->data->t_eat * 1000);
	sem_post(philo->sem_forks);
	sem_post(philo->sem_forks);
}

void	philo_sleep(t_stock *s, t_philo *philo)
{
	if (s->data->one_died)
		return ;
	sem_wait(philo->sem_display);
	if (!s->data->one_died)
		display_status(s, "	is sleeping");
	sem_post(philo->sem_display);
	usleep(s->data->t_sleep * 1000);
}

void	philo_think(t_stock *s, t_philo *philo)
{
	if (s->data->one_died)
		return ;
	sem_wait(philo->sem_display);
	if (!s->data->one_died)
		display_status(s, "	is thinking");
	sem_post(philo->sem_display);
}
