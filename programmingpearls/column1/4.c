#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start, stop;
double duration;
// bitmap sort
#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000
int a[1 + N / BITSPERWORD];
void set(int i)
{
    a[i >> SHIFT] |= (1 << (i & MASK));
}
void clr(int i)
{
    a[i >> SHIFT] &= ~(1 << (i & MASK));
}
int test(int i)
{
    return a[i >> SHIFT] & (1 << (i & MASK));
}
// system sort
int intcomp(int *x, int *y)
{
    return *x - *y;
}
int b[N];
int main(void)
{
    srand((int)time(NULL));
    // bitmap sort
    start = clock();
    int i;
    for (i = 0; i < N; i++)
        clr(i);
    for (int i = 0; i < N; i++)
    {
        int t=rand()%N;
        set(t);
    }
    for (i = 0; i < N; i++)
        test(i);
    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("bitmap sort: %lf\n", duration);

    // system sort
    start = clock();
    for (int i = 0; i < N; i++)
    {
        int t=rand()%N;
        b[i] = t;
    }
    qsort(b, N, sizeof(int), intcomp);
    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("system sort: %lf\n", duration);

    return 0;
}