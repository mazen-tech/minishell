# BASIC
CC = cc -g
CSANI = cc -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
RLFLAG = -lreadline
RM = rm -rf

# LIBFT
LIBFT = ./libft/libft.a

# COLORS
RESET	= "\033[0m"
GREEN	= "\033[32m"
RED     = "\033[31m"

# MINISHELL
NAME = minishell
SRC =	src/main.c \
    	src/commands/cd.c \
    	src/commands/echo.c \
    	src/commands/env.c \
    	src/commands/exit.c \
    	src/commands/export.c \
    	src/commands/pwd.c \
    	src/commands/unset.c \
		src/error/errors.c \
		src/executer/executer.c \
		src/executer/execve.c \
		src/executer/heredocs.c \
		src/executer/paths.c \
		src/executer/pipes.c \
		src/executer/redirects.c \
    	src/initialize/init.c \
		src/initialize/refresh.c \
    	src/initialize/start.c \
		src/parser/check.c \
		src/parser/expander.c \
    	src/parser/lexer.c \
		src/parser/parser.c \
		src/parser/signals.c \
    	src/sanitize/free_1.c \
		src/sanitize/free_2.c \
    	src/tokens/count_tokens.c \
    	src/tokens/get_tokens_1.c \
		src/tokens/get_tokens_2.c \
		src/tokens/tokens_utils_1.c \
		src/tokens/tokens_utils_2.c \
		src/tokens/tokens_utils_3.c \
		src/tokens/tokens_utils_4.c \
		src/tokens/tokens.c \
		src/utilities/debugg.c \
    	src/utilities/prompt.c \
    	src/utilities/utils_1.c \
		src/utilities/utils_2.c \

OBJSDIR = objects
OBJ = $(addprefix $(OBJSDIR)/, $(SRC:.c=.o))

# MAKE RULES
all: $(NAME)


# TARGETS
$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(RLFLAG) -o $(NAME)
	@echo $(GREEN)"Success: Compilation completed!"$(RESET)

sani: re $(OBJ)
	$(MAKE) -C ./libft
	$(CSANI) $(CFLAGS) $(OBJ) $(LIBFT) $(RLFLAG) -o $(NAME)
	@echo $(GREEN)"Success: Compiled with fsanitizer!"$(RESET)

$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE)	clean -C ./libft

fclean: clean
	$(RM) $(NAME) $(SANI) $(OBJSDIR)
	$(MAKE) fclean -C ./libft
	@echo $(RED)"Cleaned Successfully!"$(RESET)

re: fclean all

.SILENT:

.PHONY: all clean fclean re