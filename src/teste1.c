#include "../mlx_linux/mlx.h"
#include <stdio.h>

typedef struct		s_col
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_col;

typedef struct		s_tex
{
	void			*img;
	char			*data;
	int				bpp;
	int				size;
	int				endian;
}					t_tex;

typedef	struct		s_env
{
	struct s_tex tex_tab[5];
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		size;
	int		endian;
	int		lenght;
	int		width;
	int		tex_id;
	int		color;
}					t_env;

int		expose(t_env *e)
{
    printf("%d",e->lenght);
	return (0);
}

int		loader(t_env *e, t_tex *image, char *file)
{
	if (!(image->img = mlx_xpm_file_to_image(e->mlx, file, &e->lenght, &e->width)))
		return (-1);
	image->data = mlx_get_data_addr(image->img, &image->bpp, &image->size, &image->endian);
	return (0);
}

void	tex_init(t_env *e)
{
	loader(e, &e->tex_tab[0], "./p1.xpm");
	loader(e, &e->tex_tab[1], "./p1.xpm");
	loader(e, &e->tex_tab[2], "./p1.xpm");
}

void	put_pixel_to_image(t_env *e, t_col *col, int x, int y)
{
	e->data[y * e->size + x * (e->bpp / 8)] = col->b;
	e->data[y * e->size + x * (e->bpp / 8) + 1] = col->g;
	e->data[y * e->size + x * (e->bpp / 8) + 2] = col->r;
}
void	get_pxl_col(t_env *e, t_col *col, int x, int y)
{
	if (x >= 64)
		x  = x % 64;
	if (y >= 64)
		y = y % 64;
	col->b = e->tex_tab[e->tex_id].data[(y
			* e->tex_tab[e->tex_id].size
			+ e->tex_tab[e->tex_id].bpp / 8
			* x)];
	col->g = e->tex_tab[e->tex_id].data[(y
			* e->tex_tab[e->tex_id].size
			+ e->tex_tab[e->tex_id].bpp / 8
			* x) + 1];
	col->r = e->tex_tab[e->tex_id].data[(y
			* e->tex_tab[e->tex_id].size
			+ e->tex_tab[e->tex_id].bpp / 8
			* x) + 2];
}

int		main()
{
	t_env e;
	t_col col;
	int	x;
	int	y;
	// void *img;

	x = 0;
	y = 0;
	e.lenght = 64;
	e.width = 64;
	e.tex_id = 0;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 600, 600, "xmp");
	e.img = mlx_new_image(e.mlx, 600, 600);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.size, &e.endian);
	tex_init(&e);
	while (x < 600)
	{
		y = 0;
		while (y < 600)
		{
			get_pxl_col(&e, &col, x, y);
			put_pixel_to_image(&e, &col, x, y);
			y++;
		}
		x++;
	}
	mlx_xpm_file_to_image(e.mlx, "./p1.xpm", &e.lenght, &e.lenght);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	//mlx_put_image_to_window(e.mlx, e.win, img, 200, 200);
	mlx_expose_hook(e.win, expose, &e);
	mlx_loop(e.mlx);
	return (0);
}
