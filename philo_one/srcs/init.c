/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:26:45 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 11:43:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	init_forks(int n_philo, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < n_philo)
	{
		philo[i].l_fork = malloc(1 * sizeof(t_fork));
		if (!philo[i].l_fork)
			return ;
		philo[i].l_fork->id = i;
		pthread_mutex_init(&philo[i].l_fork->lock, NULL);
		i++;
	}
	i = 0;
	while (i < n_philo)
	{
		if (i == n_philo - 1)
			philo[i].r_fork = philo[0].l_fork;
		else
			philo[i].r_fork = philo[i + 1].l_fork;
		i++;
	}
}

void	init_display(int n_philo, t_philo *philo)
{
	int					i;
	pthread_mutex_t		*new_display;

	i = 0;
	new_display = malloc(1 * sizeof(pthread_mutex_t));
	if (!new_display)
		return ;
	pthread_mutex_init(new_display, NULL);
	while (i < n_philo)
	{
		philo[i].display = new_display;
		i++;
	}
}

void	init_philosophers(int n_philo, t_philo *philo)
{
	int	i;

	i = 0;
	init_forks(n_philo, philo);
	init_display(n_philo, philo);
	while (i < n_philo)
	{
		philo[i].id = i + 1;
		philo[i].last_meal = 0;
		philo[i].life = FALSE;
		i++;
	}
}
