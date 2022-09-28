#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct student{
    int id,best;
    int score[4],rank[4];
};
int exist[1000000];
int flag=-1;
bool cmp(student a,student b)
{
    return a.score[flag]>b.score[flag];
}
int main()
{
    int N,M;
    cin >> N >> M;
    vector<student> stu(N);
    for(int i=0;i<N;i++){
        cin >> stu[i].id >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
        //平均分四舍五入
        stu[i].score[0]=(stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3.0+0.5;
    }
    for(flag=0;flag<=3;flag++){
        sort(stu.begin(),stu.end(),cmp);
        stu[0].rank[flag]=1;
        for(int i=1;i<N;i++){
            stu[i].rank[flag]=i+1;
            if(stu[i].score[flag]==stu[i-1].score[flag]){
                stu[i].rank[flag]=stu[i-1].rank[flag];
            }
        }
    }
    for(int i=0;i<N;i++){
        //用exist数组保存当前id是否存在，这个id对应的stu结构体的下标是多少。
        exist[stu[i].id]=i+1;
        stu[i].best=0;
        int minn=stu[i].rank[0];
        for(int j=1;j<=3;j++){
            if(stu[i].rank[j]<minn){
                minn=stu[i].rank[j];
                stu[i].best=j;
            }
        }
    }
    char c[5]={'A','C','M','E'};
    int query;
    for(int i=0;i<M;i++){
        cin >> query;
        int temp=exist[query];
        if(temp){
            int best=stu[temp-1].best;
            cout << stu[temp-1].rank[best] << " " << c[best] << "\n";
        }else{
            cout << "N/A\n";
        }
    }
    return 0;
}