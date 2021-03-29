#include "minilibx-linux-master/mlx.h"
#include "Libft/inc/libft.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

typedef	struct			s_struct
{
	char	**map;
	int		x;
	int		y;
}						t_struct;

/*
 *	Simple 2d char array printer using prinf
 */
void	ft_print2dcarr(char **arr)
{
	int i;
	i = 0;
	if (!arr)
		return ;
	while(arr[i][0] != '\0')
	{
		printf("row%d =\t\t%s\n", i, arr[i]);
		i++;
	}
}

/*
 *	Skips ',' and ' ' characters,
 *	puts rest to ret, up to x(max widht of map)
 */
char	*linetogrid(char *ret, char *out, int x)
{
	int a;
	int i;

	i = 0;
	a = 0;

	while (i < x)
	{
		if(out[a] != ',' && out[a] != ' ')
		{
			ret[i] = out[a];
			i++;
		}
		a++;
	}
	return(ret);
}

/*
 *	The second redthrough of map file.
 *	Goes through file line by line,
 *	and builds final array with
 *	linetogrid()
 */
int			readmap(char *str, t_struct *s)
{
	int		fd;
	int		ret;
	int		i;
	int		a;
	char*	output;

	i = 0;
	a = 0;
	output = NULL;
	
	if ((fd = open(str, O_RDONLY)) == -1)
		return(0);
	while ((ret = get_next_line(fd, &output)) > 0)
	{
		s->map[i] = linetogrid(s->map[i], output, s->x);
		i++;
		free(output);
	}
	free(output);
	return(1);

}

/*
 *	The first read of map file.
 *	This function determines map.x and map.y.
 *	Y rows are counted by gnl,
 *	X is counted by the nro ',' on the row.
 */
int		checkmap(char *str, t_struct *s)
{
	int		fd;
	int		ret;
	int		i;
	char*	output;

	i = 0;
	output = NULL;
	
	if ((fd = open(str, O_RDONLY)) == -1)
		return(0);
	while ((ret = get_next_line(fd, &output)) > 0)
	{
		if(ft_countwords(output, ',') > s->x)
			s->x = ft_countwords(output, ',');
		i++;
		free(output);
	}
	s->y = i;
	free(output);
	return (0);
}

/*
 *	Allocates 2d character array,
 *	based  on map.x and map.y.
 *	Each row is zeroed,
 *	terminators are placed.
 */
int		initmap(t_struct *s)
{
	int i;
	i = 0;
	s->map = (char **)malloc(sizeof(char *) * s->y);
	while(i <= s->y)
	{
		s->map[i] = (char *)malloc(sizeof(char *) * s->x);
		ft_bzero(s->map[i], s->x);
		s->map[i][s->x] = '\0';
		i++;
	}
	ft_strclr(s->map[s->y]);
	return(0);
}

/*
 *	Simple mother function for
 *	commanding the seperate map
 *	reading functions.
 */
int			buildmap(char *str, t_struct *s)
{
	checkmap(str, s);
	initmap(s);
	readmap(str, s);
	return (0);
}

int			main(int argc, char** argv)
{
	t_struct	s;

	ft_memset(&s, 0, sizeof(s));
	buildmap(argv[1], &s);
	ft_print2dcarr(s.map);
	free(s.map);
	return (1);
}
