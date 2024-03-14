CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME = libftprintf.a
HEADER = ft_printf.h

SRCS = ft_printf.c ft_itoa.c ft_unitoa.c\
	   ft_strings.c ft_ints.c ft_format.c\
	   ft_putptr.c ft_hexa.c

OBJS = $(SRCS:.c=.o)

#regla implicita
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)


.PHONY:	all, clean, fclean, re
