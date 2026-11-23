NAME = libftprintf.a

SRCS =  ft_hexl.c \
		ft_hexu.c \
		ft_pptr.c \
		ft_pstring.c \
		ft_putnb.c \
		ft_putnbhexlc.c \
		ft_putnbhexuc.c \
		ft_putunsignednb.c \
		ft_sc.c \
		ft_printf.c

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

CC = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re