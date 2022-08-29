#include <stdio.h>
#include <string.h>

#include "ex00/ft_strcpy.c"
#include "ex01/ft_strncpy.c"
#include "ex02/ft_str_is_alpha.c"
#include "ex03/ft_str_is_numeric.c"
#include "ex04/ft_str_is_lowercase.c"
#include "ex05/ft_str_is_uppercase.c"
#include "ex06/ft_str_is_printable.c"
#include "ex07/ft_strupcase.c"
#include "ex08/ft_strlowcase.c"
#include "ex09/ft_strcapitalize.c"
#include "ex10/ft_strlcpy.c"
#include "ex11/ft_putstr_non_printable.c"
#include "ex12/ft_print_memory.c"

void	is_equal_string(char *input, char *expect)
{
	if (strcmp(input, expect) == 0)
		printf("OK!!\n");
	else
		printf("ERROR :(\n");
	printf("function result : %s\n", input);
	printf("expect   result : %s\n\n", expect);
}

void	is_equal_integer(int input, int expect)
{
	if (input == expect)
		printf("OK!!\n");
	else
		printf("ERROR :(\n");
	printf("function result : %d\n", input);
	printf("expect   result : %d\n\n", expect);
}

int main(void)
{

	printf("-----Exercise 00-----\n");
	char ex00_origin[] = "Seoul42";
	char ex00_test1[20];
	char ex00_test2[] = "STRCPY_EXAMPLE";

	is_equal_string(ft_strcpy(ex00_test1, ex00_origin), "Seoul42");
	is_equal_string(ft_strcpy(ex00_test2, ex00_origin), "Seoul42");


	printf("-----Exercise 01-----\n");
	char ex01_origin[] = "Seoul42";
	char ex01_test1[20];
	char ex01_test2[] = "abcdefghijklmnop";
	char ex01_test3[] = "STRNCPY_EXAMPLE";
	
	char *result1 = ft_strncpy(ex01_test1, ex01_origin, sizeof(ex01_origin));
	is_equal_string(result1, "Seoul42");
	char *result2 = ft_strncpy(ex01_test2, ex01_origin, sizeof(ex01_origin));
	is_equal_string(result2, "Seoul42");
	char *result3 = ft_strncpy(ex01_test3, ex01_origin, 5);
	is_equal_string(result3, "SeoulPY_EXAMPLE");


	printf("-----Exercise 02-----\n");
	char ex02_test1[] = "helloworld";
	char ex02_test2[] = "hello_world";
	char ex02_test3[] = "";

	is_equal_integer(ft_str_is_alpha(ex02_test1), 1);
	is_equal_integer(ft_str_is_alpha(ex02_test2), 0);
	is_equal_integer(ft_str_is_alpha(ex02_test3), 1);


	printf("-----Exercise 03-----\n");
	char ex03_test1[] = "12345";
	char ex03_test2[] = "123a";
	char ex03_test3[] = "";

	is_equal_integer(ft_str_is_numeric(ex03_test1), 1);
	is_equal_integer(ft_str_is_numeric(ex03_test2), 0);
	is_equal_integer(ft_str_is_numeric(ex03_test3), 1);


	printf("-----Exercise 04-----\n");
	char ex04_test1[] = "abcde";
	char ex04_test2[] = "abcdE";
	char ex04_test3[] = "";

	is_equal_integer(ft_str_is_lowercase(ex04_test1), 1);
	is_equal_integer(ft_str_is_lowercase(ex04_test2), 0);
	is_equal_integer(ft_str_is_lowercase(ex04_test3), 1);


	printf("-----Exercise 05-----\n");
	char ex05_test1[] = "ABCDE";
	char ex05_test2[] = "abcdE";
	char ex05_test3[] = "";

	is_equal_integer(ft_str_is_uppercase(ex05_test1), 1);
	is_equal_integer(ft_str_is_uppercase(ex05_test2), 0);
	is_equal_integer(ft_str_is_uppercase(ex05_test3), 1);


	printf("-----Exercise 06-----\n");
	char ex06_test1[] = " !~}*";
	char ex06_test2[] = "\n\n\t\t\t";
	char ex06_test3[] = "";

	is_equal_integer(ft_str_is_printable(ex06_test1), 1);
	is_equal_integer(ft_str_is_printable(ex06_test2), 0);
	is_equal_integer(ft_str_is_printable(ex06_test3), 1);


	printf("-----Exercise 07-----\n");
	char ex07_test1[] = "abcde";
	char ex07_test2[] = "ABcDe";
	char ex07_test3[] = "12!aB";

	is_equal_string(ft_strupcase(ex07_test1), "ABCDE");
	is_equal_string(ft_strupcase(ex07_test2), "ABCDE");
	is_equal_string(ft_strupcase(ex07_test3), "12!AB");


	printf("-----Exercise 08-----\n");
	char ex08_test1[] = "ABCDE";
	char ex08_test2[] = "ABcDe";
	char ex08_test3[] = "12!Ab";

	is_equal_string(ft_strlowcase(ex08_test1), "abcde");
	is_equal_string(ft_strlowcase(ex08_test2), "abcde");
	is_equal_string(ft_strlowcase(ex08_test3), "12!ab");


	printf("-----Exercise 09-----\n");
	char ex09_str1[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char ex09_str2[] = "abc, def Gh iJk : abcd deEf";

	is_equal_string(ft_strcapitalize(ex09_str1), "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un");
	is_equal_string(ft_strcapitalize(ex09_str2), "Abc, Def Gh Ijk : Abcd Deef");


	printf("-----Exercise 10-----\n");
	char src1[30] = "HEllO hi 123";
	char dest1[30] = "asdfasdfasdf";
	char dest2[30] = "asdfasdfasdf";

	printf("%lu\n", strlcpy(dest1, src1, 5));
	printf("%u\n\n", ft_strlcpy(dest2, src1, 5));
	printf("%s %s\n\n", dest1, dest2);


	printf("-----Exercise 11-----\n");
	char str[12] = "abcdef \t? ";
	char str1[30] = "Coucou\ntu vas bien ?";
	
	ft_putstr_non_printable(str);
	printf("\n");
	ft_putstr_non_printable(str1);
	printf("\n\n");	

	printf("-----Exercise 12-----\n");
	char ex12_str[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n";
	ft_print_memory(ex12_str, 92);

