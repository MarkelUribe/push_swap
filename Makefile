# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 11:18:25 by muribe-l          #+#    #+#              #
#    Updated: 2024/03/19 16:05:17 by muribe-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SOURCES = a_operations.c b_operations.c ab_operations.c \
push_swap.c free.c list.c dumb_sort.c arguments.c turk.c \
sort_utils.c turk_utils.c turk_utils_2.c

OBJECTS = $(patsubst %.c,$(ODIR)/%.o,$(SOURCES))
ODIR = ./obj

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFTNAME = libft.a
LIBFTDIR = ./libft

$(ODIR)/%.o: %.c
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFTDIR)/$(LIBFTNAME) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)
	make fclean -C $(LIBFTDIR)

fclean: clean
	$(RM) $(NAME)
	make clean -C $(LIBFTDIR)

re: fclean all

.PHONY:	all clean fclean re
