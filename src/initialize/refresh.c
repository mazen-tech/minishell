#include "../../headers/minishell.h"

/*here we are reallocating the enviroment variable array to accommodate a new 
entry over the existing variables and cleaning up the old memory allocations*/
void refresh_addenv(t_attr *att, char *add)
{
    int i;

    i = 0;
    double_myenv(att);//doubling the capacity of an environment-related array
    free_g_env(att);//free the old memory
    att->g_env = malloc(sizeof(char *) * (att->len_g_env + 3));
    if (!att->g_env)
        return ;
    while (i < att->len_g_env)
    {//the loop eterates over each existing env-variable in d_env and duplicating them into the new allocated g_env
        att->g_env[i] = ft_strdup(att->d_env[i]);
        i++;
    }
    att->g_env[att->len_g_env] = ft_strdup(add);
    att->len_g_env++;
    att->g_env[att->len_g_env] = 0;
    free_d_env(att);
}

/*reallocating the exported enviroment variable array to accommodate the new 
entry variables*/
void refresh_add_exp(t_attr *att, char *add)
{
    int i;

    i = 0;
    double_exp_env(att);
    free_exp_env(att);
    att->exp_env = malloc(sizeof(char *) * (att->len_exp_env + 3));
    if (!att->exp_env)
        return ;
    while (i < att->len_exp_env)
    {
        att->exp_env[i] = ft_strdup(att->d_exp_env[i]);
        i++;
    }
    att->exp_env[att->len_exp_env] = ft_strdup(add);
    att->len_exp_env++;
    att->exp_env[att->len_exp_env] = 0;
    free_d_exp_env(att);
}

/*removes the env-variable at a specified index from the exported
environment array in t_attr*/
void refresh_rmexp_env(t_attr *att, int rm_index)
{
    int i;
    int j;

    i = 0;
    j = 0;
    double_exp_env(att);
    free_exp_env(att);
    att->exp_env = malloc(sizeof(char *) * att->len_exp_env);
    if (!att->exp_env)
        return ;
    while (j < att->len_exp_env)
    {
        if (i == rm_index)
            i++;
        if (!att->d_exp_env[i])
            break ;//exit the loop if the end of the original env array is reached
        att->exp_env[j] = ft_strdup(att->d_exp_env[i]);//copy the remaining variables into the new exp_env array
        i++;
        j++;
    }
    att->exp_env[j] = 0;
    att->len_exp_env--;
    free_d_exp_env(att);
}

/*operates the same as refresh_rmenv_env but targets the g_env array unlike
refresh_rmenv_env which targting the exp_env array*/
void refresh_rmenv(t_attr *att, int rm_index)
{
    int i;
    int j;

    i = 0;
    j = 0;
    double_myenv(att);
    free_g_env(att);
    att->g_env = malloc(sizeof(char *) * att->len_g_env);
    if (!att->g_env)
        return ;
    while (j < att->len_g_env)
    {
        if (i == rm_index)
            i++;
        if (!att->d_env[i])
            break ;
        att->g_env[j] = ft_strdup(att->d_env[i]);
        i++;
        j++;
    }
    att->g_env[j] = 0;
    att->len_g_env--;
    free_d_env(att);
}

/*printing the string and adding a quote '"' after the first '=' char
and closing quote at the end*/
void add_quotes(char *s)
{
    int i;
    int j;
    int flag;

    i = 0;
    j = 0;
    flag = 1;
    while (s[i])
    {
        if (s[i] == '=' && flag)
        {
            flag = 0;
            ft_putchar_fd(s[i], 1);
            ft_putchar_fd('"', 1);
        }
        else 
            ft_putchar_fd(s[i], 1);
        i++;
        j++;
    }
    ft_putchar_fd('"', 1);
}