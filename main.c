#include "pipex.h"

void    first_cmd(char  **argv, int  pipefd[2], char **envp)
{
    int     in_file;

    in_file = open(argv[1], O_RDONLY);
    if (in_file == -1)
    {
        perror("File ERROR#1: ");
        exit(-1);
    }
    close(pipefd[0]);
    dup2(in_file, 0);
    dup2(pipefd[1], 1);
    close(in_file);
    close(pipefd[1]);
    exec_cmd(argv[2], envp);
}

void    second_cmd(char  **argv, int  pipefd[2], char **envp)
{
    int     out_file;
    out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
    if (out_file == -1)
    {
        perror("File ERROR#2: ");
        exit(-1);
    }
    close(pipefd[1]);
    dup2(out_file, 1);
    dup2(pipefd[0], 0);
    close(out_file);
    close(pipefd[0]);
    exec_cmd(argv[3], envp);
}

int     main(int argc, char **argv, char **envp)
{
    int     pipefd[2];
    pid_t   pid;
    
    if (argc != 5)
    {
        write (2, "Pipex Usage: ./pipex infile cmd1 cmd2 outfile\n", 46);
        return (0);
    }
    if (pipe(pipefd) == -1)
        exit(-1);
    pid = fork();
    if (pid == -1)
        exit(-1);
    if (!pid)
        first_cmd(argv, pipefd, envp);
    second_cmd(argv, pipefd, envp);
}