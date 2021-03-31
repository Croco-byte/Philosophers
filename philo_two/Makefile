# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 15:05:16 by user42            #+#    #+#              #
#    Updated: 2021/03/31 16:12:28 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_two

CC = clang

CFLAGS = -Wall -Wextra -I includes/ -I ../common/includes
PTHREAD = -lpthread

COMMON = ft_strlen ft_strdup ft_utoa ft_itoa ft_atoi ft_isspace ft_atol ft_strjoin parse time
MAIN = philo_two init display monitor philo_actions live


SRCS =  $(addsuffix .c, $(addprefix ../common/srcs/, $(COMMON))) \
		$(addsuffix .c, $(addprefix srcs/, $(MAIN)))


OBJS = ${SRCS:.c=.o}

all:			$(NAME)

$(NAME):		$(OBJS)
						$(CC) $(CFLAGS) $(PTHREAD) -o $(NAME) $(OBJS)

%.o:%.c
						${CC} ${CFLAGS} -c $< -o $@

clean:
						rm -f $(OBJS)

fclean:
						rm -f $(OBJS)
						rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
