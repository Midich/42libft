CFLAGS := -Wall -Wextra -Werror -Werror=vla
NAME := libft.a
AR := ar

src_files = ft_ctype.c ft_strings.c
h_files := libft.h
obj_dir := obj
obj_files := $(addprefix $(obj_dir)/, $(src_files:%.c=%.o))

test_dir = test
tests = $(addprefix $(test_dir)/bin/, test_ctype test_string)

all: $(NAME)

$(NAME): $(obj_files)
	$(AR) -r $@ $?

$(obj_files):$(obj_dir)/%.o:%.c | $(obj_dir)
	$(CC) -c $(CFLAGS) $^ -o $@
	

$(obj_dir):
	mkdir $(obj_dir)

clean:
	rm -fR $(obj_dir)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re

test: re $(tests)
	rm -fR $(test_dir)/bin

$(tests):$(test_dir)/bin/%:$(test_dir)/%.c | $(test_dir)/bin
	@echo "Testing $(@:$(test_dir)/bin/%=%)"
	@$(CC) $(CFLAGS) $< $(NAME) -o $@
	@./$@

$(test_dir)/bin:
	mkdir $(test_dir)/bin


.PHONY: all clean fclean re debug test
