# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 09:35:10 by jrinna            #+#    #+#              #
#    Updated: 2023/04/26 11:31:29 by jrinna           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#update on every project
LST_SRC :=	BitcoinExchange main

NAME := btc

#update to match c or cpp
CC := c++
FILE_EXT := .cpp
HEADER_EXT := .hpp
CPPFLAGS := -std=c++98 #-pedantic

#update if needed
CFLAGS = -Wall -Wextra -Werror -MD -I$(DIR_INC) -g3 #-fsanitize=address -g3
DIR_SRC := .#source
SUB_DIR_LST := .

#shouldn't need to update
RM := rm -rf
MD := mkdir -p

DIR_INC := include
DIR_OBJ := .object

OBJ=$(addprefix $(DIR_OBJ)/,$(addsuffix .o,$(LST_SRC)))
DEP=$(addprefix $(DIR_OBJ)/,$(addsuffix .d,$(LST_SRC)))
SUB_DIR=$(addprefix $(DIR_OBJ)/,$(SUB_DIR_LST))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(DIR_OBJ)/%.o : $(DIR_SRC)/%$(FILE_EXT) Makefile | $(SUB_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(SUB_DIR) :
	$(MD) $@

clean :
	$(RM) $(DIR_OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

-include $(DEP)