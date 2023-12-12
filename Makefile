# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 21:26:03 by fgras-ca          #+#    #+#              #
#    Updated: 2023/08/08 15:05:36 by fgras-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFTPS = libftps.a

SRCPS =		cost.c \
		do_move.c \
		initialization.c \
		input_check.c \
		input_check_utils.c \
		position.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		sort.c \
		sort_tiny.c \
		stack.c \
		swap.c \
		utils.c \
		ft_split.c \

SRCMAIN =	main.c \

OBJPS = $(SRCPS:.c=.o)

OBJMAIN = $(SRCMAIN:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

all:	$(LIBFTPS) $(OBJMAIN)
	$(CC) $(CFLAGS) $(OBJMAIN) $(LIBFTPS) -o $(NAME)

$(LIBFTPS):	$(OBJPS)
	ar rcs $(LIBFTPS) $(OBJPS)

clean:
	$(RM) $(OBJPS) $(OBJMAIN)

fclean:
	$(RM) $(NAME) $(LIBFTPS) $(OBJMAIN)

re:	fclean all
