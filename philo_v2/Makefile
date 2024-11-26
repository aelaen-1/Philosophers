# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelaen <aelaen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 12:57:07 by aboukezi          #+#    #+#              #
#    Updated: 2024/11/15 15:44:36 by aelaen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
FLAGS = -Wall -Werror -Wextra -pthread

SRC = main.c \
      input_check.c \
	  set_the_table.c \
	  time.c \
	  thread_routines.c \
	  philo_life.c \
	  check_if_end.c \
      utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

debug: FLAGS += -g
debug: all

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
