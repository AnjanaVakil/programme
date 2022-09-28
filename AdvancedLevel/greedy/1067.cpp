#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//22:05-33 0'
//Swap(0,i) 只能是数字0和其它数字交换！！！认真读题啊
//N个数字 数字最后的排序是0 1 2 到 N-1
int main()
{
    int n;
    cin >> n;
    int hash[100005];
    vector<int> v(n);
    //5 4 0 2 1 3
    //0 4 2 1 3
    //0 1 2 4 3
    //0 1 2 3 4
    for(int i=0;i<n;i++){
        cin >> v[i];
        hash[v[i]]=i;
    }
    // for(int i=0;i<n;i++){
    //     cout << hash[v[i]] << endl;
    // }
    int cnt=0;
    for(int i=0;i<n;i++){
        int max=*max_element(v.begin()+i,v.end());
        // cout << max << " ";
        int min=*min_element(v.begin()+i,v.end());
        // cout << min << "\n";
        int max_index=hash[max],min_index=hash[min];
        if(min_index<max_index){
            continue;
        }else{
            swap(v[min_index],v[max_index]);
            cnt++;
        }
        // for(int j=0;j<n;j++){
        //     cout << v[j] << " ";
        // }
        // cout << "\n";
    }
    cout << cnt;
    return 0;
}