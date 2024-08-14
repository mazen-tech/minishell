#include "../../headers/minishell.h"

void create_array(char *s, t_attr *att, t_toki tok)
{
    int count;

    att->index = 0;
    att->beforet = malloc((att->nb_tokens + 1) * sizeof(char *));
    att->beforet[att->nb_tokens] = NULL;
    if (!att->beforet)//checking the memory allocation 
        return ;
    count = 0;
    while (count < att->nb_tokens)//the loop  runs until count reaches att->nb_tokens, to make sure all the token are prossesed 
    {
        while (*s == ' ')//skipping the space
            s++;
        att->beforet[count] = get_token(s, att, tok);
        if (att->beforet[count] == 0 && count < att->nb_tokens)
        {//if get_token returns 0 indicating an error or failure to get a token
            s = NULL;
            return ;
        }
        s += att->tok_arr_i;
        count++;
    }
}

/*
get_tokens processes a string into tokens by counting them, 
creating an array, and returning the tokens array stored in 
att->beforet.*/
char **get_tokens(char *str, t_attr *att, t_toki tok)
{
    if (!str)
        return (NULL);
    count_tokens(str, att);
    create_array(str, att, tok);
    return (att->beforet);
}