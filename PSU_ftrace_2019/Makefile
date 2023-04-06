NAME	= ftrace

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./print_fct.c \
	  ./print_fct2.c \
	  ./sys.c \
	  ./syscall.c \
	  ./trace.c \
	  ./types.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -Werror -O3

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
