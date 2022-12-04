/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:22:41 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 15:47:39 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf_bonus.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_param	p;

	if (argc != 2)
		ft_error_exit("argument error");
	p.mlx = init_mlx(1920, 1080);
	p.map = parse_map(argv[1]);
	p.info = init_info(p.mlx, p.map);
	print_screen(p.mlx, p.map, p.info);
	mlx_put_image_to_window(p.mlx->mlx, p.mlx->win, p.mlx->img, 0, 0);
	mlx_key_hook(p.mlx->win, hooks, &p);
	mlx_loop(p.mlx->mlx);
	return (0);
}
