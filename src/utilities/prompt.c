#include "../../headers/minishell.h"

/*getting the pwd variables at the global env
and printing custom prompt*/

char *prompt(t_attr *att)
{
    char *str;
    char *user;
    char *pwd;

    user = custom_getenv("USER", att);
    pwd = custom_getenv("PWD", att);
    if (pwd != NULL && user != NULL)
    {
        printf("┏━" GREEN_BOLD " %s@:" GREEN_BOLD, user);
		printf(CYAN_BOLD "%s\n" CYAN_BOLD, pwd);
    }
    str = readline(RESET "┗━" RED_BOLD " minishell🐹" RED_BOLD " " RESET "");
	return (str);
}