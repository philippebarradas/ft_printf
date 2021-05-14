# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 12:18:37 by phbarrad          #+#    #+#              #
#    Updated: 2020/12/05 19:31:15 by phbarrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -rf

HEADER	=	-I includes

SRC	=	src/ft_printf.c \
		src/ft_modul.c \
		src/ft_intmod.c \
		src/ft_lib.c \
		src/ft_conv.c \
		src/ft_aff.c \
		src/ft_org.c \
		src/ft_orgstr.c \
		lib/ft_putchar_fd.c \
		lib/ft_putstr_fd.c \
		lib/ft_putnbr_fd.c \
		lib/ft_strlen.c \
		lib/ft_atoi.c \
		lib/ft_itoa.c \
		lib/ft_isdigit.c \
		lib/ft_strdup.c \
		lib/ft_utoa.c \
		lib/ft_abs.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
		$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
