# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almanuel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 12:42:56 by almanuel          #+#    #+#              #
#    Updated: 2024/09/27 12:49:29 by almanuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE = 	src/main.c 		\
		src/loop_create.c	\
		src/philo_init.c	\
		src/utils.c		\
		src/philo_rotine.c	\
		src/print_philo.c	\
		src/error_argv.c	\
		src/monitoring.c

OBJC = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJC)

fclean: clean
	rm -f $(NAME)

re: clean fclean all
