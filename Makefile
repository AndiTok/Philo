# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atok <atok@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 15:09:28 by atok              #+#    #+#              #
#    Updated: 2023/07/04 03:25:02 by atok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC 		= gcc
RM 		= rm -rf
CFLAGS 	= -Wall -Wextra -Werror -I $(INCLUDES) #-fsanitize=thread
OFLAGS 	= -pthread

INCLUDES= ~/philo.h

SRCS = checkparam.c \
		ft_atoi.c \
		ft_exit.c \
		ft_msleep.c \
		initialize_philo.c \
		initialize_var.c \
		launch.c \
		philo.c \
		routine.c \
		status.c \
		timestamp.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(OFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all