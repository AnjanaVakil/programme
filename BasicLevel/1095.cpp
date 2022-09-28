#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
#define maxn 10000+5
struct student{
    string s;
    int score;
};
int N,M,n;
string str;
student stu[maxn];
bool cmp(student a,student b)
{
    //分数非升序
    //对于分数并列的考生，按其准考证号的字典序递增输出（题目保证无重复准考证号）
    //若人数并列则按考场编号递增顺序输出。
    return a.score!=b.score ? a.score>b.score : a.s<b.s;
}
void print1()
{
    vector<student> v;
    for(int i=0;i<N;i++){
        if(stu[i].s[0]==str[0]){
            v.push_back(stu[i]);
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        cout << v[i].s << " " << v[i].score << "\n";
    }
    if(v.size()==0) cout << "NA\n";
}
void print2()
{
    int cnt=0,sum=0;
    for(int i=0;i<N;i++){
        string place=stu[i].s.substr(1,3);
        if(place==str){
            cnt+=1;
            sum+=stu[i].score;
        }
    }
    if(cnt==0){
        cout << "NA\n"; 
    }else{
        cout << cnt << " " << sum << "\n";
    }
}
void print3()
{
    unordered_map<string,int> m;
    vector<student> v;
    for(int i=0;i<N;i++){
        string time=stu[i].s.substr(4,6);
        if(time==str){
            string place=stu[i].s.substr(1,3);
            m[place]++; 
        }
    }
    for(auto it:m){
        v.push_back({it.first,it.second});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        printf("%s %d\n",v[i].s.c_str(),v[i].score);
    }
    if(v.size()==0) printf("NA\n");
}
int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> stu[i].s >> stu[i].score;
    }
    for(int i=0;i<M;i++){
        cin >> n >> str;
        printf("Case %d: %d %s\n",i+1,n,str.c_str());
        switch(n){
            case 1:print1();break;
            case 2:print2();break;
            case 3:print3();break;
        }
    }
    return 0;
}