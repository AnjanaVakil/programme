#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector< vector<string> > vec;
    for(int i=0;i<3;i++){
        vector<string> v;
        string str;
        getline(cin,str);
        int j=0,k=0;
        while(j<str.length()){
            if(str[j]=='['){
                while((k++)<str.length()){
                    if(str[k]==']'){
                        string s=str.substr(j+1,k-j-1);
                        v.push_back(s);
                        break;
                    }
                }
            }
            j++;
        }
        vec.push_back(v);
    }
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        if(a>vec[0].size() || e>vec[0].size() || b>vec[1].size() || d>vec[1].size() || c>vec[2].size() || a<1 || b<1 || c<1 || d<1 || e<1){
            cout << "Are you kidding me? @\\/@\n";
            continue;
        }
        cout << vec[0][a-1] << "(" << vec[1][b-1] << vec[2][c-1] <<vec[1][d-1] << ")" << vec[0][e-1] << "\n";
    }
    return 0;
}