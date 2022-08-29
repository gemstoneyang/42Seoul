#ifndef MAIN_H
# define MAIN_H

typedef struct s_dict{
	int	key;
	char *value;
	struct s_dict *next;
} t_dict;

typedef struct s_digit_dict{
	int	digit;
	char *value;
	struct s_digit_dict *next;
} t_digit_dict;

#endif
