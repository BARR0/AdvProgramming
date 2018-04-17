#include <stdio.h>
#include <pthread.h>

void *helloThread(void *arg)
{
    long id = (long)arg;
    printf("Hello world: %ld\n", id);
    return NULL;
}

int main()
{
    pthread_t threads[20];
    for (int i = 0; i < 20; ++i)
    {
        pthread_create(
            &threads[i],
            NULL,
            helloThread,
            (void *) i
        );
    }
    for (int i = 0; i < 20; ++i)
    {
        pthread_join(
            &threads[i],
            NULL
        );
    }

    return 0;
}
