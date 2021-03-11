# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esukava <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 12:13:28 by esukava           #+#    #+#              #
#    Updated: 2021/02/25 12:45:27 by alero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_LIST = \
	ft_abs.c\
	ft_atoi1000.c\
	ft_atoi.c\
	ft_bzero.c\
	ft_clamp.c\
	ft_countwords.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_iswhite.c\
	ft_itoa.c\
	ft_len.c\
	ft_lerp_1d.c\
	ft_memalloc.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memdel.c\
	ft_memmove.c\
	ft_memset.c\
	ft_pii.c\
	ft_putchar.c\
	ft_putchar_fd.c\
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_putnbr.c\
	ft_putnbr_fd.c\
	ft_putstr.c\
	ft_putstr_fd.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strclr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strctrim.c\
	ft_strdel.c\
	ft_strdup.c\
	ft_strequ.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strndup.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strsplit.c\
	ft_strstr.c\
	ft_strsub.c\
	ft_strtrim.c\
	ft_tolower.c\
	ft_toupper.c\
	get_next_line.c\
	ft_myrand.c
INCLUDE_DIR = inc
SRC_DIR = src
BUILD_DIR = build
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)
RM = rm -f
SRC = $(addprefix $(SRC_DIR)/, $(SRC_LIST))
OBJ = $(addprefix $(BUILD_DIR)/, $(SRC_LIST:.c=.o))
INCLUDES = inc

all : $(NAME)

$(NAME) :	$(OBJ)
	ar rc ${NAME} ${OBJ}

$(BUILD_DIR) :
	mkdir build

#
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/libft.h | $(BUILD_DIR)
	gcc $(CFLAGS) -c $< -o $@

debug : CFLAGS = -g -Wall -Wextra -Werror
debug : all

clean :
	rm -R -f $(BUILD_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re debug
