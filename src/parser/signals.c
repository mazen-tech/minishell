#include "../../headers/minishell.h"

void	handle_interrupt(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	g_value = 130;
}
void	handler_exec(int sig)
{
	if (sig == SIGQUIT)
		write (1, "Quit (core dumped)", 18);
	write(1, "\n", 1);
}

void	set_signals(void)
{
	signal(SIGINT, handle_interrupt);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signals2(void)
{
	signal(SIGINT, handler_exec);
	signal(SIGQUIT, handler_exec);
}

void	heredoc_handler(int sig)
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