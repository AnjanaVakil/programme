#include<iostream>
#include<algorithm>
using namespace std;
//计算m和n的最大公约数
int gcd(int m,int n)
{
    return n==0?m:gcd(n,m%n);
}
//现给定两个不相等的正分数
//要求你按从小到大的顺序列出它们之间分母为 K 的最简分数。
//因为要列出n1/m1和n2/m2之间的最简分数，但是n1/m1不一定小于n2/m2，
//所以如果n1 * m2 > n2 * m1，说明n1/m1比n2/m2大，则调换n1和n2、m1和m2的位置
int main()
{
    //得分：17
    int n1,m1,n2,m2,k;
    scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
    if(n1*m2>n2*m1){
        swap(n1,n2);
        swap(m1,m2);
    }
    int t=m1*m2/gcd(m1,m2);
    // cout << t << endl;
    n1=n1*(t/m1);
    n2=n2*(t/m2);
    // cout << n1 << " "  << n2 << endl;
    int flag=0;
    //题目中两个分数之间是指开区间而非闭区间。得分由13变17
    for(int i=n1+1;i<n2;i++){
        //分子i 分母t
        int m=t/k;
        if(i%m==0){
            if(gcd(i/m,k)==1){
                if(flag==1) cout << " ";
                cout << i/m << "/" << k;
            }
            flag=1;
        }
    }
    return 0;
}