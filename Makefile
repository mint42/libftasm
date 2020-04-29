# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 11:54:37 by rreedy            #+#    #+#              #
#    Updated: 2020/04/27 06:03:43 by mint             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config.mk

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

$(TEST_NAME): $(NAME) test_main.c
	$(CC) $(CFLAGS) test_main.c -o $(TEST_NAME) $(LDFLAGS)

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
	@- $(RM) -r test_main.o $(TEST_NAME)

re: fclean all
