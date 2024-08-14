#ifndef TOKENS_H
#define TOKENS_H

#include "minishell.h"

//count_tokens
int count_tokens(char *s, t_attr *att);
int check_single_quotes(char *s, int len, int i, t_attr *att);
int check_double_quotes(char *s, int len, int i, t_attr *att);
int check_non_space_char(char *s, int len, int i, t_attr *att);
int check_special_char(char *s, int len, int i, t_attr *att);


//get_token 1 /*redo*/
char	*get_token(char *s, t_attr *att, t_toki tok);
char	*quotentoken(char *s, t_attr *att, t_toki *tok);

//get_token 2 /*redo*/
int		count_tokens2(char *s, t_attr *att);
char	*get_token2(char *s, t_attr *att);
void	create_array2(char *s, t_attr *att);
char	**get_tokens2(char *str, t_attr *att);

//tokens_utils 1
void count_quotes(char *s, t_attr *att);
int process_next_token(t_attr *att, char *s, int len);
int count_if_pipe(t_attr *att, int *len, char *s);
int count_if_redir(t_attr *att, int *len, char *s);
int count_if_read(t_attr *att, int *len, char *s);

//token_utils 2
void	process_next_check(char *s, int j, t_attr *att, char **token);
int		check_if_pipe(char **token, int j, char *s);
int		check_if_redir(char **token, int j, char *s);
int		check_if_read(char **token, int j, char *s);
void	count_d_s_quotes(char *s, t_attr *att);


//token_utils 3
char *process_token_two(char *s, t_attr *att);
char *process_token_three(char *s, t_attr *att);
char *process_default(char *s, t_attr *att);
void reinit_toki(t_toki *tok);
char *process_special_char(char *s, t_attr *att);

//token_utils 4
void flag2up(char *s, t_attr *att, t_toki *tok);
void flag1up(char *s, t_attr *att, t_toki *tok);
char *process_multi_quote(char *s, t_attr *att, t_toki *tok);
char *process_single_quotes(char *s, t_attr *att, t_toki *tok);
char *process_double_quotes(char *s, t_attr *att, t_toki *tok);


//token
void create_array(char *s, t_attr *att, t_toki tok);
char **get_tokens(char *str, t_attr *att, t_toki tok);

#endif