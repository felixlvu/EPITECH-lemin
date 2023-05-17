##
## EPITECH PROJECT, 2022
## makefile
## File description:
## compiler librairie
##

RED = '\033[0;31m'
GREEN = '\033[0;32m'
WHITE = '\033[0;37m'
BLUE = '\033[0;34m'
YELLOW = '\033[0;33m'

SRC		=	    src/main.c \
				src/parser.c \
				src/print_parser.c \
				src/fill.c \
				src/room_tunnel.c \
				src/algo.c	\
				src/move_ants.c \

OBJ		= 		$(SRC:.c=.o)

NAMEBIN =		lem_in

CFLAGS  = 		-I ./include/ -W -Wall -Wextra -g3

NOPRINT = 	--no-print-directory

%.o: %.c
		@gcc -c $< -o $@ $(CFLAGS)

$(NAMEBIN):		$(OBJ)
		@echo -e $(BLUE)'         All:'$(WHITE)
		@make -C lib/ $(NOPRINT)
		@echo -e $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)
		@echo -e $(RED)' ['$(YELLOW)'BUILDING MINISHELL'$(RED)']'$(WHITE)
		@gcc $(OBJ) -o $(NAMEBIN) -L. libmy.a
		@echo -e $(RED)'       ['$(YELLOW)'FINISH'$(RED)']'$(WHITE)
		@echo -e $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)

all:			$(NAMEBIN)

clean:
		@echo -e $(BLUE)'        Clean:'$(WHITE)
		@echo -e $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)
		@rm -f $(OBJ)
		@echo -e $(RED)'      ['$(YELLOW)'REMOVE .o'$(RED)']'$(WHITE)
		@echo -e $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)

fclean:     clean
		@make fclean -C lib/ $(NOPRINT)
		@echo -e $(BLUE)'     Force Clean:'$(WHITE)
		@echo -e $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)
		@echo -e $(RED)'  ['$(YELLOW)'REMOVE MINISHELL'$(RED)']'$(WHITE)
		@rm -f $(NAME)
		@rm -f $(NAMEBIN)
		@echo -e $(RED)'       ['$(YELLOW)'FINISH'$(RED)']'$(WHITE)
		@echo -e $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)

re:			fclean all

.PHONY : all clean fclean re
