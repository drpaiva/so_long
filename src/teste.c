#include "../mlx_linux/mlx.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	char	*relative_path = "p1.xpm";
	int		img_width;
	int		img_height;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	img_width = 22;
	img_height = 37;
	mlx = mlx_init(); // inicio
	mlx_win = mlx_new_window(mlx, 400, 400, "Hello world!"); // crio janela
	// img.img = mlx_new_image(mlx, 400, 400);// crio imagem com tamanho da janela
	// capturo o endereco da memoria da imagem ????
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img.img == NULL)
	{
		printf("vazia");
	}
	
	// my_mlx_pixel_put(&img, 5, 5, 0x00ff00);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 20, 100);
	mlx_loop(mlx);
}