NAME	=	wolf3d

#compiler
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

#sources & object files
SRC_DIR =	./src/
OBJ_DIR =	./build/
SRC_LIST =	main.c \
		buildmap.c \
		checkmap.c \
		cleanup.c \
		drawmap.c \
		drawpixel.c \
		ft_print2dcarr.c \
		initmap.c \
		initSDL.c \
		linetogrid.c \
		readmap.c \
		drawline.c \
		drawcircle.c \
		keyevent.c \
		raycaster.c \
		drawplayer.c
SRCS = $(addprefix $(SRC_DIR),$(SRC_LIST))
OBJS = $(addprefix $(OBJ_DIR),$(SRC_LIST:.c=.o))

#libft
LIBFT = libft/libft.a

#SDL2
SLD_SRC_DIR = SDL2-2.0.14
SDL_DIR = libSDL2
SDL_BUILD_DIR_PATH = $(CURDIR)/$(BUILD_DIR)
SDL_CFLAGS = `$(SDL_DIR)/bin/sdl2-config --cflags --libs`

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -Iinclude/ -Ilibft/includes -I$(SDL_DIR)/include/SDL2 -o $@ -c $<

$(LIBFT):
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(SDL_CFLAGS) -L./libft/ -lft -lm -o $(NAME)

SDL:
	echo "Extracting SDL archive..."
	tar xzf SDL2-2.0.14.tar.gz
	mkdir -p $(SDL_DIR)
	cd $(SDL_SRC_DIR); ./configure --prefix=$(SDL_BUILD_DIR_PATH); make; make install

clean:
	make clean -C libft
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)
	rm -rf $(SOURCE_DIR)
	make fclean -C libft

re: fclean all
