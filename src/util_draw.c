/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:33:43 by dramos-p          #+#    #+#             */
/*   Updated: 2022/01/16 23:32:05 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check_cpe(t_mlx *mlx)
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

void get_imgdraw(char c, int i, int x, t_mlx *mlx)
{
	t_dataimg	*p;

	p = mlx->conf_img;

	while (p != NULL)
	{
		if ((p->opt) == c)
		{
			mlx->img = mlx_xpm_file_to_image(mlx->instance, p->content, &mlx->x, &mlx->y);
			mlx_put_image_to_window(mlx->instance, mlx->win, mlx->img, x , i);
			mlx_destroy_image(mlx->instance, mlx->img);
		}
		p = p->next;
	}

}

void ft_put_imgind(int line, int col, t_mlx *mlx)
{
	mlx->img = mlx_xpm_file_to_image(mlx->instance, "img/floor.xpm", &mlx->x, &mlx->y);
	mlx_put_image_to_window(mlx->instance, mlx->win, mlx->img, mlx->p_col * 32, mlx->p_line * 32);
	mlx_destroy_image(mlx->instance, mlx->img);

	mlx->p_col = col;
	mlx->p_line = line;
	mlx->img = mlx_xpm_file_to_image(mlx->instance, mlx->path, &mlx->x, &mlx->y);
	mlx_put_image_to_window(mlx->instance, mlx->win, mlx->img, mlx->p_col * 32, mlx->p_line * 32);
	mlx_destroy_image(mlx->instance, mlx->img);
}
