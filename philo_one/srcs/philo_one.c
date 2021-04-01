/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:59:44 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 17:37:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	clean(t_data *data, t_philo *philo, t_stock *stock)
{
	int	i;

	i = 0;
	free(philo->display);
	while (i < data->n_philo)
	{
		free(philo[i].l_fork);
		i++;
	}
	free(philo);
	free(data);
	free(stock);
}

void	kill_philosophers(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	usleep(1000000);
	while (i < data->n_philo)
	{
		pthread_join(philo[i].thread, 0);
		i++;
	}
}

void	launch_philosophers(t_data *data, t_philo *philo, t_stock *stock)
{
	int	i;

	i = 0;
	data->t_start_usec = get_start_time(0);
	data->t_start_sec = get_start_time(1);
	while (i < data->n_philo)
	{
		stock[i].philo = &philo[i];
		stock[i].data = data;
		if (pthread_create(&philo[i].thread, NULL, live_philosopher, &stock[i]))
			return ;
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

/*
void	*live_philosopher(void *stock)
{
	int			i;
	t_stock		*s;
	t_data		*data;
	t_philo		*philo;
	pthread_t	check_thread;

	i = 0;
	s = (t_stock *)stock;
	data = s->data;
	philo = s->philo;
	philo->life = TRUE;
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
	pthread_mutex_unlock(&philo->l_fork->lock);
	pthread_mutex_unlock(&philo->r_fork->lock);
	philo->life = FALSE;
	pthread_detach(check_thread);
	return (NULL);
}
*/
