/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:55:08 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 11:26:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	int	resultat;
	int	negative;

	negative = 0;
	resultat = 0;
	while (*nptr && (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
			|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r'))
		++nptr;
	if (*nptr && (*nptr == '-' || *nptr == '+'))
	{
		if (*nptr == '-')
			negative++;
		nptr++;
	}
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		resultat = resultat * 10 + (*nptr - 48);
		++nptr;
	}
	if (negative % 2)
		resultat = resultat * -1;
	return (resultat);
}
