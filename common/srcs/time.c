/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:04:24 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 11:36:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned int	get_time(unsigned int start_usec, unsigned int start_sec)
{
	struct timeval	current_time;
	int				sec;

	gettimeofday(&current_time, NULL);
	sec = current_time.tv_sec - start_sec;
	return (((unsigned int)(sec * 1000000 + current_time.tv_usec)
			- start_usec) / 1000);
}

unsigned int	get_start_time(int which)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (which == 0)
		return (current_time.tv_usec);
	else
		return (current_time.tv_sec);
}
