#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double avg=0.0,temp=0.0;
    int cnt=0;
    char a[50],b[50];
    for(int i=0;i<n;i++){
        cin >> a;
        //sscanf和sprintf在头文件cstdio中
        // sscanf 把字符数组中的内容以%d的格式写入n（从左往右）
        sscanf(a,"%lf",&temp);
        //sprintf 把n以%d的格式写到str字符数组中(从右往左)
        sprintf(b,"%.2f",temp);
        int flag=0;
        for(int j=0;j<strlen(a);j++){
            if(a[j]!=b[j]) flag=1;
        }
        if(flag || temp<(-1000) || temp>1000){
            cout << "ERROR: " << a << " is not a legal number\n";
        }else{
            cnt++;
            avg+=temp;
        }
    }
    if(cnt==1){
        printf("The average of %d number is %.2f",cnt,avg/cnt);
    }else if(cnt==0){
        printf("The average of 0 numbers is Undefined");
    }else{
        avg/=cnt;
        printf("The average of %d numbers is %.2f",cnt,avg);
    }
    return 0;
}