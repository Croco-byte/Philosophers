/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:17:42 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 11:26:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	*ft_strdup(char *src)
{
	int		size;
	char	*result;

	size = ft_strlen(src);
	result = malloc((size + 1) *sizeof(char));
	if (!result)
		return (0);
	result[size] = '\0';
	while (--size >= 0)
		result[size] = src[size];
	return (result);
}
