# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 11:54:37 by rreedy            #+#    #+#              #
#    Updated: 2020/05/03 06:00:19 by mint             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config.mk
include test_framework/config.mk

SRCS := $(wildcard $(SRC_DIR)/*.s)
OBJS := $(patsubst %.s,%.o,$(SRCS))

.PHONY: all start stop clean fclean re name

all: $(NAME)

$(NAME): start $(OBJS) stop
	@ printf "$(COMPILE_COLOR)Creating  $(NAME_COLOR)$(NAME) "
	@ ar rc $(NAME) $(OBJS)
	@ printf "$(DOTS_COLOR)."
	@ ranlib $(NAME)
	@ printf "."
	@ printf " $(FINISH_COLOR) done$(CLEAR_COLOR)\n"

start:
	@ printf "$(COMPILE_COLOR)Compiling $(NAME_COLOR)$(MOD_NAME) $(DOTS_COLOR)"

stop:
	@ printf "$(FINISH_COLOR) done$(CLEAR_COLOR)\n"

$(TEST_NAME): $(NAME) $(TEST_FRAMEWORK_SRCS)
	$(CC) $(CFLAGS) $(TEST_FRAMEWORK_INCLUDES) $(TEST_FRAMEWORK_SRCS) -o $(TEST_NAME) $(LDFLAGS)
	touch test_sys_read.txt test_tst_read.txt test_sys_write.txt test_tst_write.txt

%.o: %.s
	@- nasm -f elf64 $<
	@- printf "."

clean:
	@ if $(foreach obj, $(OBJS),[ -f $(obj) ] ||) false; then \
		printf "$(DELETE_COLOR)Cleaning $(NAME_COLOR)$(NAME)$(CLEAR_COLOR)\n"; \
	  fi; 
	@- $(RM) $(OBJS)

fclean: clean
	@- if [ -f $(NAME) ]; then \
			$(RM) $(NAME); \
			printf "$(DELETE_COLOR)Removing $(NAME_COLOR)$(NAME)\n"; \
	   fi;
	@- $(RM) $(NAME)
	@- $(RM) $(TEST_NAME)
	@- $(RM) test_sys_read.txt test_tst_read.txt test_sys_write.txt test_tst_write.txt

re: fclean all
