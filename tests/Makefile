UTILS 			:= soft_assert.c
PARENT_DIR		:= $(shell dirname $(shell pwd))
LIBFT_PATH		:= $(PARENT_DIR)
TESTS_PATH		:= tests
TESTS			:= ctype tolowerupper strlen memset bzero \
			memcpy memmove strlcpy strlcat strchr strrchr \
			memchr memcmp strnstr atoi calloc strdup substr strjoin \
			strtrim split itoa strmapi striteri put_fd \
			lstnew lstadd_front lstsize lstlast lstadd_back \
			lstdelone lstclear lstiter lstmap
TESTS_NOVAL		:= strncmp

CFLAGS			:= -g -Wall -Wextra -Werror -Werror=vla -I$(LIBFT_PATH)
CC				:= cc
VALGRIND		:= valgrind -q --leak-check=full

all: $(TESTS) $(TESTS_NOVAL)

$(TESTS): |start
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)/test_$@.c -L$(LIBFT_PATH) -lft -lbsd && $(VALGRIND) ./a.out && rm -f a.out

$(TESTS_NOVAL): |start
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)/test_$@.c -L$(LIBFT_PATH) -lft -lbsd && ./a.out && rm -f a.out

start:
	make -C $(LIBFT_PATH)

.PHONY: start all
