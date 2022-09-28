#include<iostream>
#include<algorithm>
using namespace std;
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
    int num=0;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            cin >> t[num].id >> t[num].score;
            t[num].location=i+1;
            num++;
        }
        //这个考场对应的数组下标为[num-k，num)
        sort(t+num-k,t+num,cmp);
        t[num-k].local_rank=1;
        for(int j=num-k+1;j<num;j++){
            t[j].local_rank=j+1-(num-k);
            if(t[j].score==t[j-1].score){
                t[j].local_rank=t[j-1].local_rank;
            }
        }
    }
    cout << num << "\n";
    sort(t,t+num,cmp);
    int r=1;
    for(int i=0;i<num;i++){
        if(i>0 && t[i].score!=t[i-1].score){
            r=i+1;
        } 
        cout << t[i].id << " " << r << " " << t[i].location << " " << t[i].local_rank << "\n";
    }
    return 0;
}