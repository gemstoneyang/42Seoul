/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongble <jeongble@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:35:38 by jeongble          #+#    #+#             */
/*   Updated: 2022/06/09 22:40:42 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include "ex00/ft_create_elem.c"
#include "ex01/ft_list_push_front.c"
#include "ex02/ft_list_size.c"
#include "ex03/ft_list_last.c"
#include "ex04/ft_list_push_back.c"
#include "ex05/ft_list_push_strs.c"
#include "ex06/ft_list_clear.c"
#include "ex07/ft_list_at.c"/*
#include "ex08/ft_list_reverse.c"
#include "ex09/ft_list_foreach.c"
#include "ex10/ft_list_foreach_if.c"
#include "ex11/ft_list_find.c"
#include "ex12/ft_list_remove_if.c"
#include "ex13/ft_list_merge.c"
#include "ex14/ft_list_sort.c"
#include "ex15/ft_list_reverse_fun.c"
#include "ex16/ft_sorted_list_insert.c"
#include "ex17/ft_sorted_list_merge.c"
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void	pt(void *str);
int		ft_strcmp(void *s3, void *s4);
int	main(void)
{
	{
		printf("\n===============EX00===============\n\n");
		t_list	*ex00;
		char	*is;
		is = (char *)malloc(3);
		is[0] = 'I';
		is[1] = 'S';
		is[2] = 0;
		ex00 = ft_create_elem(is);
		printf("data = IS\nnext = 0x0\n\n");
		printf("data = %s\nnext = %p\n",ex00-> data, ex00-> next); 
		printf("\n===============EX01===============\n\n");
		char	*jeongble;
		jeongble = (char *)malloc(8);
		jeongble[0] = 'J';
		jeongble[1] = 'E';
		jeongble[2] = 'O';
		jeongble[3] = 'N';
		jeongble[4] = 'G';
		jeongble[5] = 'B';
		jeongble[6] = 'L';
		jeongble[7] = 'E';
		jeongble[8] = 0;
		ft_list_push_front(&ex00, jeongble);
		printf("0 : JEONGBLE 1 : IS\n\n");
		printf("0 : %s 1 : %s\n", ex00-> data, (ex00-> next)-> data);
		printf("\n===============EX02===============\n\n");
		int	i = ft_list_size(ex00);
		printf("size = 2\n\n");
		printf("size = %d\n", i);
		printf("\n===============EX03===============\n\n");
		printf("last data : IS next : 0x0\n\n");
		printf("last data : %s next : %p\n", ft_list_last(ex00)-> data, ft_list_last(ex00)-> next);
		printf("\n===============EX04===============\n\n");
		char	*trash;
		trash = (char *)malloc(6);
		trash[0] = 'T';
		trash[1] = 'R';
		trash[2] = 'A';
		trash[3] = 'S';
		trash[4] = 'H';
		trash[5] = 0;
		ft_list_push_back(&ex00, trash);
		printf("0 : JEONGBLE 1 : IS 2 : TRASH\n\n");
		printf("0 : %s 1 : %s 2 : %s\n", ex00-> data, (ex00-> next)-> data, ((ex00-> next)-> next)-> data);
		printf("\n===============EX05===============\n\n");
		char	*strs[3];
		strs[0] = "JEONGBLE";
		strs[1] = "IS";
		strs[2] = "TRASH";
		t_list	*ex05 = ft_list_push_strs(3, strs);
		printf("0 : TRASH 1 : IS 2 : JEONGBLE\n\n");
		printf("0 : %s 1 : %s 2 : %s\n", ex05-> data, (ex05-> next)-> data, ((ex05-> next)-> next)-> data);
		free((ex05-> next)-> next);
		free(ex05-> next);
		free(ex05);	
		printf("\n===============EX06===============\n\n");
		
		ft_list_clear(ex00, &free);
		printf("ALL CLEAR OK\n");
		
		printf("\n===============EX07===============\n\n");
		ex05 = ft_list_push_strs(3, strs);
		t_list	*ex07 = ft_list_at(ex05, 1);
		printf("2 : IS\n\n");
		printf("2 : %s\n", ex07-> data);/*
		printf("\n===============EX08===============\n\n");
		char	**strs2;
		strs2 = (char **)malloc(sizeof(char *) * 3);
		is = (char *)malloc(3);
		is[0] = 'I';
		is[1] = 'S';
		is[2] = 0;
		jeongble = (char *)malloc(8);
		jeongble[0] = 'J';
		jeongble[1] = 'E';
		jeongble[2] = 'O';
		jeongble[3] = 'N';
		jeongble[4] = 'G';
		jeongble[5] = 'B';
		jeongble[6] = 'L';
		jeongble[7] = 'E';
		jeongble[8] = 0;
		trash = (char *)malloc(6);
		trash[0] = 'T';
		trash[1] = 'R';
		trash[2] = 'A';
		trash[3] = 'S';
		trash[4] = 'H';
		trash[5] = 0;
		strs2[0] = trash;
		strs2[1] = is;
		strs2[2] = jeongble;
		t_list	*ex08 = ft_list_push_strs(3, strs2);
		printf("before : %s %s %s\n", ex08-> data, (ex08-> next)-> data, ((ex08-> next)-> next)-> data);
		ft_list_reverse(&ex08);
		printf("after  : %s %s %s\n", ex08-> data, (ex08-> next)-> data, ((ex08-> next)-> next)-> data);
		
		printf("\n===============EX09===============\n");	
		printf("****print all****\n\n");
		ft_list_foreach(ex08, &pt);
		printf("\n\n===============EX10===============\n");
		printf("****print  IS****\n\n");
		ft_list_foreach_if(ex08, &pt, "IS", &ft_strcmp);
		printf("\n\n===============EX11===============\n");
		
		t_list	*now;
		printf("**print JEONGBLE**\n\n");
		now = ft_list_find(ex08, "JEONGBLE", &ft_strcmp);
		printf("%s", now-> data);
		printf("\n\n===============EX12===============\n");
		printf("****remove JEONGBLE****\n\n");
		ft_list_remove_if(&ex08, "JEONGBLE", &ft_strcmp, &free);
		ft_list_foreach(ex08, &pt);
		printf("\n\n===============EX13===============\n");
		printf("*****merge JEONGBLE*****\n\n");
		jeongble = (char *)malloc(8);
		jeongble[0] = 'J';
		jeongble[1] = 'E';
		jeongble[2] = 'O';
		jeongble[3] = 'N';
		jeongble[4] = 'G';
		jeongble[5] = 'B';
		jeongble[6] = 'L';
		jeongble[7] = 'E';
		jeongble[8] = 0;
		t_list *mm = ft_create_elem(jeongble);
		ft_list_merge(&ex08, mm);
		ft_list_foreach(ex08, &pt);
		printf("\n\n===============EX14===============\n\n");
		char **str4;
		str4 = (char **)malloc(sizeof(char *) * 5);
		char	z[2] = {'z',};
		char	t[2] = {'t',};
		char	a[2] = {'a',};
		char	g[2] = {'g',};
		char	v[2] = {'v',};
		str4[0] = z;
		str4[1] = t;
		str4[2] = a;
		str4[3] = g;
		str4[4] = v;
		t_list	*ex14 = ft_list_push_strs(5, str4);
		printf("before : ");ft_list_foreach(ex14, &pt);
		printf("\n\n");
		ft_list_sort(&ex14, &ft_strcmp);
		printf("after  : ");ft_list_foreach(ex14, &pt);
		printf("\n\n===============EX15===============\n\n");
		printf("before : ");ft_list_foreach(ex14, &pt);
		printf("\n\n");
		ft_list_reverse_fun(ex14);
		printf("after  : ");ft_list_foreach(ex14, &pt);
		printf("\n\n===============EX16===============\n\n");
		ft_list_reverse_fun(ex14);
		printf("before : ");ft_list_foreach(ex14, &pt);
		char	s[2] = {'s',};
		ft_sorted_list_insert(&ex14, s, &ft_strcmp);
		printf("\n\n");
		printf("after : ");ft_list_foreach(ex14, &pt);
		printf("\n\n===============EX17===============\n\n");
		char **str5;
		str5 = (char **)malloc(sizeof(char *) * 5);
		char	h[2] = {'h',};
		char	k[2] = {'k',};
		char	x[2] = {'x',};
		char	c[2] = {'c',};
		char	t2[2] = {'t',};
		str5[0] = h;
		str5[1] = k;
		str5[2] = x;
		str5[3] = c;
		str5[4] = t2;
		t_list	*ex17 = ft_list_push_strs(5, str5);
		
		printf("before : ");ft_list_foreach(ex14, &pt);
		printf("\n         + ");ft_list_foreach(ex17, &pt);
		ft_sorted_list_merge(&ex14, ex17, &ft_strcmp);
		printf("\n\n");
		printf("after : ");ft_list_foreach(ex14, &pt);
		printf("\n\n===============FIN===============\n\n");
		printf("TEST CASE CAN NOT CONTAIN EVERY EXCEPTION CASE.\n           YOU MUST NOT BELIEVE IT.\n");
		printf("\n=================================\n\n");
		free(str5);
		free(str4);
		t_list	*now2 = ex14;
		t_list	*temp;
		while (now2)
		{
			temp = now2-> next;
			free(now2);
			now2 = temp;
		}*/
	}
	return (0);
}
void	pt(void *str)
{
	printf("%s ", (char *)str);
}
int	ft_strcmp(void *s3, void *s4)
{
	unsigned int	i;
	int				result;
	char	*s1;
	char	*s2;
	s1 = s3;
	s2 = s4;
	i = 0;
	result = 0;
	while (*(s1 + i) != '\0' || *(s2 + i) != '\0')
	{
		if (*(s1 + i) != *(s2 + i))
		{
			result = *(s1 + i) - *(s2 + i);
			break ;
		}
		i ++;
	}
	return (result);
}
