#include "../inc/pipex.h"
int main()
{
	t_pipe	p;
	int		i;

	p.in = 0;
	p.out = 0;
	p.pipes = (int **) ft_calloc(3, sizeof(int*));
	i = 0;
	while (i < 2)
	{
		p.pipes[i] = (int *) ft_calloc(2, sizeof(int));
		pipe(p.pipes[i]);
		i++;
	}
	int pid = fork();
	if (pid)
	{
		char buff[200];
		wait(pid);
		read(p.pipes[0][0], buff, 14);
		write(1, buff, 14);
	}
	else
	{
		dup2(p.pipes[0][1], 1);
		close_pipes(p);
		ft_printf("It works!!\n");
		exit(0);
	}
}
