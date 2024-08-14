#ifndef INICIALIZE_H
#define INICIALIZE_H

# include "minishell.h"

//init.c
void init_parmas(int ac, char **av, t_attr *att, char **envp);
void init_attributes_one(t_attr *att);
void init_attributes_two(t_attr *att);
void init_toki(t_toki *tok);
void reinit_att(t_attr *att);


//refresh.c
void refresh_addenv(t_attr *att, char *add);
void refresh_add_exp(t_attr *att, char *add);
void refresh_rmexp_env(t_attr *att, int rm_index);
void refresh_rmenv(t_attr *att, int rm_index);
void add_quotes(char *s);


//start.c
int start_args(t_exec *args, t_attr *att);
void start_env(char **envp, t_attr *att);
void start_exp(char **envp, t_attr *att);

#endif