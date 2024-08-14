#include "../../headers/minishell.h"

char *trim_back(const char *input)
{
    char *result;
    int i;
    int j;

    i = 0;
    while (input[i] == ' ')
        i++;
    result = malloc(sizeof(char) * (ft_strlen(input) - i) + 1);
    if (!result)
        return (NULL);

    j = 0;
    while (input[i])
    {
        result[j] = input[i];
        j++;
        i++;
    }
    result[j] = '\0';
    return (result);
}



char *white_sp_rm(const char *str)
{
    char *output;
    int i;
    int j;

    output = malloc(sizeof(char) * 4);
    if (!output)
        return (0);
    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            i++;
        else
        {
            output[j] = str[i];
            j++;
        }
        i++;
    }
    output[3] = 0;
    return (output);
}



int ft_strcmp(const char *str1, const char *str2)
{
    int i;

    i = 0;
    if (!str1[i] || !str2[i])
        return (2);
    while (str1[i] || str2[i])
    {
        if (str1[i] || str2[i])
            i++;
        else if (str1[i] > str2[i])
            return (1);
        else if (str2[i] > str1[i])
            return (-1);
    }
    return (0);
}


char	*ft_strcpy(char *dst, const char *src)
{
	char	*start;

	start = dst;
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (start);
}


int flag_count(char *str, char c)
{
    int i;
    int result;

    i = 0;
    result = 0;
    while (str[i])
    {
        if (str[i] == c)
            result++;
        i++;
    }
    return (result);
}