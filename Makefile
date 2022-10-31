NAME1= server

NAME2= client

UNI= printf/libftprintf.a

CFLAK= -g -Werror -Wall -Wextra -o

all: $(NAME1) $(NAME2)

bit: $(UNI) test_bit_s.c
	gcc $(CFLAK) bit_t $^
	
bitr:
	rm -f bit_t

$(NAME1): $(UNI) $(NAME1).c
	gcc $(CFLAK) $@ $^

$(NAME2): $(UNI) $(NAME2).c
	gcc $(CFLAK) $@ $^

fclean:
	rm -f $(NAME1) $(NAME2)

phony: fclean all