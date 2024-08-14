#include "../../headers/minishell.h"

int count_tokens(char *s, t_attr *att)
{
    int len;
    int i;

    count_quotes(s, att);
    att->nb_tokens = 0;
    len = ft_strlen(s) - 1;
    i = 0;
    while (i <= len)
    {
        if (s[i] == '\'')//handles single quotes to manage enclosed test
            i = check_single_quotes(s, len, i, att);
        else if (s[i] == '"')//handles double quotes for text encapsulation
            i = check_double_quotes(s, len, i, att);
        else if (s[i] != ' ')//processes non-space charcters for token 
            i = check_non_space_char(s, len, i, att);
        else if (s[i] != ' ' && s[i] != '|' && s[i] != '<'
                && s[i] != '>')//checks for spacial char to manage specific token
                i = check_special_char(s, len, i, att);
        else if (s[i] == ' ')//skips spaces to find next relevant
            i++;
        else 
            i++;
    }
    return (att->nb_tokens);
}


int check_single_quotes(char *s, int len, int i, t_attr *att)
{
    int quotes;

    quotes = 0;
    att->nb_tokens++;
    /*checks if the next char is a single quote and the char after is 
    either a space or the end of the string if true returning i + 2 */
    if (s[i + 1] && s[i + 1] == '\''
            && ((s[i + 2] && s[i + 2] == ' ') || !s[i + 2]))
            return (i + 2);
    while (i <= len && quotes <= att->o_quotes)
    {
        if (s[i] == '\'')
            quotes++;
        /*if the number of quotes encountered so far is even and the 
        next char is a space so we will increament by 1 and return new value*/
        if (quotes % 2 == 0 && s[i + 1] && s[i + 1] == ' ')
        {
            i++;
            return (i);
        }
        i++;
    }
    return (i);
}


/*The check_double_quotes function processes double-quoted tokens 
in a string, updates the token count, handles specific double-quote patterns,
 and returns the new index after handling the double quotes correctly.*/
int check_double_quotes(char *s, int len, int i, t_attr *att)
{
    int quotes;

    quotes = 0;
    att->nb_tokens++;
    if (s[i + 1] && s[i + 1] == '"'
        && ((s[i + 2] && s[i + 2] == ' ') || !s[i + 2]))
        return (i + 2);
    while (i <= len && quotes <= att->o_dquotes)
    {
        if (s[i] == '"')
            quotes++;
        if (quotes % 2 == 0 && s[i + 1] && s[i + 1] == ' ')
        {
            i++;
            return (i);
        }
        i++;
    }
    return (i);
}


int check_non_space_char(char *s, int len, int i, t_attr *att)
{
    att->nb_tokens++;
    while (i <= len && s[i] != ' ')
        i++;
    return (++i);
}

int check_special_char(char *s, int len, int i, t_attr *att)
{
    att->nb_tokens++;
    while (i <= len && (s[i] != ' ' && s[i] != '|' && s[i] != '<'
                                        && s[i] != '>'))
                                            i++;
    return (++i);
}
