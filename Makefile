NAME = wolf3d

#compiler
CC = clang
CFLAGS = -Wall -Wextra -Werror $(LIBSDL_CFLAGS)
#$(addprefix -I, $(INCLUDE_DIRS))

#sources

#includes
INCLUDE_DIRS = includes/ libft/includes/
#libft

#SDL2
SOURCE_DIR = SDL2-2.0.14
BUILD_DIR = libSDL2
BUILD_DIR_PATH = $(CURDIR)/$(BUILD_DIR)
LIBSDL_CFLAGS = `$(BUILD_DIR)/bin/sdl2-config --cflags --libs`

.PHONY: all SDL clean fclean re

all:
	gcc wolf3d_SDL.c wolf.h $(CFLAGS) -L./Libft/ -lft

SDL :
	echo "Extracting SDL archive..."
	tar xzf SDL2-2.0.14.tar.gz
	mkdir -p $(BUILD_DIR)
	cd $(SOURCE_DIR); ./configure --prefix=$(BUILD_DIR_PATH); make; make install

clean :
	rm -f $(SOURCE_DIR)

fclean : clean

re : fclean all