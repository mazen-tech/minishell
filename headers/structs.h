#ifndef STRUCTS_H
# define STRUCTS_H

# include "macros.h"

/*manages parsed tokens and their count*/
typedef struct s_pars
{
	char	**pars_arr;//array of parsed tokens
	int		nb_tokenst;//number of tokens in 'pars_arr'
}			t_pars;

//struct to manage token parsing, env-variable and commmand execution
typedef struct s_attr
{
	int		i;
	char	**beforet; //array of string before token
	char	**aftert; //array of string after token
	int		o_dquotes; //count the opened double quotes
	int		o_quotes;  //count the opened single quotes
	int		tok_arr_i; //index for token array
	int		nb_tokens; //number of tokens
	int		pipeindex; //index of current pipe
	int		index; //genral index
	int		len_d_env;//length of the double quotes environment
	int		len_g_env;//length of the global enviroment
	char	**tok_arr;//array of tokens
	char	**g_env;//global enviroment variables
	char	*last_path;//last used path
	char	**d_env;//double quotes environment variables
	char	**exp_env;//expanded environment variable
	int		len_exp_env;// lenght of expanded environment variables
	char	**d_exp_env;//double quotes expanded environment variables
	int		len_d_exp_env;//lenght of double quotes expanded variables
	char	**commands_arr;// array of commands
	int		write_to_pipe;// file descriptor for pipe write
	int		read_from_pipe;//file descriptor for pipe read
	int		read_from_file;//file descriptpr for file read
	int		redir;// redirection type indicator
	int		create_file;//flag to create file
	int		only_create;//flag to create file only
	int		heredoc;//flag for heredoc usage
	int		skip;//skip processing flag
	int		inside_single_quotes;//flag for single quotes context
	int		number_of_pipes;//count of pipes
	int		number_of_redir;//count of redirections
	int		number_of_read;//count of read operations
	int		number_of_append;//count of append operations
	int		**pipesfd;//file descriptor for pipes
	int		redir_fd;//file descriptor for redirection
	int		first_flag;//flag for the first occurrence
	int		already_dealt;//flag if already processed
	int		has_path;//flag if a path exists
	t_pars	pars_data;
}			t_attr;

/*struct to handle command execution and path resolution and process 
managment*/
typedef struct s_exec
{
	int		i;//General purpose index
	int		nb_of_paths;//number of available paths
	char	*command;//command to be executed
	char	*path_srt;//shortest path for command
	char	**all_paths;//array of all possible paths
	char	**path_command;//array of paths for command execution
	char	curr_path[PATH_MAX];//current working dir
	int		ret;//return status of command
	pid_t	pid;//process ID for the command
}			t_exec;

/*manage variable expansion details and tokens*/
typedef struct s_exp
{
	char	*var_name;//name of the enviroment variable
	char	*value;//value of the enviroment variable
	size_t	expanded_length;//length of the expanded token
	size_t	token_length;//lenght of the original token
	char	*expanded_token;//expanded form of the token
	int		j;//general purpose index for loops
	int		i;//also like j
	int		has_quote;//flag indicating if quotes are present
}			t_exp;

/*handles individual token with flags and positional information*/
typedef struct s_toki
{
	char	*token;//token string 
	int		flag;//flags associated with the token
	int		pos;//position of the token in input
	int		j;//j and i are both index or counter of the the used strings
	int		i;
}			t_toki;

#endif