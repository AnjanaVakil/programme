//在选择要保留区间时，区间的结尾十分重要：
//选择的区间结尾越小，余留给其它区间的空间就越大，就越能保留更多的区间。
//因此，我们采取的贪心策略为，优先保留结尾小且不相交的区间。
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        //使用C++的Lamdba结合sort函数进行自定义排序
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        //1 2,1 3,2 3,3 4
        int total=0,prev=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prev){
                total++;
            }else{
                prev=intervals[i][1];
            }
        }
        return total;
    }
};

