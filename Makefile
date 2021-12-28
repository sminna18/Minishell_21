NAME	=	minishell

SRCS	=	minishell.c ft_split_shell.c shell_utils.c shell_utils_2.c shell_utils_3.c shell_utils_4.c preparser.c fd_redirect.c fd_redirect_2.c shell_parser.c \
			echo_pwd.c	env_cd.c	exit.c		export.c	export_help.c	export_help2.c	export_help3.c nopipe.c	nopipe_utils.c pipe.c start.c unset.c unset_help.c utils.c

INCLUDE	=	minishell.h

INCLUDEL=	libft/libft.h

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

READLINE=	-lreadline -L ~/.brew/opt/readline/lib

LIBFT	=	-Llibft -lft

CFLAGS 	=	-Wall -Wextra -Werror

# COLORS
WHITE	=	\033[0m
BLACK	=	\033[0;30m
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[0;36m

all : $(NAME)

%.o: %.c		$(SRCS)
				@$(CC) $(CFLAGS) -I$(INCLUDE) -I$(INCLUDEL) -c $< -o $@

$(NAME) : $(OBJS) $(INCLUDE)
	@say make lib functions
	@echo "$(GREEN)▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ $(WHITE)"
	@sleep 0.1
	@make bonus -C libft
	@make -C libft
	@make bonus -C libft
	@say done
	@say complete programm
	@echo "$(BLUE)▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ $(WHITE)"
	@$(CC) $(READLINE) $(LIBFT) $(CFLAGS) $(OBJS)  -o $(NAME)
	@say done
clean :
	@say delete objects files
	@rm -rf $(OBJS)
	@make clean -C libft
	@echo "$(RED)▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ \c"
	@sleep 0.1
	@echo "▶ $(WHITE)"
	@sleep 0.1
	@say done
	@sleep 0.1

fclean	: clean
	@rm -rf $(NAME)
	@make fclean -C libft

re		: fclean all

norm	:
		@say check norminette
		@sleep 0.1
		@say oh
		@sleep 0.1
		@say nice
		@norminette

.PHONY: clean fclean re all