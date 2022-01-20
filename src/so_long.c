/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:46:37 by dramos-p          #+#    #+#             */
/*   Updated: 2022/01/19 22:19:01 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_del(void *content)
{
	free(content);
}

static void	erase_put(char *path, int l, int c, t_mlx *mlx)
{
	if (mlx->map[l][c] != '1')
	{
		if (mlx->map[l][c] == 'E' && mlx->c_count == 0)
		{
			mlx->c_move++;
			printf("TOTAL MOVES: %d\n", mlx->c_move);
			win_close(mlx);
			exit(0);
		}
		if (mlx->map[l][c] != 'E')
		{
			mlx->path = ft_strdup(path);
			ft_put_imgind(l, c, mlx);
			mlx->c_move++;
			printf("TOTAL MOVES: %d\n", mlx->c_move);
			free(mlx->path);
		}
	}
	if (mlx->map[l][c] == 'C')
		mlx->c_count--;
}

int	key_press(int key, t_mlx *mlx)
{
	if (key == D_KEY)
		erase_put("img/h_r.xpm", mlx->p_line, mlx->p_col + 1, mlx);
	if (key == A_KEY)
		erase_put("img/h_l.xpm", mlx->p_line, mlx->p_col - 1, mlx);
	if (key == W_KEY)
		erase_put("img/h_u.xpm", mlx->p_line - 1, mlx->p_col, mlx);
	if (key == S_KEY)
		erase_put("img/h_d.xpm", mlx->p_line + 1, mlx->p_col, mlx);
	if (key == ESC_KEY)
		win_close(mlx);
	return (0);
}

static void	ft_len_c(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < mlx->c.line)
	{
		y = 0;
		while (y < mlx->c.col)
		{
			if (mlx->map[x][y] == 'C')
				mlx->c_count++;
			if (mlx->map[x][y] == 'P')
				mlx->p_count++;
			if (mlx->map[x][y] == 'E')
				mlx->e_count++;
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		x;
	int		y;

	mlx.c_move = 0;
	mlx.c_count = 0;
	mlx.e_count = 0;
	mlx.p_count = 0;
	mlx.c = map_getlinecol(argv[1]);
	check_file(argc, argv, mlx.c);
	map_matriz(argv[1], mlx.c.line, &mlx);
	check_datafile(&mlx);
	check_maplimit(&mlx);
	ft_len_c(&mlx);
	check_cpe(&mlx);
	mlx.instance = mlx_init();
	x = mlx.c.col * 32;
	y = mlx.c.line * 32;
	mlx.win = mlx_new_window(mlx.instance, x, y, "so_long");
	set_conf_img(&mlx);
	draw(mlx.map, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, key_press, &mlx);
	mlx_hook(mlx.win, 33, 1L << 17, win_close, &mlx);
	mlx_loop(mlx.instance);
	return (0);
}
