/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:22:41 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/02 18:18:38 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_param param;

	if (argc != 2)
		error_exit("argument error");
	param.map = parse_map_info(argv[1]);
	parse_map(param.map, argv[1]);
	param.mlx = init_mlx(1920, 1080);
	param.info = init_info(param.mlx, param.map);
	print_screen(param.mlx, param.map, param.info);
	mlx_hook(param.mlx->win, 2, 1L<<0, hooks, &param);
	mlx_loop(param.mlx->mlx);
	return (0);
}
