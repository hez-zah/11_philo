# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 17:36:09 by hbadr             #+#    #+#              #
#    Updated: 2022/05/21 15:21:12 by hbadr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE = main.c utils.c philo_util.c init_philo.c routine.c

NAME = philo
OBJ_FILE = $(SRC_FILE:.c=.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = philo.h
cc = gcc
RM = rm -rf

PURPLE = \033[0;35m
BLUE = \033[0;34m
RED = \033[0;31m

all : $(NAME)

%.o:%.c $(HEADER)
	$(cc) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILE)
	@$(cc) $(CFLAGS) $(OBJ_FILE) -o $(NAME)
	@echo "$(BLUE)tout est MAKE"

clean :
	$(RM) $(OBJ_FILE)
	@echo "$(RED) tout est clear"

fclean : clean
	@$(RM) $(NAME)

re : fclean all