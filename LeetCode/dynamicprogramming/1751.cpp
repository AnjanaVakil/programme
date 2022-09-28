//有问题
class Solution {
public:
    //这个方法要写static，否则编译不通过,why???
    static bool cmp(vector<int>& events1,vector<int>& events2){
        return events1[1]<events2[1];
    }
    int binarysearch(vector<int>& arr,int left,int right,int target){
        while(left<=right){
            int mid=left+(right-left)/2;
            if(target<arr[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return left-1;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();

        //按照会议结束时间升序排序
        sort(events.begin(),events.end(),cmp);

        //会议的结束时间
        vector<int> end(n+1);
        for(int i=0;i<n;i++){
            end[i+1]=events[i][1];
        }
        //二分查找 p[i] a[i]开始前最后结束的会议编号
        vector<int> p(n+1); 
        for(int i=1;i<n;i++){
            p[i]=binarysearch(end,0,i-1,events[i-1][0]-1);
        }
        vector<int> dp(n+1);
        dp[0]=0;
        for(int j=1;j<=n;j++){
            if(dp[p[j]]+events[j][2]>dp[j-1]){
                dp[j]=dp[p[j]]+events[j][2];
            }else{
                dp[j]=dp[j-1];
            }
        }
        return dp[n];
    }
};