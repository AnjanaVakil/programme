#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
// 25score
long long convert(string a,int radix)
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
long long find_radix(string b,long long target)
{
    //b(radix)-->10 == target
    //上下界的确定
    //下界low：b的最大数值位+1 f(15)+1=16进制
    char max_num=*max_element(b.begin(),b.end());
    long long low=(isdigit(max_num)?max_num-'0':max_num-'a'+10)+1;
    //上界：low和target的最大值 why?
    long long high=max(low,target);
    while(low<=high){
        long long mid=low+(high-low)/2;
        long long convert_res=convert(b,mid);
        if(convert_res==target){
            return mid;
        }else if(convert_res<0 || convert_res>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}
int main()
{
    string a,b;
    int tag,radix;
    cin >> a >> b >> tag >> radix;
    if(tag==2){
        swap(a,b);
    }
    //a:radix b:result_radix;
    long long result_radix;
    //a(radix)-->a(10)
    long long a_10=convert(a,radix);
    // cout << convert("1110",2) << endl;
    // cout << convert("ffff",16) << endl;
    result_radix=find_radix(b,a_10);
    if(result_radix!=-1){
        cout << result_radix;
    }else{
        cout << "Impossible";
    }
    return 0;
}