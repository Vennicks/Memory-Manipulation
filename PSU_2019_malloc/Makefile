INC_DIR			= ./include

CC				= gcc
CFLAGS			+= -I $(INC_DIR)
CFLAGS			+= -Wall -Wextra -Werror
CFLAGS			+= -fPIC

RM				= rm -f

NAME			= libmy_malloc.so

SRCS			= malloc.c \
				  alloc_func.c


OBJS			= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -fPIC -shared -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re