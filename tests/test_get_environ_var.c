#include "../inc/pipex.h"

int main(int nargs, char **vargs, char **env)
{
	ft_printf("%s\n", get_environ_val(env, "PATH"));
}
