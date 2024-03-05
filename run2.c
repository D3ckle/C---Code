#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char ** argv)
{
    pid_t child;
    int exitStatus;

    // at least, there should be 3 arguments
    // 2 for the first command, and the rest for the second command

    //The first executable is argv[1]
    //and it takes one, and only one, argument, which is in argv[2]. The second executable is argv[3], and the
    //rest of arguments, if any, are arguments to argv[3].

    //arg0 = this file call
    //arg1 = cmd1
    //arg2 = argv for cmd1
    //argv3 = cmd2, and any after is argv for cmd2 4 arguments minimum

    if (argc < 4) {
        fprintf(stderr, "Usage: %s cmd1 cmd1_arg cmd2 [cmd2_args ..]\n", argv[0]);
        return 1;
    }

    // TODO

    child = fork();
    
    perror("fork()");
    
    if (child == 0) // child process
    {

        //cmd1
        char *cmd1 = argv[1];
        
        execlp(cmd1, cmd1, argv[2], NULL);
        perror("execlp()");
        
        return -1;
        
    }
    waitpid(child, &exitStatus, 0);
    printf("exited=%d exitstatus=%d\n", WIFEXITED(exitStatus), WEXITSTATUS(exitStatus));
    

    child = fork();
    if (child == 0) // parent process
    {
        //cmd2
        char *cmd2 = argv[3];
        execvp(cmd2, &argv[3]);
        perror("execvp()"); // returns an int
        return -1;
    }
    waitpid(child, &exitStatus, 0);
    printf("exited=%d exitstatus=%d\n", WIFEXITED(exitStatus), WEXITSTATUS(exitStatus));
    return 0;
}