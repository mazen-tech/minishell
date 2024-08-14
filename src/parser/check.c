#include "../../headers/minishell.h"

/*checking if the string contains '=' 

the logic behine this function 
if the string have '=' (key-value pair) the function then separate the ket and the value to compiare

if the string doesn't have '=' so it's simple string
*/
int check_the_arr(char **search, char *str)
{
    int j;

    if (check_equal(str))
    {
        j = 0;
        while (str[j] != '=')
        {
            j++;
        }
        return (check_the_equal_with_equal(search, str, j));
    }

    else
        return (check_the_equal_without_equal(search, str));
}


int check_the_equal_without_equal(char **search, char *str)
{
    int len;
    char *to_find;
    int r;

    len = 0;
    while (str[len])
        len++;
    to_find = add_equal(str);// append '='
    r = check_the_equal_with_equal(search, to_find, len);//check the newly formed string
    free(to_find);
    return (r);
}


int check_the_equal_with_equal(char **search, char *to_find, int len)
{
    int i;

    i = 0;
    while (search[i])
    {
        if (!ft_strncmp(search[i], to_find, len))
            return (i);//here we compairing the char of string 'search' with pointer char 'to_find'
        i++;
    }
    return (-1);
}

int check_equal(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[0] == '=')
            return (0);
        if (str[i] == '=')
            return (1);
        i++;
    }
    return (0);
}