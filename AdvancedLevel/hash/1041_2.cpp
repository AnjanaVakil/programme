#include<iostream>
using namespace std;
//Hash散列
int num[100000],cnt[100000];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        cnt[num[i]]++;
    }
    for(int i=0;i<n;i++){
        if(cnt[num[i]]==1){
            printf("%d",num[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}