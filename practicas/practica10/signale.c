#include <stdio.h>
#include <signal.h>

void receiveSignal(int sig)
{
    printf("Received: %d\n", sig);
}

int main()
{
    signal(SIGUSR1, receiveSignal);
    while(1);
    return 0;
}
