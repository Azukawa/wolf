All:
	gcc wolf3d_SDL.c wolf.h `sdl2-config --cflags --libs` -L./Libft/ -lft
