#ifndef SANITIZE_H
#define SANITIZE_H

# include "minishell.h"

//free 1
void free_arr(char **arr);
void free_tokens(char **tokens, t_attr *att);
void free_g_env(t_attr *att);
void free_d_env(t_attr *att);
void free_exp_env(t_attr *att);

//free 2
void free_d_exp_env(t_attr *att);
void exit_free(t_attr *att);
void ft_delete_matrix(void *matrix);
void free_start_args(t_exec *args, t_attr *att);
void free_child(t_attr *att, t_exec *args);

#endif