#include "../inc/pipex.h"
int main(int nargs, char **vargs, char **env)
{
	t_command *cmds = command_parser(nargs, vargs, "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Library/Frameworks/Mono.framework/Versions/Current/Commands", env);

	system("leaks a.out");
}
