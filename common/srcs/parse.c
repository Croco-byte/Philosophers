/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:00:42 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 11:35:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	valid_args(int argc, char **argv)
{
	int		i;
	long	temp;

	i = 1;
	while (i < argc)
	{
		if (!check_num(argv[i]))
			return (0);
		temp = ft_atol(argv[i]);
		if (temp > 2147483647 || temp < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	display_error(char *str)
{
	write(1, "[X] Error: ", 11);
	if (str)
		write(1, str, ft_strlen(str));
	else
	{
		write(1, "number_of_time_each_philosophers_must_eat", 41);
		write(1, " can't be less than 1\n", 22);
	}
	return (0);
}

int	check_arguments(int ac, t_data *data)
{
	if (data->n_philo <= 1)
		return (display_error("number_of_philosopher can't be less than 2\n"));
	if (data->t_die < 1)
		return (display_error("time_to_die can't be less than 1\n"));
	if (data->t_eat < 1)
		return (display_error("time_to_eat can't be less than 1\n"));
	if (data->t_sleep < 1)
		return (display_error("time_to_sleep can't be less than 1\n"));
	if (ac == 6 && data->n_eat < 1)
		return (display_error(0));
	return (1);
}

int	init_data(int ac, char **av, t_data *data)
{
	if (ac < 5 || ac > 6)
		return (display_error("wrong number of arguments\n"));
	if (!valid_args(ac, av))
		return (display_error("arguments are not valid\n"));
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->n_eat = ft_atoi(av[5]);
	else
		data->n_eat = -1;
	data->one_died = 0;
	data->t_start_usec = 0;
	data->t_start_sec = 0;
	data->all_meals = 0;
	if (!check_arguments(ac, data))
		return (0);
	return (1);
}
