/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:59:44 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 17:17:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	clean(t_data *data, t_philo *philo, t_stock *stock)
{
	sem_unlink("display");
	sem_unlink("forks");
	sem_close(philo->sem_forks);
	sem_close(philo->sem_display);
	free(philo);
	free(data);
	free(stock);
}

void	launch_philosophers(t_data *data, t_philo *philo, t_stock *stock)
{
	int	i;

	i = 0;
	data->t_start_usec = get_start_time(0);
	data->t_start_sec = get_start_time(1);
	while (i < data->n_philo)
	{
		stock->philo = &philo[i];
		stock->data = data;
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			live_philosopher(stock);
		usleep(35);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	t_stock	*stock;

	data = malloc(1 * sizeof(t_data));
	if (!data)
		exit(1);
	if (!init_data(ac, av, data))
	{
		free(data);
		exit(1);
	}
	philo = malloc(data->n_philo * sizeof(t_philo));
	if (!philo)
		exit(1);
	stock = malloc((data->n_philo + 1) *sizeof(t_stock));
	if (!stock)
		exit(1);
	init_philosophers(data->n_philo, philo);
	launch_philosophers(data, philo, stock);
	monitor(data, philo);
	clean(data, philo, stock);
	return (0);
}
