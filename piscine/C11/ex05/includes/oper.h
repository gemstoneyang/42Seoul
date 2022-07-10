/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:24:52 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/06 13:03:24 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPER_H
# define OPER_H

int		plus(int a, int b);
int		minus(int a, int b);
int		multi(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
int		is_oper(char *op);
void	print_num(int n);

#endif
