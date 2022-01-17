/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:50:51 by dramos-p          #+#    #+#             */
/*   Updated: 2022/01/16 23:37:35 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_linux/mlx.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

#  define W_KEY			119
#  define A_KEY			97
#  define S_KEY			115
#  define D_KEY			100
#  define ESC_KEY		65307

typedef struct s_dataimg
{
	char				*content;
	char				opt;
	int					x;
	int					y;
	struct s_dataimg	*next;
}	t_dataimg;

typedef struct s_map
{
	char	*str;
	int		line;
	int		col;
	int		validate;
}	t_map;

typedef struct s_mlx
{
	void	*instance;
	void	*win;
	void	*img;
	int		x;
	int		y;
	int		p_line;
	int		p_col;
	int		c_move;
	int		c_count;
	int		p_count;
	int		e_count;
	char	*path;
	t_dataimg	*conf_img;
	char	**map;
	t_map	c;
}	t_mlx;

int	win_close(t_mlx *mlx);
int ft_equal(int x, int y);
t_map map_getlinecol(char *file);
char	**map_matriz(char *file, int line);
void	check_file(int argc, char **argv, t_map m);
t_dataimg	*ft_lstnew_md(void *content, char opt);
void	ft_lstadd_back_md(t_dataimg **lst, t_dataimg *new);
t_dataimg	*ft_lstlast_md(t_dataimg *lst);
void	ft_lstclear_md(t_dataimg **lst, void (*del)(void*));
void	ft_lstdelone_md(t_dataimg *lst, void (*del)(void*));
void 	set_conf_img(t_mlx	*mlx);
void	draw(char **map, t_mlx	*mlx);
void	ft_del(void *content);
void	get_imgdraw(char c, int i, int x, t_mlx *mlx);
void	ft_put_imgind(int line, int col, t_mlx *mlx);
void	check_datafile(t_mlx *mlx);
void	check_maplimit(t_mlx *mlx);
void	check_cpe(t_mlx *mlx);

#endif