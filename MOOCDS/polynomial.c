#include<stdio.h>
#include<time.h>
#include<math.h>
clock_t start,stop;
double duration;
#define MAXN 10
double f1(int n,double a[],double x);
double f2(int n,double a[],double x);
int main()
{
    double a[MAXN];
    for(int i=0;i<MAXN;i++) a[i]=(double)i;

    start=clock();
    f1(MAXN-1,a,1.1);
    stop=clock();
    duration=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("ticks1=%f\n",(double)(stop-start));
    printf("duration1=%6.2e\n",duration);

    start=clock();
    f2(MAXN-1,a,1.1);
    stop=clock();
    duration=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("ticks2=%f\n",(double)(stop-start));
    printf("duration2=%6.2e\n",duration);

    return 0;
}
//多项式在x处的值
double f1(int n,double a[],double x)
{
    // double sum=0;
    // for(int i=0;i<=n;i++){
    //     sum+=a[i]*pow(x,i);
    // }
    // return sum;
    double sum=a[0];
    for(int i=1;i<=n;i++){
        sum+=a[i]*pow(x,i);
    }
    return sum;
}
double f2(int n,double a[],double x)
{
    double sum=a[n];
    for(int i=n;i>0;i--){
        sum=a[i-1]+x*sum;
    }
    return sum;
}