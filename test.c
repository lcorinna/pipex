#include "pipex.h"

int	main(void)
{
	pid_t	pid;
	int		fd;
	char	*aa[2];

	aa[0] = "pwd";
	aa[1] = NULL; 
	pid = fork();
	if (pid == 0)
	{
		fd = open("334", O_CREAT | O_RDWR, 0644);
		dup2(fd, 1);
		execve("/bin/pwd", aa, NULL);
		exit(0);
	}
	else
		return (0);
}

fd = open("infile", O_RDONLY);
if (fd == -1)
	perror("Stop callin`\nStop callin`\nI don`t wanna think anymore\nI \
	left my head and my heart on the dancefloor");