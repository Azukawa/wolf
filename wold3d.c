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

int			buildmap(char *str, t_struct *s)
{
	checkmap(str, s);
	initmap(s);
	readmap(str, s);
	return (0);
}

int			main(int argc, char** argv)
{
	printf("alku\n");
	t_struct	s;
	ft_memset(&s, 0, sizeof(s));
	buildmap(argv[1], &s);
	printf("x = %d\ty = %d\n\n", s.x, s.y);
	ft_print2dcarr(s.map);
	free(s.map);
	printf("\nloppu\n");
	return (1);
}
