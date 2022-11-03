NAME1= server

NAME2= client

UNI= printf/libftprintf.a

HEADER= mini_talk.h

CFLAK= -g -Werror -Wall -Wextra -o

all: $(NAME1) $(NAME2)

$(NAME1): $(UNI) $(NAME1).o
	gcc $(CFLAK) $@ $^

$(NAME2): $(UNI) $(NAME2).o
	gcc $(CFLAK) $@ $^

%.o: %.c $(HEADER)
	gcc -c $(CFLAK) $@ $<

$(UNI):
	$(MAKE) -C printf

clean:
	rm -f $(NAME1).o $(NAME2).o
	$(MAKE) -C printf clean

fclean:
	rm -f $(NAME1) $(NAME2) $(NAME1).o $(NAME2).o
	$(MAKE) -C printf fclean

f: fclean

re:
	$(MAKE) fclean
	$(MAKE) all

phony: fclean all clean re f