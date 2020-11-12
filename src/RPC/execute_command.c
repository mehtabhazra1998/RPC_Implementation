#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 50

void func(int signum)
{
    wait(NULL);
}

int main()
{

    pid_t process_id;
    char cmd[MAX_CMD_LENGTH];

    while (1)
    {
        fgets(cmd, MAX_CMD_LENGTH, stdin);
        process_id = fork();

        if (process_id == -1)
        {

            printf("Can not fork!");
            exit(EXIT_FAILURE);
        }

        else if (process_id == 0)
        {
            // Child process
            system(cmd);
            exit(EXIT_SUCCESS);
        }
        else if (process_id > 0)
        {
            signal(SIGCHLD, func);
        }
        
    }
    
    
    return 0;
}