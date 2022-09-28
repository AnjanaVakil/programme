#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
//25'
const int maxn=10010;
const int inf=11111;
struct Node{
    int depth=inf;
    int id;
    int father=inf;
}node[maxn];
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    //在接收完n后要getchar()读取一下换行符才能用getline，否则换行符会被读进getline中～
    getchar();
    for(int i=0;i<n;i++){
        getline(cin,v[i]);
        int depth=v[i].length()-4;
        int id=stoi(v[i]);
        node[id].depth=depth;
        node[id].id=id;
        for(int j=i-1;j>=0;j--){
            int lastdepth=v[j].length()-4;
            int lastid=stoi(v[j]);
            if(lastdepth==depth-1){
                node[id].father=lastid;
                break;
            }
        }
    }
    int k,query;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> query;
        if(node[query].depth==inf){
            printf("Error: %04d is not found.\n",query);
            continue;
        }
        //res初始化应该放在里面
        vector<int> res;
        res.push_back(query);
        while(node[query].father!=inf){
            res.push_back(node[query].father);
            query=node[query].father;
        }
        for(int j=res.size()-1;j>=0;j--){
            printf("%04d%s",res[j],j==0?"\n":"->");
        }
    }
    return 0;
}