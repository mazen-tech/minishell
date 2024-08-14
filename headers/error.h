#ifndef ERROR_H
# define ERROR_H

# include "macros.h"

//errors messages 
# define ERROR_CD  "minishell: cd: %s: NO such file or directory \n"
# define ERROR_EXPORT "minishell: export: %s: not valid identifier\n"
# define ERROR_NLINE "minishell: syntax error near unexpected token 'newline'\n"
# define ERROR_simple_2 "minishell: parse error near '%c%c'\n"
# define ERROR_simple_1 "minishell: parse error near '%c'\n"
# define ERROR_PIPE2 "minishell: syntax error near unexpected token '||'\n"
# define ERROR_PIPE1 "minishell: syntax error near unexpected token '|'\n"
# define ERROR_TWO "minishell: syntax error near unexpected token '%c%c'\n"
# define ERROR_ONE "minishell: syntax error near unexpected toke '%c'\n"
# define ERROR_UNCLOSED "minishell: syntax error unclosed quotes\n"

//errors 1st
int error_last(char *str, char c);
int error_simple(char *str, char c);
int especialcase(char *str, int i);
int especialcase_two(char *str, int i);

//error 2nd
int error_pipes(char *str);
int error_simple_dirdoc(char *str, char c);
int error_single(char *str, char c);
int error_double(char *str, char c);
//int	error_mixed(char *str, char c, char r); //need modification

//error 3rd
int error_dirdoc(char *str);
int double_quote(char *str, char c);
int single_quote(char *str, char c);
int error_quotes(char *str);
int verify_readline(char *str);

//error 4th
int print_error_pipe(char *str, int i);
int error_onepipe(char *str);
int print_mixed_error(char *str, char r, int i);
int error_mixed(char *str, char c, char r);


#endif