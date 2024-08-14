 #ifndef MACROS_H
# define MACROS_H

# include "../libft/libft.h"
# include <dirent.h>//Directory handling, file operations, directory streams
# include <errno.h>//Error codes, error handling, system errors
# include <limits.h>//limits of integral
# include <readline/history.h>/*check*/
# include <readline/readline.h>/*check*/
# include <signal.h>
# include <stdbool.h>//Boolean type
# include <stdio.h>
# include <stdlib.h>//malloc, calloc, free
# include <string.h>
# include <sys/types.h>//Data types, system-related types, process management
# include <sys/wait.h>//process status
# include <unistd.h>//POSIZ operating system API and system calls
# include <fcntl.h>

// colors
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define GREEN_BOLD "\033[1;32m"
# define RED_BOLD "\033[1;31m"
# define YELLOW_BOLD "\033[1;33m"
# define CYAN_BOLD "\033[1;36m"
# define RESET "\033[0m"
# define BLUE_BOLD "\033[1;34m"

// variables (maximum path size)
# define PATH_MAX 4096

// pipes , defining macros name read_end that represents value 0
//and write_end value 1, NOTE Macros are commanly used to make the code
//more readable
# define READ_END 0
# define WRITE_END 1

#endif