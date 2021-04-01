/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:31:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/01 12:23:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	display_all_ate(t_data *data)
{
	char	*time;

	time = ft_utoa(get_time(data->t_start_usec, data->t_start_sec));
	write(1, time, ft_strlen(time));
	write(1, "		all meals ate\n", 16);
	free(time);
}

void	display_status(t_stock *s, char *event)
{
	char	*time;
	char	*id;
	char	*str;

	id = ft_utoa(s->philo->id);
	time = ft_utoa(get_time(s->data->t_start_usec, s->data->t_start_sec));
	str = 0;
	str = ft_strjoin(str, time, 2);
	str = ft_strjoin(str, "	", 1);
	str = ft_strjoin(str, id, 2);
	str = ft_strjoin(str, event, 1);
	str = ft_strjoin(str, "\n", 1);
	write(1, str, ft_strlen(str));
	free(str);
}
