/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:59:44 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 11:16:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"


void	clean(t_data *data, t_philo *philo, t_stock *stock)
{
	int	i;

	i = 0;

	sem_unlink("display");
	sem_unlink("forks");
	free(philo);
	free(data);
	free(stock);
}

void	*check(void *stock)
{
	t_stock		*s;
	t_data		*data;
	t_philo		*philo;
	unsigned int	current_time;

	s = (t_stock *)stock;
	data = s->data;
	philo = s->philo;
	usleep(data->t_die * 1000);
	current_time = get_time(data->t_start_usec, data->t_start_sec);
	if (philo->life == TRUE && current_time - philo->last_meal >= data->t_die)
	{
		data->one_died = 1;
		sem_wait(philo->sem_display);
		display_status(s, "	has died");
	}
	return (NULL);
}

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
			break;
		}
		philo_sleep(s, philo);
		philo_think(s, philo);
	}
	philo->life = FALSE;
	pthread_join(check_thread, 0);
	return (NULL);
}

void	kill_philosophers(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	usleep(10000);
	while (i < data->n_philo)
	{
		pthread_detach(philo[i].thread);
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
		usleep(10);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	t_stock	*stock;

	if (!(data = malloc(1 * sizeof(t_data))))
		return (1);
	if (!init_data(ac, av, data))
	{
		free(data);
		return (1);
	}
	if (!(philo = malloc(data->n_philo * sizeof(t_philo))))
		return (1);
	if (!(stock = malloc((data->n_philo + 1) * sizeof(t_stock))))
		return (1);
	init_philosophers(data->n_philo, philo);
	launch_philosophers(data, philo, stock);
	monitor(data, philo);
	clean(data, philo, stock);
	return (0);
}
