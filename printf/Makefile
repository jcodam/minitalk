CC = gcc

NAME = libftprintf.a

header = ft_printf.h

OBJ = ft_printf.o ft_printf_extra.o

ADDS = libft/*.o

BONES_OBJ = 

CFLAGS = -Wall -Werror -Wextra

ifdef plusbones
OBJ_FILES = $(OBJ) $(BONES_OBJ)
else
OBJ_FILES = $(OBJ)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES) $(ADDS)
	ar -crs $@ $^

$(ADDS):
	@make -C libft bonus

%.o: %.c $(header)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) $(BONES_OBJ)
	@make -C libft clean

fclean:
	rm -f $(NAME) $(OBJ) $(BONES_OBJ)
	@make -C libft fclean

re:
	$(MAKE) fclean
	$(MAKE) all

bonus:
	$(MAKE) plusbones=1 all

.PHONY: all clean fclean re bonus