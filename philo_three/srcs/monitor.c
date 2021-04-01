/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:59:49 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 17:16:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	kill_philosophers(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}
}

int	check_child(t_data *data, t_philo *philo, int i, int *finished_eating)
{
	int	status;

	status = 0;
	waitpid(philo[i].pid, &status, WNOHANG);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 2)
			return (2);
		else if (WEXITSTATUS(status) == 3)
		{
			*finished_eating = *finished_eating + 1;
			if (*finished_eating >= data->n_philo)
				return (3);
		}
	}
	return (0);
}

void	monitor(t_data *data, t_philo *philo)
{
	int		i;
	int		checker;
	int		finished_eating;

	i = 0;
	checker = 0;
	finished_eating = 0;
	while (i < data->n_philo)
	{
		checker = check_child(data, philo, i, &finished_eating);
		if (checker == 2 || checker == 3)
			break ;
		i++;
		if (i == data->n_philo)
			i = 0;
	}
	kill_philosophers(data, philo);
	if (checker == 3)
		display_all_ate(data);
}
