#include<iostream>
#include<vector>
using namespace std;
//17:11-17:20 AC
vector<int> v(100005);
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> num(n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        v[num[i]]++;
    }
    int flag=0;
    for(int i=0;i<n;i++){
        if(v[num[i]]==1){
            printf("%d",num[i]);
            flag=1;
            break;
        }
    }
    if(flag==0) printf("None");
    return 0;
}