#include "libft/inc/libft.h"
int main(int nargs, char **vargs, char **env)
{
	while(*env)
	{
		ft_printf("%s\t\t\n", *env);
		env++;
	}
}
