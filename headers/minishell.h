#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>


# include "structs.h"
# include "macros.h"
# include "inicialize.h"
# include "tokens.h"
# include "parser.h"
# include "commands.h"
# include "executer.h"
# include "error.h"
# include "sanitize.h"
# include "utilities.h"


extern int g_value;

#endif
