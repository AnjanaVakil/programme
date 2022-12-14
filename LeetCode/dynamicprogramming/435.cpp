class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const auto& u,const auto& v){
            return u[1]<v[1];
        });
        //1 2,1 3,2 3,3 4
        vector<int> f(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(intervals[j][1]<=intervals[i][0]){
                    f[i]=max(f[i],f[j]+1);
                }
            }
        }
        return n-*max_element(f.begin(),f.end());
    }
};