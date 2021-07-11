#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t f(uint64_t n)
{
    uint64_t ret = 2;
    uint64_t k;
    for (k = 1; k < n; k++) {
        ret += f(k);
    }
    return ret;
}

int main(int argc, char *argv[])
{
    uint64_t n = 1;
    if (argc > 1) {
        n = strtoull(argv[1], NULL, 10);
    }

    uint64_t nr_nodes = 2;
    uint64_t k;
    for (k = 1; k < n; k++) {
        nr_nodes += f(k);
    }
    printf("%llu\n", nr_nodes);
    printf("%llu\n", nr_nodes * n);
}
