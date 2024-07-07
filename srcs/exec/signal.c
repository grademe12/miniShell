#include "../../include/minishell.h"

extern volatile sig_atomic_t	signal_num;

void	sigint_handler(int sig, t_data *data)
{
	int	i;

	i = 0;
	if (sig == SIGINT && data->pids)
	{
		while (data->pids[i])
		{	
			kill(data->pids[i], SIGKILL);
			i++;
		}
		ft_putstr_fd("^C", 2);
	}
	else if (sig == SIGINT && !(data->pids))
		return ;
}

void	sigeof_handler(int sig)
{
	if (sig == SIGTERM)
		signal_num = EOF;
}

void	sigquit_handler(int sig)
{
	sig = 0;
	return ;
}