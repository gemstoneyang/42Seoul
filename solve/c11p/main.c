#include "ex00/ft_foreach.c"
#include "ex01/ft_map.c"
#include "ex02/ft_any.c"/*
#include "ex03/ft_count_if.c"
#include "ex04/ft_is_sort.c"
#include "ex06/ft_sort_string_tab.c"
#include "ex07/ft_advanced_sort_string_tab.c"*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int	ft_strcmp2(char *s1, char *s2);
int		add(int	n);
void	ft_putnbr22(int nb);
int		fff(char *str);
int		comp(int n, int m);
int		main(void)
{
	{
		printf("\n===============EX00===============\n\n");
		printf("0123456789\n");
		int	tab[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		ft_foreach(tab, 10, &ft_putnbr22);
	}
	{
		printf("\n\n===============EX01===============\n\n");
		int	tab[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int	*result = ft_map(tab, 10, &add);
		printf("12345678910\n");
		for (int i = 0; i < 10; i ++)
			printf("%d", *(result + i));
	}
	{
		printf("\n\n===============EX02===============\n\n");
		char **tab;
		tab = (char **)malloc(sizeof(char *) * 5);
		for (int i = 0; i < 5; i ++)
			*(tab + i) = (char *)malloc(sizeof(char) * 4);
		*(*(tab)) = 'A';
		*(*(tab + 1)) = 'B';
		*(*(tab + 2)) = 'C';
		*(*(tab + 3)) = 'D';
		*(tab + 4) = 0;
		printf("0 : %d\n", ft_any(tab, &fff)); 
		*(*(tab + 2)) = 'c';
		printf("1 : %d\n", ft_any(tab, &fff));
	 }	/*
		printf("\n===============EX03===============\n\n");
		printf("1 : %d\n", ft_count_if(tab, 4, &fff));
		*(*(tab + 1)) = 'b';
		*(*(tab + 3)) = 'd';
		printf("3 : %d\n", ft_count_if(tab, 4, &fff));
		printf("\n===============EX04===============\n\n");
		int tab2[6] = {1, 2, 3, 4, 5, 6};
		printf("1 2 3 4 5 6\n");
		if (ft_is_sort(tab2, 6, &comp))
			printf("OK : OK\n\n");
		else
			printf("OK : KO\n\n");
		int tab3[6] = {1, 3, 2, 4, 6, 5};
		printf("1 3 2 4 6 5\n");
		if (ft_is_sort(tab3, 6, &comp))
			printf("KO : OK\n\n");
		else
			printf("KO : KO\n\n");
		printf("6 5 4 3 2 1\n");
		int tab4[6] = {6, 5, 4, 3, 2, 1};
		if (ft_is_sort(tab4, 6, &comp))
			printf("OK : OK\n");
		else
			printf("OK : KO\n");
		printf("\n===============EX06===============\n\n");
		*(*(tab + 2)) = 'C';	
		for (int i = 0; i < 4; i ++)
			printf("%c ", *(*(tab + i)));
		printf("\nvvvvvvv\n");
		ft_sort_string_tab(tab);
		for (int i = 0; i < 4; i ++)
			printf("%c ", *(*(tab + i)));
		printf("\n\n===============EX07===============\n\n");
		*(*(tab + 2)) = 'C';
		*(*(tab + 1)) = 'b';
		for (int i = 0; i < 4; i ++)
			printf("%c ", *(*(tab + i)));
		printf("\nvvvvvvv\n");
		ft_advanced_sort_string_tab(tab, &ft_strcmp2);
		for (int i = 0; i < 4; i ++)
			printf("%c ", *(*(tab + i)));
		for (int i = 0; i < 5; i ++)
			free(*(tab + i));
		free(tab);
		printf("\n\n===============FIN===============\n\n");
		printf("TEST CASE CAN NOT CONTAIN EVERY EXCEPTION CASE.\n           YOU MUST NOT BELIEVE IT.\n");
		printf("\n=================================\n\n");
	}*/
	return (0);
}
int	ft_strcmp2(char *s1, char *s2)
{
	unsigned int	i;
	int				result;
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
int	comp(int n, int m)
{
	return (n - m);
}
int	fff(char *str)
{
	if (*(str) > 95)
		return (1);
	else
		return (0);
}
int	add(int	n)
{
	return (n + 1);
}
void	intmin2(void)
{
	char	*ex;
	ex = "-2147483648";
	write(1, ex, 11);
}
void	ft_putnbr22(int nb)
{
	int		i;
	char	arr[10];
	if (nb == -2147483648)
		intmin2();
	else if (nb == 0)
		write(1, "0", 1);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		i = 0;
		while (nb > 0)
		{
			arr[i] = '0' + nb % 10;
			nb /= 10;
			i ++;
		}
		while (-- i >= 0)
			write(1, arr + i, 1);
	}
}
