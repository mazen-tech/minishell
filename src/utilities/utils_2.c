#include "../../headers/minishell.h"


int check_firsrchar(char *str)
{
    if (!str)
        return (0);
    if (str[0] != '\0')
    {
        if (str[0] >= '0' && str[0] <= '9')
            return (1);
        if (!(ft_isalpha(str[0])))
            return (0);
    }
    return (0);
}


int	check_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '=')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (check_firsrchar(str))
			return (0);
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}


char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}


char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}