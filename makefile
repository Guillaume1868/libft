FLAG = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c  ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c   ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c  ft_strnstr.c  ft_strrchr.c \
ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_striteri.c get_next_line.c\
get_next_line_utils.c

OBJ = $(SRC:.c=.o)

BONUS			=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c  ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
					ft_lstmap.c
BONUS_OBJS		= $(BONUS:.c=.o)

GREEN       =   \e[38;5;118m
YELLOW      =   \e[38;5;226m
RESET       =   \e[0m
_SUCCESS    =   [$(GREEN)SUCCESS$(RESET)]
_INFO       =   [$(YELLOW)INFO$(RESET)]

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@printf "$(_SUCCESS) libft ready.\n"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@
	@printf "$(_INFO) OBJ $@ compiled.\n"

clean:
	@rm -f $(OBJ) $(BONUS_OBJS)
	@printf "$(_INFO) libft OBJ removed.\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(_INFO) LIBFT removed.\n"

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJS)

.PHONY: all, clean, fclean, re, bonus
