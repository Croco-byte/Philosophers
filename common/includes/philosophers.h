/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:49:03 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 11:23:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "semaphore.h"

# define FALSE	0
# define TRUE	1

typedef struct s_data
{
	int				n_philo;
	unsigned int	t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				one_died;
	unsigned int	t_start_sec;
	unsigned int	t_start_usec;
	int				all_meals;
}					t_data;

typedef struct s_stock
{
	struct s_philo	*philo;
	struct s_data	*data;
}					t_stock;

/* FT FUNCTIONS */

int				ft_strlen(char *str);
char			*ft_strdup(char *src);
int				ft_atoi(const char *nptr);
long			ft_atol(const char *nptr);
char			*ft_itoa(int n);
char			*ft_utoa(unsigned int n);
char			*ft_strjoin(char *s1, char *s2, int which);
int				ft_isspace(int c);

/* COMMON FUNCTIONS */
int				init_data(int ac, char **av, t_data *data);
unsigned int	get_time(unsigned int start_usec, unsigned int start_sec);
unsigned int	get_start_time(int which);

#endif
