#include "../../headers/minishell.h"

void handle_interrupt(int sig)
{
    if (sig == SIGINT)
    {
        printf("\n");
        rl_replace_line("", 0);//rl_replace_line from GNU readline library to replace the current line with an empty string
        rl_on_new_line();//to make sure the readline is posotioned on the beginning of the newline
        rl_redisplay();//to refresh the readline display and uodate it to show the changes
    }
    g_value = 130;
}


/*handling the SIGQUIT signal */
void handler_exec(int sig)
{
    if (sig == SIGQUIT)
        write (1, "Quit (core dumped)", 18);
    write (1, "\n", 1);
}


/*sets up signal by associating 'SIGINT' with the 
'handle_interrupt' function and ignore 'SIGQUIT'

this allowes the program to handle interruptiono signals gracefully 
and ignore quit signal*/
void set_signals(void)
{
    signal(SIGINT, handle_interrupt);
    signal(SIGQUIT, SIG_IGN);
}

/*when ever signal 'SIGINT' or 'SIGQUIT' will be recieved 'handler_exec'
will be invoked to handle them*/
void set_signals2(void)
{
    signal(SIGINT, handler_exec);
    signal(SIGQUIT, handler_exec);
}


/*The heredoc_handler function handles SIGINT and 
SIGQUIT signals by deleting the .heredoc file and exiting 
with status codes 130 or 131. This ensures cleanup during signal 
interruptions.*/
void heredoc_handler(int sig)
{
    if (sig == SIGINT)
    {
        unlink(".heredoc");
        exit(130);
    }
    else if (sig == SIGQUIT)
    {
        unlink(".heredoc");
        exit(131);
    }
}