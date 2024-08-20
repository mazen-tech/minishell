#include "../../headers/minishell.h"
/*The command function processes and executes a shell command
 in att->tok_arr[0]. It handles specific built-in commands like cd,
 unset, exit, and export. If none match, it runs an external command.*/

/*void command(t_attr *att, int index)
{
    if (att->inside_single_quotes == 0)
        expand_tokens(&att->tok_arr[0], att);
    if (!att->tok_arr[0])
        return ;
    else if (ft_strcmp(att->tok_arr[0], "cd") == 0)
        g_value = cd(att);
    else if (ft_strcmp(att->tok_arr[0], "unset") == 0)
        g_value = unset(att);
    else if((ft_strcmp(att->tok_arr[0], "exit") == 0))
        return (ft_exit(att));
    else if (ft_strcmp(att->tok_arr[0], "export") == 0 && att->tok_arr[1])
        g_value = export_ft(att);
    else    
        execute(att, index);
}*/


void	command(t_attr *att, int index)
{
	if (att->inside_single_quotes == 0)
		expand_tokens(&att->tok_arr[0], att);
	if (!att->tok_arr[0])
		return ;
	else if (ft_strcmp(att->tok_arr[0], "cd") == 0)
		g_value = cd(att);
	else if (ft_strcmp(att->tok_arr[0], "unset") == 0)
		g_value = unset(att);
	else if ((ft_strcmp(att->tok_arr[0], "exit") == 0))
		return (ft_exit(att));
	else if (ft_strcmp(att->tok_arr[0], "export") == 0 && att->tok_arr[1])
		g_value = export_ft(att);
	else
		execute(att, index);
}