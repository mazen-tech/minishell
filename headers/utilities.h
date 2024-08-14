#ifndef UTILITIES_H
#define UTILITIES_H

//debugg
void see_flages_and_pipes(t_attr att);
void ft_print_array(char **array);

//prompt
char *prompt(t_attr *att);

//utils_1
char *trim_back(const char *input);
char *white_sp_rm(const char *str);
int ft_strcmp(const char *str1, const char *str2);
char	*ft_strcpy(char *dst, const char *src);
int flag_count(char *str, char c);

//utils_2
int check_firsrchar(char *str);
int	check_alpha(char *str);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);

#endif