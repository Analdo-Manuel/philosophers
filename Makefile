# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 14:33:53 by marccarv          #+#    #+#              #
#    Updated: 2024/09/20 19:22:35 by almanuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc 
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g
SOURCE = main.c loop_create.c philo_init.c utils.c philo_rotine.c print_philo.c
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
