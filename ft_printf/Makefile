# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 11:10:38 by sdiaz-ru          #+#    #+#              #
#    Updated: 2023/06/20 10:43:31 by sdiaz-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	libftprintf.a
COMPILE_NAME	=	main.out

CFLAGS			=	-Wall -Werror -Wextra
AR				=	ar -crs
RM				=	rm -fr

INCLUDE			=	ft_printf.h

SRC				=	ft_printf.c \
					ft_itoa.c	\
					ft_writes.c	\
					ft_putbase.c

OBJ				=	$(SRC:.c=.o)
# COLORS
GREEN = `tput setaf 2`
RED = `tput setaf 1`
RESET = `tput sgr0`

all: $(NAME)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)CREATE ft_printf$(RESET)\n"

c:
			gcc $(CFLAGS) main.c $(SRC) -o $(COMPILE_NAME)

re:		fclean all

clean: 
		@$(RM) $(OBJ)
		@echo "$(RED)REMOVE OBJECTS ft_printf$(RESET)\n"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)DELETE ft_printf$(RESET)\n"

.PHONY: 	all re clean fclean c d
