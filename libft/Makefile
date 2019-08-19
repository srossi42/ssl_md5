# COMPILATION
CC = ar
CFLAGS = -Werror -Wextra -Wall -g

# DEFAULT RULE
DEFRULE = all

# BINARY
NAME = libft.a

# PATHS
ROOT = $(shell dirname `pwd`)
VPATH = ./srcs/ \
		./srcs/printf_srcs


OBJ_PATH = ./objs/
INC_PATH = ./includes/


# SOURCES
SRC_NAME =	ft_swap.c \
			ft_atoi.c \
			ft_appendchar.c \
		 	ft_bzero.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strlen.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstaddtail.c \
			ft_lstaddafter.c \
			ft_lstlen.c \
			ft_lstelempos.c \
			ft_lstmodify_cont.c \
			ft_printlist.c \
			ft_itoa_base_ll.c \
			ft_itoa_base_ull.c \
			ft_strrev.c \
			ft_max_int.c \
			ft_min_int.c \
			ft_val_abs.c \
			ft_sqrt.c \
			ft_printf.c \
			ft_init.c \
			ft_arg_set.c \
			ft_arg_clean.c \
			ft_arg_reset.c \
			ft_fdetect.c \
			ft_cast.c \
			ft_conv_nb.c \
			ft_conv_str.c \
			ft_conv_char.c \
			ft_conv_wchar.c \
			ft_conv_wchar_string.c \
			ft_conv_percent.c \
			ft_conv_p.c \
			ft_conv_x.c \
			ft_no_conv.c \
			ft_unicodes.c \
			ft_set_arg_nb.c \
			ft_def_x.c \
			ft_write_buff.c \
			ft_fill_nchar.c \
			get_next_line.c

# OBJECTS
OBJ_NAME = $(SRC_NAME:.c=.o)
DEPS = $(shell find . -regex ".*\.[ch]")


# PREFIXES
SRC = $(addprefix $(V_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

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

# MAIN RULES
default:
	@$(MAKE) $(DEFRULE)

.PHONY: all
all: $(OBJ_PATH) $(NAME)

building:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"

$(NAME): Makefile $(OBJ) $(DEPS)
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)....................... $(LOG_ORANGE)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) -rc $@ $(OBJ)
	@echo -e "--$(LOG_CLEAR)$(LOG_CYAN)$(NAME)$(LOG_NOCOLOR) compiled................. $(LOG_GREEN)✓$(LOG_NOCOLOR)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)%.o: $(V_PATH)%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@gcc $(CFLAGS) $(INC) -c $< -o $@

.PHONY: clean
clean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@$(RM) -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deleted.............. $(LOG_RED)×$(LOG_NOCOLOR)"

.PHONY: fclean
fclean: clean
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean $(NAME)$(LOG_NOCOLOR)"
	@$(RM) -f $(NAME)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deleted............... $(LOG_RED)×$(LOG_NOCOLOR)"

.PHONY:re
re:
	@$(MAKE) fclean
	@$(MAKE) all

norme:
	norminette $(SRC)
	norminette ./includes/*.h
