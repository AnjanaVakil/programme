#include<iostream>
#include<algorithm>
using namespace std;
struct Fraction{
    long long up,down;
};
long long gcd(long long a,long long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
Fraction reduction(Fraction result)
{
    if(result.down<0){
        result.up=-result.up;
        result.down=-result.down;
    }
    if(result.up==0){
        result.down=1;
    }else{
        int d=gcd(abs(result.up),abs(result.down));
        result.up/=d;
        result.down/=d;
    }
    return result;
}
Fraction add(Fraction a,Fraction b)
{
    Fraction result;
    //两个int相乘会溢出，使用long long存储
    result.up=a.up*b.down+a.down*b.up;
    result.down=a.down*b.down;
    return reduction(result);
}
void showResult(Fraction f)
{
    f=reduction(f);
    if(f.down==1) printf("%lld",f.up);
    else if(abs(f.up)>f.down){ //注意这里是abs(f.up) f.down
        printf("%lld %lld/%lld",f.up/f.down,abs(f.up)%f.down,f.down);
    }else{
        printf("%lld/%lld",f.up,f.down);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    Fraction temp,sum;
    //sum的初始化 up分子为0，down分母为1
    sum.up=0,sum.down=1;
    for(int i=0;i<n;i++){
        scanf("%lld/%lld",&temp.up,&temp.down);
        sum=add(sum,temp);
    }
    showResult(sum);
    return 0;
}