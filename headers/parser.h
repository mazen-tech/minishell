#ifndef PARSER_H
#define PARSER_H

//check
int check_the_arr(char **search, char *str);
int check_the_equal_without_equal(char **search, char *str);
int check_the_equal_with_equal(char **search, char *to_find, int len);
int check_equal(char *str);

//expander
char *custom_getenv(const char *var_name, t_attr *att);
void init_var(t_exp *var);
void expand_tokens2(char **tokens, t_exp *info, int j);
char **expand_tokens(char **tokens, t_attr *att);
char	*correct_name(char *str);

//lexer
void command(t_attr *att, int index);

//parser
int is_symbol(char *s);
void reset_flags(t_attr *att);/*check*/
void next_step_sub2(t_attr *att);/*check*/
void next_step_sub(t_attr *att);/*check*/
int check_next_step(t_attr *att);

//signals
void handle_interrupt(int sig);
void handler_exec(int sig);
void set_signals(void);
void set_signals2(void);
void heredoc_handler(int sig);

#endif