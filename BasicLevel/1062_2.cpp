#include<iostream>
using namespace std;
//最大公约数
int gcd(int a,int b)
{
    return b==0?a:gcd(a,a%b);
}
//现给定两个不相等的正分数
//要求你按从小到大的顺序列出它们之间分母为 K 的最简分数。
//因为要列出n1/m1和n2/m2之间的最简分数，但是n1/m1不一定小于n2/m2，
//所以如果n1 * m2 > n2 * m1，说明n1/m1比n2/m2大，则调换n1和n2、m1和m2的位置
int main()
{
    int n1,m1,n2,m2,k;
    scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
    if(n1*m2>n2*m1){
        swap(n1,n2);
        swap(m1,m2);
    }
    //假设所求的分数分母为k、分子num，先令num=1
    int num=1;
    bool flag=false;
    while(n1*k>=m1*num) num++;
    while(n1*k<m1*num && m2*num<n2*k){
        //判断num和k是否有最大公约数，如果等于1表示没有最大公约数
        if(gcd(num,k)==1){
            printf("%s%d/%d",flag==true?" ":"",num,k);
            flag=true;
        }
        num++;
    }
    return 0;
}