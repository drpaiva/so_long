/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:08:18 by dramos-p          #+#    #+#             */
/*   Updated: 2022/01/19 02:08:44 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	win_close(t_mlx *mlx)
{
	int	i;

	mlx_destroy_window(mlx->instance, mlx->win);
	i = 0;
	while (i < mlx->c.line)
	{
		free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
	ft_lstclear_md(&mlx->conf_img, ft_del);
	free(mlx->instance);
	exit(0);
	return (0);
}


void set_conf_img(t_mlx	*mlx)
{
	mlx->conf_img = ft_lstnew_md(ft_strdup("img/floor.xpm"), '0');
	ft_lstadd_back_md(&mlx->conf_img, ft_lstnew_md(ft_strdup("img/x_p.xpm"), '1'));
	ft_lstadd_back_md(&mlx->conf_img, ft_lstnew_md(ft_strdup("img/fruit.xpm"), 'C'));
	ft_lstadd_back_md(&mlx->conf_img, ft_lstnew_md(ft_strdup("img/out.xpm"), 'E'));
	ft_lstadd_back_md(&mlx->conf_img, ft_lstnew_md(ft_strdup("img/h_r.xpm"), 'P'));
}

void draw(char **map, t_mlx	*mlx)
{
	int l;
	int c;

	l = 0;
	while (l < mlx->c.line)
	{
		c = 0;
		while (c < mlx->c.col)
		{
			if (map[l][c] == 'P')
			{
				mlx->p_col = c;
				mlx->p_line = l;
			}
			
			get_imgdraw(map[l][c], l * 32, c * 32, mlx);

			c++;
		}
		l++;
	}


	
}
