#include <stdio.h>
int main()
{
    int n, a, b, c;
    scanf("%d", &n);
    int team[1001]={0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d-%d %d", &a, &b, &c);
        team[a]+=c;
    }
    int max=team[0];
    for(int i=0;i<1000;i++){
        if(team[i+1]>team[max]){
            max=i+1;
        }
    }
    printf("%d %d",max,team[max]);
}