#include "inc/pipex.h"

int main(int nargs, char **vargs, char **env)
{

	int fd = open("lul.txt", O_RDONLY);
	char c[12];	
	perror(strerror(errno));
	ft_printf("%i", errno);
}
