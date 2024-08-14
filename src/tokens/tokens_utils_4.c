#include "../../headers/minishell.h"


void flag2up(char *s, t_attr *att, t_toki *tok)
{
    tok->flag = 2;
    att->o_dquotes--;//decrementing by 1 this likely indicates that a double quote has been processed

    while (s[tok->i])//looping until reaching the null terminaltor
    {
        if (s[tok->i] == 34)//34 is the double quotes in the ascii table
            tok->j++;
        if (s[tok->i + 1])//if the next char not = '\0'
        {
            if (s[tok->i + 1] == ' ' && tok->j % 2 == 0)//if next char is space and the j is even (even indecate that it's double quotes)
            {
                tok->i++;
                tok->pos = tok->i - tok->j;//sets 'pos' to the current index minus the number of double quotes encountered
                tok->token = quotentoken(s, att, tok);
                break ; 
            }
        }
        /*note the function 'quotentoken' -> genrates token based on the current state of 's' 'att' 'tok'*/
        else if (!s[tok->i + 1])//incase the next char is '\0'
        {
            tok->i++;
            tok->pos = tok->i - tok->j;
            tok->token = quotentoken(s, att, tok);
            break ;
        }
        tok->i++;//move to next
    }
}

//same af previuse function when it cimes to logis but dealing with single quotes
void flag1up(char *s, t_attr *att, t_toki *tok)
{
    tok->flag = 1;
    att->o_dquotes--;
    while(s[tok->i])
    {
        if (s[tok->i] == 39)//39 is single quote in ASCII
            tok->j++;
        if (s[tok->i + 1])
        {
            if (s[tok->i + 1] == ' ' && tok->j % 2 == 0)
            {
                tok->i++;
                tok->pos = tok->i - tok->j;
                tok->token = quotentoken(s, att, tok);
                break ;
            }
        }
        else if (!s[tok->i + 1])
        {
            tok->i++;
            tok->pos = tok->i - tok->j;
            tok->token = quotentoken(s, att, tok);
            break ;
        }
        tok->i++;
    }
}


char *process_multi_quote(char *s, t_attr *att, t_toki *tok)
{
    reinit_toki(tok);
    while (s[tok->i])
    {
        if (s[tok->i] == '"' && (tok->flag == 0 || tok->flag == 2))
        {
            flag2up(s, att, tok);
            return (tok->token);
        }

        else if (s[tok->i] == '\'' && (tok->flag == 0 || tok->flag == 1))
        {
            flag1up(s, att, tok);
            return (tok->token);
        }
        //handling the space char 
        else if (s[tok->i] == ' ' && tok->i % 2 == 0 && tok->j > 1)
        {
            tok->pos = tok->i - tok->j;
            tok->token = quotentoken(s, att, tok);
            return (tok->token);
        }
        tok->i++;
    }
    tok->pos = tok->i - tok->j;//calculating position
    tok->token = quotentoken(s, att, tok);//genrates a token based on the current state
    return (tok->token);
}

/*The process_single_quotes function processes the input string 
s within the context of single quotes.
 It builds a token by appending characters from s to tok->token*/
char *process_single_quotes(char *s, t_attr *att, t_toki *tok)
{
    int closed;

    closed = 0;
    while (tok->j < tok->pos && s[tok->i] != '\0')
    {
        if (s[tok->i] == 39)
            closed++;
        while (s[tok->i] != 39 && s[tok->i] != '\0')
        {
            if (closed >= 2 && s[tok->i] == ' ')//indecates that at least one pair of single quotes has been encountered
                return (tok->token);
            tok->token[tok->j] = s[tok->i];//append the char and increament both i and j
            tok->j++;
            tok->i++;
        }
        if (s[tok->i] == 34)//checking for the double quotes
            att->o_dquotes--;
        tok->i++;
    }
    return (tok->token);
}


char *process_double_quotes(char *s, t_attr *att, t_toki *tok)
{
    int closed;

    closed = 0;
    while (tok->j < tok->pos && s[tok->i] != '\0')
    {
        if (s[tok->i] == 34)
            closed++;
        while (s[tok->i] != 34 && s[tok->i] != '\0')
        {
            if (closed >= 2 && s[tok->i] != '\0')
                return (tok->token);
            tok->token[tok->j] = s[tok->i];
            tok->j++;
            tok->i++;
        }
        if (s[tok->i] == 39)
            att->o_dquotes--;
        tok->i++;
    }
    return (tok->token);
}