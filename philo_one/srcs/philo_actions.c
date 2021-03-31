/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:18:23 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 16:12:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	take_forks(t_stock *s, t_philo *philo)
{
	if (s->data->one_died)
		return ;
	pthread_mutex_lock(&philo->l_fork->lock);
	pthread_mutex_lock(&philo->r_fork->lock);
	pthread_mutex_lock(s->philo->display);
	if (!s->data->one_died)
	{
		display_status(s, "	has taken a fork");
		display_status(s, "	has taken a fork");
	}
	pthread_mutex_unlock(s->philo->display);
}

void	philo_eat(t_stock *s, t_philo *philo)
{
	if (s->data->one_died)
		return ;
	pthread_mutex_lock(s->philo->display);
	if (!s->data->one_died)
		display_status(s, "	is eating");
	pthread_mutex_unlock(s->philo->display);
	philo->last_meal = get_time(s->data->t_start_usec, s->data->t_start_sec);
	usleep(s->data->t_eat * 1000);
	pthread_mutex_unlock(&philo->l_fork->lock);
	pthread_mutex_unlock(&philo->r_fork->lock);
}

void	philo_sleep(t_stock *s)
{
	if (s->data->one_died)
		return ;
	pthread_mutex_lock(s->philo->display);
	if (!s->data->one_died)
		display_status(s, "	is sleeping");
	pthread_mutex_unlock(s->philo->display);
	usleep(s->data->t_sleep * 1000);
}

void	philo_think(t_stock *s)
{
	if (s->data->one_died)
		return ;
	pthread_mutex_lock(s->philo->display);
	if (!s->data->one_died)
		display_status(s, "	is thinking");
	pthread_mutex_unlock(s->philo->display);
}
