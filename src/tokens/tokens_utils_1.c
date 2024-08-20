#include "../../headers/minishell.h"

void	count_quotes(char *s, t_attr *att)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
			att->o_dquotes++;
		else if (s[i] == '\'')
			att->o_quotes++;
		i++;
	}
}

int	process_next_token(t_attr *att, char *s, int len)
{
	if (count_if_pipe(att, &len, s))
		return (len);
	else if (count_if_redir(att, &len, s))
		return (len);
	else if (count_if_read(att, &len, s))
		return (len);
	else
		return (len - 1);
}

int	count_if_pipe(t_attr *att, int *len, char *s)
{
	if (s[*len] == '|' && s[*len - 1] != '|')
	{
		*len = *len - 1;
		att->pars_data.nb_tokenst++;
		return (1);
	}
	else if (s[*len] == '|' && s[*len - 1] == '|')
	{
		*len = *len - 2;
		att->pars_data.nb_tokenst++;
		return (1);
	}
	return (0);
}

int	count_if_redir(t_attr *att, int *len, char *s)
{
	if (s[*len] == '>' && s[*len - 1] != '>')
	{
		*len = *len - 1;
		att->pars_data.nb_tokenst++;
		return (1);
	}
	else if (s[*len] == '>' && s[*len - 1] == '>')
	{
		*len = *len - 2;
		att->pars_data.nb_tokenst++;
		return (1);
	}
	return (0);
}

int	count_if_read(t_attr *att, int *len, char *s)
{
	if (s[*len] == '<' && s[*len - 1] != '<')
	{
		*len = *len - 1;
		att->pars_data.nb_tokenst++;
		return (1);
	}
	else if (s[*len] == '<' && s[*len - 1] == '<')
	{
		*len = *len - 2;
		att->pars_data.nb_tokenst++;
		return (1);
	}
	return (0);
}