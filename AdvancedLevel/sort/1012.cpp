#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;
//12:20-13:04 看了答案才写出来的
struct student{
    //student ID which is a string of 6 digits
    int id;
    int score[4],rank[4];
    int besttag;//0 1 2 3
};
int flag;
//用exist数组保存当前id是否存在，这个id对应的stu结构体的下标是多少。
int exist[1000000];
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
        stu[i].score[0]=(stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3.0+0.5;
    }
    for(flag=0;flag<=3;flag++){
        sort(stu.begin(),stu.end(),cmp);
        stu[0].rank[flag]=1;
        for(int i=1;i<N;i++){
            if(stu[i].score[flag]==stu[i-1].score[flag]){
                stu[i].rank[flag]=stu[i-1].rank[flag];
            }else{
                stu[i].rank[flag]=i+1;
            }
        }
    }
    for(int i=0;i<N;i++){
        //exist的值为stu[i].id对应的i
        exist[stu[i].id]=i+1;
        stu[i].besttag=0;
        int bestrank=stu[i].rank[0];
        for(int j=1;j<4;j++){
            if(stu[i].rank[j]<bestrank){
                bestrank=stu[i].rank[j];
                stu[i].besttag=j;
            }
        }
    }
    string s="ACME";
    int query;
    for(int i=0;i<M;i++){
        cin >> query;
        int j=exist[query];
        if(j!=0){
            int best=stu[j-1].besttag;
            cout << stu[j-1].rank[best] << " " << s[best] << "\n";
        }else{
            cout << "N/A\n";
        }
    }
    return 0;
}