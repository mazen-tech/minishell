#include "../../headers/minishell.h"

/*prints am error message for a missing file or directory isong the 
string array att->tok_arr[i]*/
int  env_print_err(t_attr *att, int i)
{
    printf("env: '%s': NO SUCH FILE OR DIRECTORY\n", att->tok_arr[i]);
    return (127);
}

int env(t_attr *att)
{
    int i;

    i = 1;
    while(att->tok_arr[i])
    {
        if (!check_equal(att->tok_arr[i]))//we checking if the token string doesn't contain = sign
            return (env_print_err(att, i));
        i++;
    }
    i = 0;

    while (i < att->len_g_env)
    {
        //we here printing the current env variable untile the end 
        //of the len_g_env
        printf("%s\n", att->g_env[i]);
        i++;
    }
    i = 1;
    while (att->tok_arr[i])
    {
        if (check_equal(att->tok_arr[i]))
            printf("%s\n", att->tok_arr[i]);
            //print the current token from tok_arr followed by a newline
        i++;
    }
    return (0);
}