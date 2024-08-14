#include "../../headers/minishell.h"

/*defining functions to handle command parsing and 
state mangment for a shell program + checking sempols & flages 
sets flags based on command contect in 'commands_arr'*/


//checking symbol function 
int is_symbol(char *s)
{
    char *symbols[5];
    int i;

    symbols[0] = ">";
    symbols[1] = "<";
    symbols[2] = ">>";
    symbols[3] = "<<";
    symbols[4] = "|";
    if (s[0] == '\0')
        return (0);
    i = 0;
    while (i < 5)
    {
        if (!ft_strcmp(s, symbols[i]))
            return (1);
        i++;
    }
    return (0);
}


void reset_flags(t_attr *att)
{
    att->write_to_pipe = 0;//Indicates whether the current command's output should be written to a pipe
    att->redir = 0;//'>>' & '<<'
    att->read_from_pipe = 0;//Used when a command is receiving input from the output of a previous command in a pipeline.
    att->read_from_file = 0;//redirection of input from file rather than standard input
    att->heredoc = 0;//
    att->skip = 0;
    att->create_file = 0;
    att->only_create = 0;//This could be used to touch or create a 
    //file without writing anything to it, similar to 'touch' command
}

/*This function sets flags based on the previous command in commands_arr. It updates 
read_from_pipe or skip based on specific redirection or pipe symbols.*/
void next_step_sub2(t_attr *att)
{
    if (!ft_strcmp(att->commands_arr[att->i - 1], "|"))
        att->read_from_pipe = 1;
    if (!ft_strcmp(att->commands_arr[att->i - 1], ">>")
        || !ft_strcmp(att->commands_arr[att->i - 1], ">"))
        att->skip = 1;
    if (!ft_strcmp(att->commands_arr[att->i - 1], "<"))
        att->skip = 1;
    if (!ft_strcmp(att->commands_arr[att->i - 1], "<<"))
        att->skip = 1;
}

/*This function updates flags based on the next command in commands_arr. 
It sets write_to_pipe, redir, read_from_file,
or heredoc depending on the command's symbols and conditions.*/
void next_step_sub(t_attr *att)
{
    if (!ft_strcmp(att->commands_arr[att->i + 1], "|"))
        att->write_to_pipe = 1;
    else if (!ft_strcmp(att->commands_arr[att->i + 1], ">")
        || !ft_strcmp(att->commands_arr[att->i + 1], ">"))
        att->redir = 1;
    else if (!ft_strcmp(att->commands_arr[att->i + 1], "<"))
    {
        att->read_from_file = 1;
        if (!ft_strcmp(att->commands_arr[att->i + 3], "|"))
            att->write_to_pipe = 1;
    }
    else if (!ft_strcmp(att->commands_arr[att->i + 1], "<<"))
        att->heredoc = 1;
}

//here we are reseting flags and checking if the first command creates
//a file
int check_next_step(t_attr *att)
{
    reset_flags(att);
    if (!ft_strcmp(att->commands_arr[0], ">")
        || !ft_strcmp(att->commands_arr[0], ">>"))
    {
        att->only_create = 1;
        att->skip = 1;
    }
    else if (att->commands_arr[att->i] && att->commands_arr[att->i + 1])
        next_step_sub(att);
    if (att->i > 1)
        next_step_sub2(att);
    return (0);
}