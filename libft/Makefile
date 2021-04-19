# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/11 10:42:46 by eniini            #+#    #+#              #
#    Updated: 2021/04/01 20:56:09 by eniini           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# sources
SRC_DIR = ./srcs
INC_DIR = ./includes
SRC = array_utils/ft_free_arr.c \
	array_utils/ft_get_arr_size.c \
	char_utils/ft_isalnum.c \
	char_utils/ft_isalpha.c \
	char_utils/ft_isascii.c \
	char_utils/ft_isdigit.c \
	char_utils/ft_islower.c \
	char_utils/ft_isprint.c \
	char_utils/ft_isspace.c \
	char_utils/ft_isupper.c \
	char_utils/ft_tolower.c \
	char_utils/ft_toupper.c \
	file_io/ft_putchar_fd.c \
	file_io/ft_putchar.c \
	file_io/ft_putendl_fd.c \
	file_io/ft_putendl.c \
	file_io/ft_putnbr_fd.c \
	file_io/ft_putnbr.c \
	file_io/ft_putstr_fd.c \
	file_io/ft_putstr.c \
	file_io/get_next_line.c \
	gfx/ft_d_lerp.c \
	gfx/ft_i_lerp.c \
	gfx/ft_inverse_d_lerp.c \
	gfx/ft_inverse_i_lerp.c \
	llist_utils/ft_elemdel.c \
	llist_utils/ft_lstadd.c \
	llist_utils/ft_lstaddl.c \
	llist_utils/ft_lstdel.c \
	llist_utils/ft_lstdelone.c \
	llist_utils/ft_lstiter.c \
	llist_utils/ft_lstmap.c \
	llist_utils/ft_lstnew.c \
	math/ft_abs.c \
	math/ft_clamp_d.c \
	math/ft_clamp_i.c \
	math/ft_pow.c \
	mem_utils/ft_bzero.c \
	mem_utils/ft_memalloc.c \
	mem_utils/ft_memccpy.c \
	mem_utils/ft_memchr.c \
	mem_utils/ft_memcmp.c \
	mem_utils/ft_memcpy.c \
	mem_utils/ft_memdel.c \
	mem_utils/ft_memmove.c \
	mem_utils/ft_memset.c \
	mem_utils/ft_realloc.c \
	mem_utils/ft_swap.c \
	process_control/ft_getout.c \
	string_utils/ft_strcat.c \
	string_utils/ft_strchr.c \
	string_utils/ft_strclr.c \
	string_utils/ft_strcmp.c \
	string_utils/ft_strcpy.c \
	string_utils/ft_strdel.c \
	string_utils/ft_strdup.c \
	string_utils/ft_strequ.c \
	string_utils/ft_striter.c \
	string_utils/ft_striteri.c \
	string_utils/ft_strjoin.c \
	string_utils/ft_strlcat.c \
	string_utils/ft_strlen.c \
	string_utils/ft_strmap.c \
	string_utils/ft_strmapi.c \
	string_utils/ft_strncat.c \
	string_utils/ft_strncmp.c \
	string_utils/ft_strncpy.c \
	string_utils/ft_strndup.c \
	string_utils/ft_strnequ.c \
	string_utils/ft_strnew.c \
	string_utils/ft_strnstr.c \
	string_utils/ft_strrchr.c \
	string_utils/ft_strsplit.c \
	string_utils/ft_strstr.c \
	string_utils/ft_strsub.c \
	string_utils/ft_strtrim.c \
	string_utils/ft_wordcount.c \
	type_conversion/ft_atoi.c \
	type_conversion/ft_ftoa.c \
	type_conversion/ft_itoa_base.c \
	type_conversion/ft_itoa.c \
	type_conversion/ft_uitoa_base.c \
	type_conversion/ft_uitoa.c \
	wchar_utils/ft_putwchar.c \
	wchar_utils/ft_putwstr.c \
	wchar_utils/ft_wcharlen.c \
	wchar_utils/ft_wstrlen.c

OBJ = $(notdir $(SRC:.c=.o))

#colors
CYAN = \033[0;36m
NOCOL = \033[0m

.PHONY : all clean fclean re

all :
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $(addprefix $(SRC_DIR)/,$(SRC))
	@ar rcs $(NAME) $(OBJ)
	@echo "${CYAN}[libft] libft archive created${NOCOL}"

clean :
	@rm -f $(OBJ)
	@echo "${CYAN}[libft] .obj files removed${NOCOL}"

fclean : clean
	@rm -f $(NAME)
	@echo "${CYAN}[libft] archive removed${NOCOL}"

re : fclean all
