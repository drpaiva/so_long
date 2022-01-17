/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:54:27 by dramos-p          #+#    #+#             */
/*   Updated: 2022/01/16 23:46:35 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_file(int argc, char **argv, t_map m)
{
	char	*ext;
	char	*str;

	if (argc != 2 || m.validate == 0)
	{
		ft_putstr_fd("Error\n Input file must be of type .ber\n", 1);
		ft_putstr_fd("./so_long *.ber\n", 1);
		exit(0);
	}
	ext = ".ber";
	str = ft_strrchr(argv[1], 46);
	if (ft_strncmp(ext, str, 4) != 0)
	{
		ft_putstr_fd("Error\n Input file must be of type .ber\n", 1);
		exit(0);
	}
}

static int	ft_char_auth(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'E')
		return (1);
	return (0);
}

void	check_datafile(t_mlx *mlx)
{
	int	l;
	int	c;

	l = 0;
	while (l < mlx->c.line)
	{
		c = 0;
		while (c < mlx->c.col)
		{
			if (ft_char_auth(mlx->map[l][c]))
			{
				ft_putstr_fd("Error\n  File.ber char invalid!\n", 1);
				exit(0);
			}
			c++;
		}
		l++;
	}
}

static int	ft_is_limit(char c)
{
	if (c != '1')
	{
		ft_putstr_fd("Error\n  File.ber format invalid!\n", 1);
		return (1);
	}
	return (0);
}

void	check_maplimit(t_mlx *mlx)
{
	int	l;
	int	c;

	l = 0;
	while (l < mlx->c.line)
	{
		c = 0;
		if (ft_is_limit(mlx->map[l][c]))
			exit(0);
		while (c < mlx->c.col)
		{
			if (ft_is_limit(mlx->map[0][c]))
				exit(0);
			if (ft_is_limit(mlx->map[mlx->c.line - 1][c]))
				exit(0);
			if (ft_is_limit(mlx->map[l][mlx->c.col - 1]))
				exit(0);
			c++;
		}
		l++;
	}
}
