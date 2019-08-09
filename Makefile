# COMPILATION
CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -Werror


DEFRULE = all
#BINARY
NAME = ft_ssl
DST = ./

# PATHS
LIBS = ./libft/libft.a
LIB_PATH = ./libft/
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/ $(LIB_PATH)includes/

# SOURCES
SRC_NAME =	main.c \
            md5/md5.c \
            md5/encode.c \
            md5/decode.c \
            md5/padding.c \
            sha256/sha256.c \
            sha256/encode.c \
            sha256/decode.c \
            sha256/padding.c \
            sha256/sigma.c \
            sha256/maj_ch.c \
            misc/free.c \
            misc/options.c \
            misc/print.c \
            misc/print_usage.c \
            misc/reverse_bits.c \
            misc/rotate.c \


# OBJECTS
OBJ_NAME = $(SRC_NAME:.c=.o)
DEPS = $(shell find . -regex ".*\.[ch]")

# PREFIXES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

# **************************************************************************** #
# SPECIAL CHARS

LOG_CLEAR= \033[2K
LOG_UP= \033[A
LOG_NOCOLOR= \033[0m
LOG_BOLD= \033[1m
LOG_UNDERLINE= \033[4m
LOG_BLINKING= \033[5m
LOG_BLACK= \033[1;30m
LOG_RED= \033[1;31m
LOG_GREEN= \033[1;32m
LOG_YELLOW= \033[1;33m
LOG_BLUE= \033[1;34m
LOG_MAGENTA= \033[1;35m
LOG_CYAN= \033[1;36m
LOG_WHITE= \033[1;37m
LOG_ORANGE= \033[1;38;5;208m

# **************************************************************************** #

# RULES
#

default:
	@$(MAKE) $(DEFRULE)

.PHONY: all
all : $(NAME)

$(NAME): $(OBJ_PATH) $(DEPS) $(OBJ)
	@$(MAKE) -C $(LIB_PATH)
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)....................... $(LOG_ORANGE)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(OBJ) $(INC) $(LIBS) -o $(DST)$@
	@echo -e "--$(LOG_CLEAR)$(LOG_CYAN)$(NAME)$(LOG_NOCOLOR) compiled................. $(LOG_GREEN)✓$(LOG_NOCOLOR)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/md5
	@mkdir -p $(OBJ_PATH)/sha256
	@mkdir -p $(OBJ_PATH)/misc

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(INC) -c $^ -o $@

.PHONY: clean
clean:
	@$(MAKE) -C libft clean
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@$(RM) -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@$(RM) -rf $(OBJ_PATH)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deleted.............. $(LOG_RED)×$(LOG_NOCOLOR)"

.PHONY: fclean
fclean: clean
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean libft.a $(LOG_NOCOLOR)"
	@$(RM) -f $(NAME)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deleted............... $(LOG_RED)×$(LOG_NOCOLOR)"
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean $(NAME)$(LOG_NOCOLOR)"
	@$(RM) -f $(NAME)
	@$(RM) -f $(LIBS)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deleted............... $(LOG_RED)×$(LOG_NOCOLOR)"


.PHONY:re
re:
	@$(MAKE) fclean
	@$(MAKE) all

norme:
	norminette $(SRC)
	norminette ./includes/*.h
