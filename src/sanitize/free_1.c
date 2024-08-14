#include "../../headers/minishell.h"

void free_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void free_tokens(char **tokens, t_attr *att)
{
    int i;

    i = 0;
    while (i < att->nb_tokens)
        free(tokens[i++]);
    free(tokens);
}


void free_g_env(t_attr *att)
{
    int i;

    i = 0;
    while (att->g_env[i] != NULL)
    {
        free(att->g_env[i]);
        i++;
    }
    free(att->g_env);
}


/*free all the memory allocated for d_env member of 
the t_attr structure*/
void free_d_env(t_attr *att)
{
    int i;
    i = 0;
    while (att->d_env[i] != NULL)
    {
        free(att->d_env[i]);
        i++;
    }
    free(att->d_env);
}

/*function to iterate through exp_env and
 free each string array at t_attr*/
void free_exp_env(t_attr *att)
{
    int i;

    i = 0;
    while (att->exp_env[i] != NULL)
    {
        free(att->exp_env[i]);
        i++;
    }
    free(att->exp_env);
}