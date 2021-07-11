#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t f(uint64_t n)
{
    if (n == 1)
        return 1;

    uint64_t ret = n;
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

    uint64_t sum = n;
    uint64_t k;
    for (k = 1; k <= n; k++) {
        sum += f(k);
    }
    printf("%llu\n", sum);
}
