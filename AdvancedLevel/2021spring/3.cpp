#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> v;
void upAdjust(int low,int high)
{
    int i=high,j=i/2;
    while(j>=low){
        if(v[j]<v[i]){
            swap(v[j],v[i]);
            i=j;
            j=i/2;
        }else{
            break;
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    v.resize(n+1);
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        upAdjust(1,i);
    }
    for(int i=1;i<=n;i++){
        mp[v[i]]=i;
    }
    getchar();
    string s;
    string ans;
    for(int i=0;i<m;i++){
        getline(cin,s);
        int x,y;
        if(s.find("root")!=s.npos){
            sscanf(s.c_str(),"%d is the root",&x);
            if(mp[x]==1) ans+="1";
            else ans+="0";
        }else if(s.find("siblings")!=s.npos){
            sscanf(s.c_str(),"%d and %d are siblings",&x,&y);
            if(mp[x]/2==mp[y]/2) ans+="1";
            else ans+="0";
        }else if(s.find("parent")<s.size()){
            sscanf(s.c_str(),"%d is the parent of %d",&x,&y);
            if(mp[x]==mp[y]/2) ans+="1";
            else ans+="0";
        }else if(s.find("left")!=s.npos){
            sscanf(s.c_str(),"%d is the left child of %d",&x,&y);
            if(mp[x]==mp[y]*2) ans+="1";
            else  ans+="0";
        }else if(s.find("right")!=s.npos){
            sscanf(s.c_str(),"%d is the right child of %d",&x,&y);
            if(mp[x]==mp[y]*2+1) ans+="1";
            else ans+="0";
        }
    }
    cout << ans;
    return 0;
}