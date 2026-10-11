#include <stdio.h>
#include <stdlib.h>

int sum_for(int n)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += i;
    return s;
}

unsigned sum_for_u(unsigned n)
{
    unsigned s = 0;
    for (unsigned i = 1; i <= n; i++)
        s += i;
    return s;
}

int sum_while(int n)
{
    int s = 0, i = 1;
    while (i <= n) {
        s += i;
        i++;
    }
    return s;
}

int sum_do(int n)
{
    int s = 0, i = 1;
    do {
        s += i;
        i++;
    } while (i <= n);
    return s;
}

int main(int argc, char *argv[])
{
    int n = argc > 1 ? atoi(argv[1]) : 5;
    printf("for:      %d\n", sum_for(n));
    printf("for (u):  %u\n", sum_for_u((unsigned)n));
    printf("while:    %d\n", sum_while(n));
    printf("do-while: %d\n", sum_do(n));
    return 0;
}
