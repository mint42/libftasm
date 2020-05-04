# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 11:54:37 by rreedy            #+#    #+#              #
#    Updated: 2020/05/04 03:14:55 by mint             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config.mk
include test_framework/config.mk

OBJS := $(patsubst %.s,%.o,$(SRCS))

.PHONY: all clean fclean re macos linux

all: $(NAME)

$(NAME): $(OBJS)
	@ ar rc $(NAME) $(OBJS)
	@ ranlib $(NAME)

%.o: %.s
	nasm -f $(BINARY_FMT) $<

$(TEST_NAME): $(NAME) $(TEST_FRAMEWORK_SRCS)
	$(CC) $(CFLAGS) $(TEST_FRAMEWORK_INCLUDES) $(TEST_FRAMEWORK_SRCS) -o $(TEST_NAME) $(LDFLAGS)
	touch test_sys_read.txt test_tst_read.txt test_sys_write.txt test_tst_write.txt

clean:
	@- $(RM) $(OBJS)

fclean: clean
	@- $(RM) $(NAME)
	@- $(RM) $(TEST_NAME)
	@- $(RM) test_sys_read.txt test_tst_read.txt test_sys_write.txt test_tst_write.txt

re: fclean all
