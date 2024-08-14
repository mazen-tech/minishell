#include "../../headers/minishell.h"

void see_flages_and_pipes(t_attr att)
{
    printf("------------------------------------\n");
    printf("nb of pipes: %d\n", att.number_of_pipes);
    printf("token: %s, index: %d\n", att.commands_arr[att.i], att.i);
    printf("read from pipe: %d\n", att.read_from_pipe);
    printf("write to pipe: %d\n", att.write_to_pipe);
    printf("redir: %d\n", att.redir);
    printf("raed from file: %d\n", att.read_from_file);
    printf("------------------------------------\n");
}


void ft_print_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
    {
        printf("%d -> %s\n", i, array[i]);
        i++;
    }
    printf("END\n\n");
}