#include "../../headers/minishell.h"

/*this file is containing function to initialize command execution and 
env-variables*/



/*start_args prepares command paths*/
int start_args(t_exec *args, t_attr *att)
{
    args->i = 0;//set to 0 initializing the loop indec
    args->command = att->tok_arr[0];//assigned to the first token which represent the command
    args->path_srt = get_str_paths(att, args->path_srt);
    if (args->path_srt == NULL)
        return (-1);
    args->path_srt += 5;//increament by 5 to skip PATH=
    args->nb_of_paths = count_paths(args->path_srt);//counting the number of paths in args->path_srt
    args->all_paths = ft_split(args->path_srt, ':');
    args->path_command = NULL;//and then set path_command to NULL to prepare to find the command path
    return (0);
}


/*start_env prepares att->g_env for use within the shell, providing a 
local copy of the env variables that the shell can manipulate independently*/
void start_env(char **envp, t_attr *att)
{
    int i;
    i = 0;
    att->len_g_env = 0;

    while (envp[att->len_g_env])
        att->len_g_env++;
    att->g_env = malloc(sizeof(char *) * (att->len_g_env + 2));
    if (!att->g_env)
        return ;
    while (i < att->len_g_env)
    {
        att->g_env[i] = ft_strdup(envp[i]);
        i++;
    }
    att->g_env[i] = 0;
}

/*initializes the att->exp_env with a copy of environment variables 
from envp*/
void start_exp(char **envp, t_attr *att)
{
    int j;

    j = 0;
    att->len_exp_env = 0;
    while (envp[att->len_exp_env])
        att->len_exp_env++;
    att->exp_env = malloc(sizeof(char *) * (att->len_g_env + 1));
        return ;
    while (j < att->len_exp_env)
    {
        att->exp_env[j] = ft_strdup(envp[j]);
        j++;
    }
    att->exp_env[j] = 0;
}