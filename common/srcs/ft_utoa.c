/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:16:06 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 11:29:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	size(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	reverse(char *result)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(result) - 1;
	while (i < j)
	{
		temp = result[i];
		result[i] = result[j];
		result[j] = temp;
		i++;
		j--;
	}
}

char	*ft_utoa(unsigned int n)
{
	int		i;
	char	*result;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	result = malloc((size(n) + 1) *sizeof(char));
	if (!result)
		return (0);
	while (n)
	{
		result[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	result[i] = '\0';
	reverse(result);
	return (result);
}
