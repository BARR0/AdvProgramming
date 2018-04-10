#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = fork();
    if (pid == 0)
    {
        printf("1\n");
        execl("/bin/echo", "echo", "test2", NULL);
    }
    else
    {
        printf("2\n");
    }
    return 0;
}
