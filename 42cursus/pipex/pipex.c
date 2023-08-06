/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:04:48 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/05 17:02:04 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/ft_printf.h"

void    leak_check(void)
{
    system("leaks pipex");
    exit(0);
}

//프로세스가 실행되면 시스템으로부터 환경변수 정보를 받아서 이 정보를 바탕으로 실행을 한다.
int	main(int ac, char **av, char **env)
{
    atexit(leak_check);
    char **path;
	if (ac != 5)
	{
		ft_putstr_fd(strerror(EINVAL), 2);
		return (0);
	}
    int i = 0;
    while (env[i])
    {
        if (ft_strncmp("PATH", env[i], 4) == 0)
            path = ft_split(ft_strchr(env[i], '=') + 1, ':');
        i++;
    }
    i = 0;
    while (path[i])
    {
        char *command = ft_strjoin("/", av[2]);
        char *command_dir = ft_strjoin(path[i++], command);
        //https://www.it-note.kr/156 참고
        //정상적으로 실행되면 execv다음 로직은 실행할 수 없다? 다른 프로세스가 되었다는 말이 있음 -> 그래서 fork를 떠야하는건가?
        char *argv[] = {av[2],av[1], NULL};
        printf("command %s\n", command_dir);
        execve(command_dir, argv, NULL);
        perror("command failed");
        free(command);
        free(command_dir);
    }
    i = 0;
    while (path[i])
        free(path[i++]);
    free(path);
}
