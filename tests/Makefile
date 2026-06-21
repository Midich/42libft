UTILS 			:= check.c
PARENT_DIR		:= $(shell dirname $(shell pwd))
LIBFT_PATH		:= $(PARENT_DIR)
TESTS_PATH		:= tests
TESTS			:= isalpha isdigit isalnum isascii isprint strlen memset bzero /
					

CFLAGS			:= -g -Wall -Wextra -Werror -Werror=vla -I$(LIBFT_PATH)

all: $(TESTS)

$(TESTS): |start
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)/test_$@.c -L$(LIBFT_PATH) -lft && valgrind -q --leak-check=full ./a.out && rm -f a.out

start:
	make -C $(LIBFT_PATH)

.PHONY: start all
