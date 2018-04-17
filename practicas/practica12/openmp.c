#include <stdio.h>
#include <omp.h>

int main()
{
    int tid;
    int gid;
    #pragma omp parallel private(tid) shared(gid)
    {
        tid = omp_get_thread_num();
        gid = tid;
        printf("Hello World! %d %d\n", tid, gid);
    }
    return 0;
}
