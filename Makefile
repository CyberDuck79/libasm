# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/28 09:21:09 by fhenrion          #+#    #+#              #
#    Updated: 2020/04/04 14:46:24 by fhenrion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
SRCS_NAME = strlen strcpy strcmp write read strdup memcpy bzero
SRCS_BONUS_NAME = atoi checkset checkdup skipset setindex atoi_base new_list \
list_size list_push_front list_pop_front
TEST_NAME = test
DBG_NAME = dbg

SRCS = $(addprefix ft_,$(SRCS_NAME))
SRCS_BONUS = $(addprefix ft_,$(SRCS_BONUS_NAME))
SRC_TEST = $(addsuffix .c,$(TEST_NAME))
SRC_DBG = $(addsuffix .s,$(DBG_NAME))
OBJ_DBG = $(addsuffix .o,$(DBG_NAME))

OBJS = $(addsuffix .o,$(SRCS))
OBJS_BONUS = $(addsuffix .o,$(SRCS_BONUS))

ASM_COMPILER = nasm
ASM_FLAGS = -f macho64 -g -F dwarf

C_COMPILER = gcc
#C_FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
C_FLAGS = -g -fsanitize=address

LINKER = ld
L_FLAGS = -e _main -macosx_version_min 10.15 -lSystem

LIB_ARCHIVER = ar rc
LIB_INDEXER = ranlib

DBG_SYMBOLS = test.dSYM

.PHONY: all re clean fclean bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB_ARCHIVER) $(NAME) $(OBJS)
	$(LIB_INDEXER) $(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
	$(LIB_ARCHIVER) $(NAME) $(OBJS) $(OBJS_BONUS)
	$(LIB_INDEXER) $(NAME)

$(TEST_NAME): $(NAME) $(OBJS) $(OBJS_BONUS) $(SRC_TEST)
	$(C_COMPILER) $(C_FLAGS) $^ -o $@
	./$(TEST_NAME)

$(DBG_NAME): $(OBJS) $(OBJS_BONUS) $(OBJ_DBG)
	$(LINKER) $(L_FLAGS) $^ -o $@

%.o: %.s
	$(ASM_COMPILER) $(ASM_FLAGS) -o $@ $<

clean:
	rm -rf $(OBJS) $(OBJS_BONUS) $(OBJ_DBG) $(DBG_SYMBOLS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME) $(DBG_NAME)

re: fclean all
retest: fclean bonus $(TEST_NAME)
redbg: fclean $(DBG_NAME)
