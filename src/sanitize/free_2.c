#include "../../headers/minishell.h"


void free_d_exp_env(t_attr *att)
{
    int i;

    i = 0;
    while (att->d_exp_env[i] != NULL)
    {
        free(att->d_exp_env[i]);
        i++;
    }
    free(att->d_exp_env);
}


void exit_free(t_attr *att)
{
    free_tokens(att->tok_arr, att);
    free_g_env(att);
    free_exp_env(att);
    free_arr(att->commands_arr);
    ft_delete_matrix(att->pipesfd);
}

void ft_delete_matrix(void *matrix)
{
    int i;

    i = -1;
    while (((char **)matrix)[++i]) //(((char **)matrix)[++i]) accesses the ith element of matrix
        free(((char **)matrix)[i]);//which is cast to a char**
    free(matrix);
}

void free_start_args(t_exec *args, t_attr *att)
{
    int i;

    i = 0;
    if (att->has_path == 1)
    {
        while (args->all_paths[i] != NULL)
        {
            free(args->all_paths[i]);
            i++;
        }
        free(args->all_paths);
    }
}

/*The free_child function frees memory allocated for various 
components in the t_attr and t_exec structures, ensuring no 
memory leaks occur after execution.*/
void free_child(t_attr *att, t_exec *args)
{
    free_start_args(args, att);
    free_g_env(att);
    free_exp_env(att);
    free_arr(att->commands_arr);
    ft_delete_matrix(att->pipesfd);
    free_tokens(att->tok_arr, att);
}