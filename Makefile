# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 09:26:29 by pnamnil           #+#    #+#              #
#    Updated: 2023/09/06 13:59:51 by pnamnil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prog
SRC_DIR = ../get_next_line

SRCS_M = $(addprefix $(SRC_DIR)/, get_next_line.c get_next_line_utils.c)
OBJS_M = $(SRCS_M:.c=.o)

SRCS_B = $(addprefix $(SRC_DIR)/, get_next_line_bonus.c get_next_line_utils_bonus.c)
OBJS_B = $(SRCS_B:.c=.o)

TEST_M = main.c
TEST_B = main_bonus.c

BUFFER_SIZE = 1

CC = gcc
CFLAGS = -Wall -Werror -Wextra
BUFFER = -D BUFFER_SIZE=$(BUFFER_SIZE)
INCLUDE = -I $(SRC_DIR)

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@ 

all: $(NAME)
	./$(NAME)

bonus: clean $(OBJS_B)
	$(CC) $(CFLAGS) $(BUFFER) $(INCLUDE) $(OBJS_B) $(TEST_B) -o $(NAME)
	./$(NAME)

$(NAME): clean $(OBJS_M)
	$(CC) $(CFLAGS) $(BUFFER) $(INCLUDE) $(OBJS_M) $(TEST_M) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJS_M) $(OBJS_B)

re: fclean all
