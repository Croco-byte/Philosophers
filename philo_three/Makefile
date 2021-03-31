# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 15:05:16 by user42            #+#    #+#              #
#    Updated: 2021/03/30 16:34:03 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three

CC = clang

CFLAGS = -Wall -Wextra -Werror -I includes/ -I ../common/includes
#-fsanitize=address -g3 -fno-omit-frame-pointer
PTHREAD = -lpthread

COMMON = ft_strlen ft_strdup ft_utoa ft_itoa ft_atoi ft_isspace ft_atol ft_strjoin parse time
MAIN = philo_three init display philo_actions monitor


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
