#include "../../headers/minishell.h"

/*This function implements the echo command, processing options like -n, 
printing tokens with spaces between them, 
and conditionally adding a newline at the end.*/

int echo(t_attr att)
{
    int i;
    int fl_n;//-n flag
    int fl_pr;//for printing space

    i = 1;//to skip the command name
    fl_n = 0;
    fl_pr = 0;//to prevint printing space initially
    while(i <att.nb_tokens && att.tok_arr[i])
    {//starts a loop that iterates over the tokens in 'att.tok_Arr' starting from the second token
        if (handle_echo_options(att, &fl_n, &fl_pr, i))
        {
            i++;
            continue;
        }
        if(fl_pr)
            printf(" ");
        printf("%s", att.tok_arr[i]);
        fl_pr = 1;
        i++;
        att.already_dealt = 1;
    }
    if (fl_n == 0)
        printf("\n");
    return (0);
}


/*this function processes echo command option, settin flag for -n and $?
and calling echo_n when needed indicating if an option was handled 
successfully*/
int handle_echo_options(t_attr att, int *fl_n, int *fl_pr, int i)
{
   if (has_n(att.tok_arr[i], 'n') && att.already_dealt == 0)
   {
        *fl_n = 1;
        return (1);
   }

   else if (ft_strnstr(att.tok_arr[i], "-n", ft_strlen(att.tok_arr[i])) 
        && *fl_pr == 0)
    {
        echo_n(att);
        *fl_n = 1;
        return (1);
    }

    if (ft_strnstr(att.tok_arr[i], "$?", ft_strlen(att.tok_arr[i])))
    {
        printf("%d", g_value);
        return (1);
    }
    return (0);
}

/*this function checks if the second agrument att.tok_arr[i] is -n 
if not, it print it to standard output*/
int echo_n(t_attr att)
{
    int i;
    i = 1;
    if(ft_strcmp(att.tok_arr[i], "-n") != 0)
        ft_putstr_fd(att.tok_arr[i], 1);
    i++;
    return (0);
}

/*checks if a string starts with a '-' followed by one or more occurrences 
of charcter 'n' */
int has_n(char *str, char n)
{
    int i = 0;
    int len = (int)strlen(str);

    if(str[i] && str[i] == '-')
    {
        i++;
        while (i < len)
        {
            if(str[i] == n)
                while (i < len && str[i] == n)
                    i++;
            else    
                return (0);
            if (i == len)
                break;
            if (str[i] != n)
                return (0);
            i++;
        }
        return (1);
    }
    return (0);
}