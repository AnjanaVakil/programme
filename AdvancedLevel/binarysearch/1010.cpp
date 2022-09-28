#include<iostream>
#include<cmath>
using namespace std;
//17score
//n在radix下转为10进制
long long convert(string a,long long radix)
{
    //a:radix-->10
    int index=0;
    long long result=0;
    for(int i=a.length()-1;i>=0;i--){
        int num=isdigit(a[i])?a[i]-'0':a[i]-'a'+10;
        result+=(num*pow(radix,index++));
    }
    return result;
}
//找到令两个数值相等的进制数
long long find_radix(string n,long long num)
{
    long long left=2,right=36;
    while(left<=right){
        long mid=left+(right-left)/2;
        long long temp=convert(n,mid);
        if(temp==num){
            return mid;
        }else if(temp<num){
            //进制太小
            left=mid+1;
        }else if(temp>num || temp<0){
            right=mid-1;
        }
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
    // cout << convert("110",2);
    int result=find_radix(b,convert(a,radix));
    if(result!=-1){
        cout << result;
    }else{
        cout << "Impossible";
    }
    return 0;
}