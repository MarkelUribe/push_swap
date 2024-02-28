# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 11:18:25 by muribe-l          #+#    #+#              #
#    Updated: 2024/02/28 14:12:05 by muribe-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SOURCES = sa.c sb.c ss.c ra.c rb.c pa.c pb.c rr.c rra.c rrb.c rrr.c swap.c \
push_swap.c free.c list.c order.c arguments.c

OBJECTS = $(patsubst %.c,$(ODIR)/%.o,$(SOURCES))
ODIR = ./obj

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
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
