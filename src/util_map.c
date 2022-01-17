/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:38:30 by dramos-p          #+#    #+#             */
/*   Updated: 2022/01/13 02:06:24 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_equal(int x, int y)
{
	if (x == y)
		return (1);
	return (0);
}

t_map	map_getlinecol(char *file)
{
	t_map	x;
	int		y[2];

	x.validate = 1;
	x.line = 0;
	y[0] = 1;
	y[1] = open(file, O_RDONLY);
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

char	**map_matriz(char *file, int line)
{
	char	**map;
	char	*str;
	int		fd;
	// int		out;
	int		i;

	// out = 1;
	map = (char **)ft_calloc(line, sizeof(int *));
	i = 0;
	// while (i < line)
	// {
	// 	map[i] = malloc(col * sizeof(int));
	// 	i++;
	// }
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < line)
	{
		get_next_line(fd, &str);
		map[i] = ft_strdup(str);

		// y = 0;
		// while (y < col)
		// {
		// 	map[i][y] = str[y];
		// }
		i++;
		free(str);
	}
	return (map);

}
