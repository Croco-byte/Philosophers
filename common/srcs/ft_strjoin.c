/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:50:16 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 11:28:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_which(char *s1, char *s2, int which)
{
	if (which == 1)
		free(s1);
	if (which == 2)
	{
		free(s1);
		free(s2);
	}
}

char	*ft_strjoin(char *s1, char *s2, int which)
{
	int		i;
	int		k;
	char	*result;

	i = 0;
	k = 0;
	if (!s1 && !s2)
		return (0);
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) *sizeof(char));
	if (!result)
		return (0);
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	while (k < ft_strlen(s2))
	{
		result[i + k] = s2[k];
		k++;
	}
	result[i + k] = '\0';
	free_which(s1, s2, which);
	return (result);
}
