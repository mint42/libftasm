# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 09:39:36 by rreedy            #+#    #+#              #
#    Updated: 2020/05/04 04:47:05 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libasm.a
LIB	:= asm

MACOS_SRC_DIR := ./macos_srcs
LINUX_SRC_DIR := ./linux_srcs
INCLUDE_DIR := ./includes

ifeq ($(shell uname -s),Linux)
	BINARY_FMT := elf64
	SRCS := $(wildcard $(LINUX_SRC_DIR)/*.s)
endif

ifeq ($(shell uname -s),Darwin)
	BINARY_FMT := macho64
	SRCS := $(wildcard $(MACOS_SRC_DIR)/*.s)
endif

CC := gcc
CFLAGS += -g
//CFLAGS += -Wall
//CFLAGS += -Wextra
//CFLAGS += -Werror
CFLAGS += -I$(INCLUDE_DIR)

# testing
TEST_NAME := test
LDFLAGS := -lasm -L./
