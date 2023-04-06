NAME	= my_nm

CC	= gcc

RM	= rm -f

SRCS	= ./nmd/*.c

CFLAGS = -I ./nm-objdump/includes/
CFLAGS += -Wall -Wextra

all: $(NM)

nm: $(OBJS)
	$(CC) $(SRCS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) ./nmd/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
