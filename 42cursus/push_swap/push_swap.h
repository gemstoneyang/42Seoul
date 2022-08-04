/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:05:14 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/05 02:23:36 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
}					t_node;

typedef struct s_stack
{
	struct s_stack	*top;
	struct s_stack	*bot;
	int				count;
}					t_stack;


void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);

t_node	*init_node(int val);
t_stack	*init_stack(void);

#endif
