#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n = argc > 1 ? atoi(argv[1]) : 4;
    int power = 1;
    for (int i = 1;
         i <= n;
         i++) {
        power *= 2;
        printf("i = %d  2^i = %d\n", i, power);
    }
    printf("2^%d = %d\n", n, power);
    return 0;
}
