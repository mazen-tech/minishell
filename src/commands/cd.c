#include "../../headers/minishell.h"

/*The search_variables_in_env function searches for a variable
 in the global environment (g_env). It loops through the 
 environment variables, compares the beginning of each 
 variable with the search string s, and if a match is found, 
 returns a pointer to the value of that variable. 
 If no match is found, it returns NULL.*/

char *search_variables_in_env(t_attr *att, char *srt)
{
    int i;
    int s_size;
    char *path;//store the path found for the variable

    i = 0;
    s_size = (int)ft_strlen(srt);//length of the searched string
    while (att->g_env[i] != NULL)
    {
        if(!ft_strncmp(att->g_env[i], srt, s_size))
        {//we will compare the first s_size char of 
        //att->g_env with s
            path = att->g_env[i];
            path += s_size + 1;
            return (path);
        }
        i++;
    }
    return (NULL);
}

/*The cd_rm_add_path function updates both the global
 and export environments by removing a specified path 
 or variable if it exists, and then adding a new path 
 or variable*/

void cd_update_path(t_attr *att, char *to_remove, char *str)
{
    if (find_index(att->g_env, to_remove))
        refresh_rmenv(att, check_the_arr(att->g_env, to_remove));
    refresh_addenv(att, str);
    if (find_index(att->exp_env, to_remove))
        refresh_rmexp_env(att, check_the_arr(att->exp_env, to_remove));
    refresh_add_exp(att, str);
}


/*this function changes the current directory in a shell enviroment,
 handling "~" and "-" shortcuts and also error messages and 
 update enviroment*/


int cd(t_attr *att)
{
    char *destiny_path;
    char *current__path;

    destiny_path = att->tok_arr[1];//destiny_path is set to the second token from att->tok_arr 
    current__path = getcwd(NULL, 0);// current working directory
    if (att->nb_tokens > 2)
    {
        ft_putstr_fd("minishell: cd error: too many args\n", 1);
        free(current__path);
        return (1);
    }

    if(!destiny_path || !ft_strcmp(destiny_path, "~"))   //if destiny_path is NULL or '`', it is set to the value of the "home" enviroment
        destiny_path = search_variables_in_env(att, "HOME");
    else if(!ft_strcmp(att->tok_arr[1], "-"))//if the second token is "-", destiny_path is set to the previous directory using 'cd_previous_path'
        cd_previous_path(att, &destiny_path);
    if (!current__path || chdir(destiny_path))
    {
        printf(ERROR_CD, att->tok_arr[1]);
        free(current__path);
        return (1);
    }
    update_oldpwd(att, current__path);
    update_pwd(att);
    free(current__path);
    return (0);
}

/*this function sets the destination path to the previous working directory of the current directory
printing the new destination path accordengly*/

void cd_previous_path(t_attr *att, char **destiny_path)
{
    if (!att->first_flag)//if the find_flag in the structure att is not set
    {//(false or 0), it enters this condition 
        *destiny_path = search_variables_in_env(att, "PWD");
        att->first_flag = 1;
        printf("%s\n", *destiny_path);
    }

    else
    {
        *destiny_path = att->last_path;
        printf("%s\n", *destiny_path);
    }
}


