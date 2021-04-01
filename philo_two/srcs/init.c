/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:26:45 by user42            #+#    #+#             */
/*   Updated: 2021/04/01 13:26:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	init_philosophers(int n_philo, t_philo *philo)
{
	int		i;
	sem_t	*display;
	sem_t	*forks;

	i = 0;
	sem_unlink("display");
	sem_unlink("forks");
	display = sem_open("display", O_CREAT | O_EXCL, S_IRWXU, 1);
	forks = sem_open("forks", O_CREAT | O_EXCL, S_IRWXU, n_philo);
	while (i < n_philo)
	{
		philo[i].full = 0;
		philo[i].sem_display = display;
		philo[i].sem_forks = forks;
		philo[i].id = i + 1;
		philo[i].last_meal = 0;
		philo[i].life = FALSE;
		i++;
	}
}
