//
// Created by 이상윤 on 2023/08/10.
//

#include "pipex_bonus.h"

//void    leak_check(void)
//{
//    system("leaks pipex");
//    exit(0);
//}

void    print_error(char *error_msg)
{
    perror(error_msg);
    exit(1);
}

void    child_proc(t_pipes pipes, char **av, char **env)
{
    int fd;

    setbuf(stderr, 0);
    fprintf(stderr, "im a %d child process!!\n", pipes.step);
    if (pipes.step == 0)
    {
        fd = open(av[1], O_RDONLY);
        if (fd < 0)
            print_error("pipex: input file open error in first");
        if (dup2(fd, STDIN_FILENO) < 0)
            print_error("pipex: dup2 error stdin to input in first");
        close(fd);
        if (dup2(pipes.a[1], STDOUT_FILENO) < 0)
            print_error("pipex: dup2 error stdout to pipeA in first");
        close(pipes.a[0]);
        char *argv[] = {"ls", NULL};
        execve("/bin/ls", argv, env);
    }
    else if (pipes.step == pipes.cnt - 1) {
        fd = open(av[pipes.cnt + 2], O_RDWR | O_TRUNC | O_CREAT, 0644);
        if (fd < 0)
            print_error("pipex: output file open error in end");
        if (dup2(fd, STDOUT_FILENO) < 0)
            print_error("pipex: dup2 error stdout to pipeA in end");
        close(fd);
        if (!(pipes.step % 2))
        {
            if (dup2(pipes.b[0], STDIN_FILENO) < 0)
                print_error("pipex: dup2 error stdin to pipeB in end");
            close(pipes.b[1]);
        }
        else
        {
            if (dup2(pipes.a[0], STDIN_FILENO) < 0)
                print_error("pipex: dup2 error stdin to pipeA in end");
            close(pipes.a[1]);
        }
        char *argv[] = {"ls", NULL};
        execve("/bin/ls", argv, env);
    }
    else
    {
        if (!(pipes.step) % 2)
        {
            if (dup2(pipes.b[0], STDIN_FILENO) < 0)
                print_error("pipex: dup2 error stdin to pipeB in middle");
            close(pipes.b[1]);
            if (dup2(pipes.a[1], STDOUT_FILENO) < 0)
                print_error("pipex: dup2 error stdout to pipeA in middle");
            close(pipes.a[0]);
            char *argv[] = {"ls", NULL};
            execve("/bin/ls", argv, env);
        }
        else
        {
            if (dup2(pipes.a[0], STDIN_FILENO) < 0)
                print_error("pipex: dup2 error stdin to pipeA in middle");
            close(pipes.a[1]);
            if (dup2(pipes.b[1], STDOUT_FILENO) < 0)
                print_error("pipex: dup2 error stdout to pipeB in middle");
            close(pipes.b[0]);
            char *argv[] = {"ls", NULL};
            execve("/bin/ls", argv, env);
        }
    }
}

void    parent_proc(t_pipes pipes, pid_t pid)
{
    setbuf(stderr, 0);
    fprintf(stderr, "im a %d step parent process!!\n", pipes.step);
    if (pipes.step == 0)
    {
//        close(pipes.a[0]);
    }
    else if (pipes.step == pipes.cnt - 1)
    {
        if (!(pipes.step % 2))
            close(pipes.a[1]);
        else
            close(pipes.b[1]);
    }
    else
    {
        if (!(pipes.step % 2))
        {
//            close(pipes.a[0]);
//            close(pipes.a[1]);
//            close(pipes.b[0]);
            close(pipes.b[1]);
        }
        else
        {
//            close(pipes.a[0]);
            close(pipes.a[1]);
//            close(pipes.b[0]);
//            close(pipes.b[1]);
        }
    }
    waitpid(pid, 0, 0);
    setbuf(stderr, 0);
    fprintf(stderr, "%d parent process waiting!!\n", pipes.step);
}

int main(int ac, char **av, char **env)
{
//    atexit(leak_check);
    if (ac < 5)
        print_error("pipex: too many arguments");
    t_pipes pipes;
    pipes.step = -1;
    pipes.cnt = ac - 3;
    pid_t pid;
    while (++pipes.step < pipes.cnt)
    {
        if (!(pipes.step % 2) && pipe(pipes.a) < 0)
            print_error("pipex: pipeA error");
        if ((pipes.step % 2) && pipe(pipes.b) < 0)
            print_error("pipex: pipeB error");
        pid = fork();
        if (pid == -1)
            print_error("pipex: fork error");
        else if (!pid)
            child_proc(pipes, av, env);
        else
            parent_proc(pipes, pid);
    }
}
