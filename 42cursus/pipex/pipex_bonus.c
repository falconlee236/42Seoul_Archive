//
// Created by 이상윤 on 2023/08/10.
//

#include "pipex_bonus.h"

void    leak_check(void)
{
    system("leaks pipex");
    exit(0);
}

int main(int ac, char **av, char **env)
{
    atexit(leak_check);
    if (ac < 5)
    {
        perror("pipex: too many arguments");
        exit(1);
    }

    char **param = ft_split(av, ' ');
    int i = 0;

}

/*
 * 1. 파이프를 만든다
 * 2. 자식 1을 만든다.
 * 3. 자식 1에게 pipe write를 수행시킨다.
 * 4. 자식 1이 끝날때까지 기다린다.
 * 5. 파이프를 하나 더 만든다.
 * 6. 자식을 만든다.
 * 7. 자식1에게 받은 파이프를 입력으로 다시 한다.
 * 8. 자식이 파이프를 쓴다.
 * 9. 자식이 끝날때 까지 기다린다.
 * 즉 맨 처음하고 맨 마지막만 따로 처리하고 나머지 안에 있는 내용은 같은듯?
 */