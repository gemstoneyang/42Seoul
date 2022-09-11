/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:04:09 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/11 23:25:03 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	char	*input_cmd;

	data = init_data();
	parse_nums(argc, argv, data);
	validation_data(argc, data);
	while (1)
	{
		if (get_next_line(&input_cmd, 0) == ERROR)
			error_exit(data);
		if (input_cmd == NULL)
			break ;
		if (cmd(input_cmd, data) == ERROR)
		{
			free(input_cmd);
			error_exit(data);
		}
		free(input_cmd);
	}
	check_result(data);
	return (0);
}
