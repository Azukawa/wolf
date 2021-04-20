NAME = wolf3d

#compiler
CC = clang
CFLAGS = -Wall -Wextra -Werror $(LIBSDL_CFLAGS)
#$(addprefix -I, $(INCLUDE_DIRS))
SRC_DIR = src
BUILD_DIR = build
#sources
SRC_LIST = main.c \
		buildmap.c \
		checkmap.c \
		cleanup.c \
		drawmap.c \
		drawpixel.c \
		ft_print2dcarr.c \
		initmap.c \
		initSDL.c \
		linetogrid.c \
		readmap.c

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC_LIST:.c=.o))
#includes
INCLUDE_DIRS = includes/ libft/includes/
#libft

#SDL2
SOURCE_DIR = SDL2-2.0.14
BUILD_DIR = libSDL2
BUILD_DIR_PATH = $(CURDIR)/$(BUILD_DIR)
LIBSDL_CFLAGS = `$(BUILD_DIR)/bin/sdl2-config --cflags --libs`
SRC = $(addprefix $(SRC_DIR)/, $(SRC_LIST))
.PHONY: all SDL clean fclean re

all:
	make -C libft
	make -C ftprintf
	gcc $(SRC) include/wolf.h $(CFLAGS) -L./libft/ -lft -L./ftprintf/ -lftprintf

SDL :
	echo "Extracting SDL archive..."
	tar xzf SDL2-2.0.14.tar.gz
	mkdir -p $(BUILD_DIR)
	cd $(SOURCE_DIR); ./configure --prefix=$(BUILD_DIR_PATH); make; make install

clean :
	make clean -C libft
	make clean -C ftprintf

fclean : clean
	rm -rf $(SOURCE_DIR)
	make fclean -C libft
	make fclean -C ftprintf

re : fclean all
