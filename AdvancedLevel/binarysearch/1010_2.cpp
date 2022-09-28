#include<iostream>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;
//n在radix下转为10进制
long long convert(string n,long long radix)
{
    // long long res=0;
    // int len=n.length();
    // for(int i=0;i<len;i++){
    //     int num=isdigit(n[i])? n[i]-'0':n[i]-'a'+10;
    //     // long long num=n[i]-'0';这种写法错误的，完全忽略了字母
    //     res+=(num*pow(radix,--len));
    // }
    // return res;
    long long res=0;
    int index=0,temp=0;
    for(auto it=n.rbegin();it!=n.rend();it++){
        temp=isdigit(*it)?*it-'0':*it-'a'+10;
        res+=temp*pow(radix,index++);
    }
    return res;
}
//找到令两个数值相等的进制数
long long find_radix(string n,long long num)
{
    char it=*max_element(n.begin(),n.end());
    long long left=(isdigit(it)?it-'0':it-'a'+10)+1;
    long long right=max(num,left);
    while(left<=right){
        long mid=left+(right-left)/2;
        long long temp=convert(n,mid);
        if(temp<0 || temp>num){
            right=mid-1;
        }else if(temp==num){
            return mid;
        }else{
            left=mid+1;
        }
        //这样写是错误的，只有15score
        // if(temp==num){
        //     return mid;
        // }else if(temp<num){
        //     //进制太小
        //     left=mid+1;
        // }else if(temp<0 || temp>num){
        //     right=mid-1;
        // }
    }
    return -1;
}
int main()
{
    string a,b;
    long long tag,radix,result_radix;
    cin >> a >> b >> tag >> radix;
    if(tag==2){
        swap(a,b);
    }
    result_radix=find_radix(b,convert(a,radix));
    if(result_radix!=-1){
        cout << result_radix;
    }else{
        cout << "Impossible";
    }
    return 0;
}