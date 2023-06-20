# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 12:04:14 by sdiaz-ru          #+#    #+#              #
#    Updated: 2023/06/20 10:44:19 by sdiaz-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo
CC				=	gcc -pthread -g3
CFLAGS			=	-Wall -Werror -Wextra -fsanitize=thread -g
RM				=	rm -f
DIR_SRC			=	./src
DIR_FT_PRINTF	=	./ft_printf
FT_PRINTF		=	libftprintf.a
INCLUDE			=	$(DIR_SRC)/philo.h
SRC				=	$(DIR_SRC)/philo.c $(DIR_SRC)/parser_arg.c $(DIR_SRC)/atoi.c $(DIR_SRC)/thread_philo.c
# COLORS
GREEN = `tput setaf 2`
RED = `tput setaf 1`
RESET = `tput sgr0`

OBJS = $(SRC:.c=.o)

$(TRUE).SILENT:

all: $(NAME)

$(DIR_FT_PRINTF)/$(FT_PRINTF):
	@make -C $(DIR_FT_PRINTF)

$(NAME): $(OBJS) $(DIR_FT_PRINTF)/$(FT_PRINTF)
			$(CC) $(CFLAGS) $(OBJS) $(DIR_FT_PRINTF)/$(FT_PRINTF) -o $@
			@echo "$(GREEN)CREATE philo$(RESET)\n"


re:		fclean all

clean:
		@$(RM) $(OBJS)
		@make -s clean -C $(DIR_FT_PRINTF)
		@echo "$(RED)REMOVE OBJECTS philo$(RESET)\n"

fclean:	clean
		@$(RM) $(NAME)
		@make -s fclean -C $(DIR_FT_PRINTF)
		@echo "$(RED)DELETE philo$(RESET)\n"
		
.PHONY: all re clean fclean