//
// Created by 이상윤 on 2023/08/10.
//

#ifndef INC_42SEOUL_ARCHIVE_PIPEX_BONUS_H
#define INC_42SEOUL_ARCHIVE_PIPEX_BONUS_H

# include "./libft/libft.h"
# include <unistd.h>
/*access() unlink() close() read() write() pipe() dup() dup2() execve() fork()*/
# include <fcntl.h>
/* open() */
# include <stdio.h>
/* perror() */
# include <string.h>
/* strerror */
# include <sys/wait.h>
/* waitpid() wait() */
# include <stdlib.h>
/* malloc() free() exit() */
# include <errno.h>

typedef struct s_pipes
{
    int a[2];
    int b[2];
    int step;
    int cnt;
} t_pipes;

#endif //INC_42SEOUL_ARCHIVE_PIPEX_BONUS_H
