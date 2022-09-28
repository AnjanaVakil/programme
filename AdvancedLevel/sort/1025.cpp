#include<iostream>
#include<algorithm>
using namespace std;
//13:22-55 16'
struct testee{
    string id;
    int location,score,local_rank;
};
bool cmp(testee a,testee b)
{
    if(a.score!=b.score) return a.score>b.score;
    else if(a.id!=b.id) return a.id<b.id;
}
int main()
{
    int n;
    cin >> n;
    testee t[30005];
    int temp=0;
    int j;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        for(j=temp;j<temp+k;j++){
            cin >> t[j].id >> t[j].score;
            t[j].location=i+1;
        }
        sort(t+temp,t+temp+k,cmp);
        t[temp].local_rank=1;
        int tag;
        for(j=temp+1,tag=1;j<temp+k;j++,tag++){
            t[j].local_rank=tag+1;
            if(t[j].score==t[j-1].score){
                t[j].local_rank=t[j-1].local_rank;
            }
        }
        temp=k;
    }
    cout << j << "\n";
    sort(t,t+j,cmp);
    int r=1;
    for(int i=0;i<j;i++){
        if(i>0 && t[i].score!=t[i-1].score){
            r=i+1;
        } 
        cout << t[i].id << " " << r << " " << t[i].location << " " << t[i].local_rank << "\n";
    }
    return 0;
}