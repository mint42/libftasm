# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 09:39:36 by rreedy            #+#    #+#              #
#    Updated: 2020/04/29 06:48:35 by mint             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libasm.a
LIB	:= asm

SRC_DIR := ./srcs
INCLUDE_DIR := ./includes

CC := gcc
//CFLAGS += -g
//CFLAGS += -Wall
//CFLAGS += -Wextra
//CFLAGS += -Werror
CFLAGS += -I$(INCLUDE_DIR)

# testing

TEST_NAME := test
LDFLAGS := -l$(LIB) -L./

NAME_COLOR := \e[1;33m
COMPILE_COLOR := \e[1;32m
DOTS_COLOR := \e[0;36m
FINISH_COLOR := \e[0;32m
CLEAR_COLOR := \e[m
DELETE_COLOR := \e[0;31m
