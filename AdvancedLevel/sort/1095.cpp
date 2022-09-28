#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int id;
    vector<int> score;
    int rank,per,sum;
    bool isshow=false;
};
bool cmp(node a,node b)
{
    if(a.sum!=b.sum) return a.sum>b.sum;
    else if(a.per!=b.per) return a.per>b.per;
    else return a.id<b.id;
}
int main()
{
    int n,k,m;
    cin >> n >> k >> m;
    int full[10];
    vector<node> v(n+1);
    for(int i=1;i<=n;i++){
        v[i].score.resize(k+1,-1);
    }
    for(int i=1;i<=k;i++){
        cin >> full[i];
    }
    int id,pid,score;
    for(int i=0;i<m;i++){
        cin >> id >> pid >> score;
        v[id].id=id;
        v[id].score[pid]=max(score,v[id].score[pid]);
        if(score!=-1){
            v[id].isshow=true;
        }else if(v[id].score[pid]==-1){
            //-1 未通过编译器编译
            v[id].score[pid]=-2;
        }
    }
    //the user id's are 5-digit numbers from 00001 to N
    //题目信息很关键
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(v[i].score[j]!=-1 && v[i].score[j]!=-2){
                v[i].sum+=v[i].score[j];
            }
            if(v[i].score[j]==full[j]){
                v[i].per++;
            }
        }
    }
    sort(v.begin()+1,v.end(),cmp);
    for(int i=1;i<=n;i++){
        v[i].rank=i;
        if(i!=1 && v[i].sum==v[i-1].sum){
            v[i].rank=v[i-1].rank;
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i].isshow==true){
            printf("%d %05d %d",v[i].rank,v[i].id,v[i].sum);
            for(int j=1;j<=k;j++){
                if(v[i].score[j]!=-1 && v[i].score[j]!=-2){
                    printf(" %d",v[i].score[j]);
                }else if(v[i].score[j]==-1){
                    printf(" -");
                }else{
                    printf(" 0");
                }
            }
            printf("\n");
        }
    }
    return 0;
}