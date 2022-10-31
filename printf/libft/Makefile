
CC = gcc

NAME = libft.a

header = libft.h

OBJ = ft_memset.o ft_memcpy.o ft_memmove.o ft_putchar_fd.o ft_putendl_fd.o ft_putstr_fd.o ft_putnbr_fd.o ft_tolower.o ft_toupper.o \
ft_strchr.o ft_strrchr.o ft_strlen.o ft_strnstr.o ft_memcmp.o ft_memchr.o ft_bzero.o ft_strncmp.o ft_strdup.o ft_strlcpy.o ft_strlcat.o ft_atoi.o \
ft_calloc.o ft_isalpha.o ft_isalnum.o ft_isdigit.o ft_isascii.o ft_isprint.o ft_strtrim.o ft_strmapi.o ft_substr.o ft_strjoin.o ft_itoa.o ft_split.o \
ft_striteri.o

BONES_OBJ = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o

CFLAGS = -Wall -Werror -Wextra -g

ifdef plusbones
OBJ_FILES = $(OBJ) $(BONES_OBJ)
else
OBJ_FILES = $(OBJ)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -crs $@ $^

%.o: %.c $(header)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) $(BONES_OBJ)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus:
	$(MAKE) plusbones=1 all

.PHONY: all clean fclean re