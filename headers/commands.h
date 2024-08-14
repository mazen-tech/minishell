#ifndef COMMANDS_H
# define COMMANDS_H

#include "minishell.h"

//cd
char *search_variables_in_env(t_attr *att, char *srt);
void cd_update_path(t_attr *att, char *to_remove, char *str);
int cd(t_attr *att);
void cd_previous_path(t_attr *att, char **destiny_path);

//echo
int echo(t_attr att);
int handle_echo_options(t_attr att, int *fl_n, int *fl_pr, int i);
int echo_n(t_attr att);
int has_n(char *str, char n);

//env
int  env_print_err(t_attr *att, int i);
int env(t_attr *att);

//exit
int exit_print_err(const char *arg);
int ft_exit_args(t_attr att);
void ft_exit(t_attr *att);

//export
int export_ft(t_attr *att);
void export_sort(t_attr att);
int export_print(t_attr att);
void export_check_equal(t_attr *att, int j);
void export_not_equal(t_attr *att, int j);

//pwd
int pwd(void);
void update_oldpwd(t_attr *att, const char *current_path);
void update_pwd(t_attr *att);

//unset
char *add_equal(char *str);
int find_index(char **search, char *str);
void double_myenv(t_attr *att);
void double_exp_env(t_attr *att);
int unset(t_attr *att);

#endif
