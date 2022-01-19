/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:38:30 by dramos-p          #+#    #+#             */
/*   Updated: 2022/01/19 01:54:54 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_equal(int x, int y)
{
	if (x == y)
		return (1);
	return (0);
}
static int ft_open_res(char *file)
{
	int res;
	char	*ext;
	char	*str;

	ext = ".ber";
	str = ft_strrchr(file, 46);
	if (ft_strncmp(ext, str, 4) != 0)
	{
		ft_putstr_fd("Error\n Input file must be of type .ber\n", 1);
		exit(0);
	}

	res = open(file, O_RDONLY);
	if(res < 0)
	{
		ft_putstr_fd("Error\n  File.ber not open!\n", 1);
		exit(0);
	}
	return (res);
}

t_map	map_getlinecol(char *file)
{
	t_map	x;
	int		y[2];

	x.validate = 1;
	x.line = 0;
	y[0] = 1;
	y[1] = ft_open_res(file);
	while (y[0] && (x.validate == 1))
	{
		y[0] = get_next_line(y[1], &x.str);
		if (x.line == 0)
			x.col = ft_strlen(x.str);
		if (x.line != 0)
		{
			if (ft_equal(x.col, ft_strlen(x.str)))
				x.validate = 1;
			else
				x.validate = 0;
			x.col = ft_strlen(x.str);
		}
		free(x.str);
		x.line++;
	}
	close(y[1]);
	return (x);
}

void	map_matriz(char *file, int line, t_mlx *mlx)
{
	// char	**map;
	char	*str;
	int		fd;
	// int		out;
	int		i;

	// out = 1;
	mlx->map = (char **)ft_calloc(line, sizeof(int *));
	i = 0;

	fd = open(file, O_RDONLY);
	i = 0;
	while (i < line)
	{
		get_next_line(fd, &str);
		mlx->map[i] = ft_strdup(str);

		i++;
		free(str);
	}
}
