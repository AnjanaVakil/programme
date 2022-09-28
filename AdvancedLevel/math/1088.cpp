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
Fraction minu(Fraction a,Fraction b)
{
    Fraction result;
    result.up=a.up*b.down-a.down*b.up;
    result.down=a.down*b.down;
    return reduction(result);
}
Fraction multi(Fraction a,Fraction b)
{
    Fraction result;
    result.up=a.up*b.up;
    result.down=a.down*b.down;
    return reduction(result);
}
Fraction divide(Fraction a,Fraction b)
{
    Fraction result;
    result.up=a.up*b.down;
    result.down=a.down*b.up;
    return reduction(result);
}
void showResult(Fraction f)
{
    f=reduction(f);
    if(f.up<0) printf("(");
    if(f.down==1) printf("%lld",f.up);
    else if(abs(f.up)>f.down){ //注意这里是abs(f.up) f.down
        printf("%lld %lld/%lld",f.up/f.down,abs(f.up)%f.down,f.down);
    }else{
        printf("%lld/%lld",f.up,f.down);
    }
    if(f.up<0) printf(")");
}
int main()
{
    Fraction a,b,res;
    scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
    showResult(a);
    printf(" + ");
    showResult(b);
    printf(" = ");
    res=add(a,b);
    showResult(res);
    printf("\n");

    showResult(a);
    printf(" - ");
    showResult(b);
    printf(" = ");
    res=minu(a,b);
    showResult(res);
    printf("\n");

    showResult(a);
    printf(" * ");
    showResult(b);
    printf(" = ");
    res=multi(a,b);
    showResult(res);
    printf("\n");

    showResult(a);
    printf(" / ");
    showResult(b);
    printf(" = ");
    res=divide(a,b);
    if(b.up==0){
        printf("Inf");
    }else{
        showResult(res);
    }
    printf("\n");
    return 0;
}