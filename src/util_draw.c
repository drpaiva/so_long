/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:33:43 by dramos-p          #+#    #+#             */
/*   Updated: 2022/01/20 00:07:41 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_cpe(t_mlx *mlx)
{
	if (mlx->c_count < 1)
	{
		ft_putstr_fd("Error\n  File.ber no collectible item!\n", 1);
		exit(0);
	}
	if (mlx->p_count != 1)
	{
		ft_putstr_fd("Error\n  File.ber multiple initial position!\n", 1);
		exit(0);
	}
	if (mlx->e_count < 1)
	{
		ft_putstr_fd("Error\n  File.ber no exist exit!\n", 1);
		exit(0);
	}	
}

void	get_imgdraw(char c, int i, int x, t_mlx *mlx)
{
	t_dataimg	*p;
	void		*s;

	s = mlx->instance;
	p = mlx->conf_img;
	while (p != NULL)
	{
		if ((p->opt) == c)
		{
			mlx->img = mlx_xpm_file_to_image(s, p->content, &mlx->x, &mlx->y);
			mlx_put_image_to_window(mlx->instance, mlx->win, mlx->img, x, i);
			mlx_destroy_image(mlx->instance, mlx->img);
		}
		p = p->next;
	}
}

void	ft_put_imgind(int line, int col, t_mlx *mlx)
{
	void	*s;
	int		c;
	int		l;

	c = mlx->p_col * 32;
	l = mlx->p_line * 32;
	s = mlx->instance;
	mlx->img = mlx_xpm_file_to_image(s, "img/floor.xpm", &mlx->x, &mlx->y);
	mlx_put_image_to_window(s, mlx->win, mlx->img, c, l);
	mlx_destroy_image(mlx->instance, mlx->img);
	mlx->p_col = col;
	mlx->p_line = line;
	c = mlx->p_col * 32;
	l = mlx->p_line * 32;
	mlx->img = mlx_xpm_file_to_image(s, mlx->path, &mlx->x, &mlx->y);
	mlx_put_image_to_window(mlx->instance, mlx->win, mlx->img, c, l);
	mlx_destroy_image(mlx->instance, mlx->img);
}
