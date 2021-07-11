#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int n = 1;
    if (argc > 1)
        n = strtol(argv[1], NULL, 10);

    for (int i = 0; i < n; i++) {
        fork();
        printf("-");
        // fflush(stdout);
        // printf("-\n");
        // printf("%d\t%d\n", getpid(), i);
    }

    fflush(stdout);
    return 0;
}
