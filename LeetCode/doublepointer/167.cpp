class Solution {
    //尽管使用了break，但还是超出时间限制
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v(2);
        for(int i=0;i<numbers.size();i++){
            for(int j=i+1;j<numbers.size();j++){
                if(numbers[i]+numbers[j]==target){
                    v[0]=i+1;
                    v[1]=j+1;
                }else if(numbers[i]+numbers[j]>target){
                    break;
                }
            }
            if(v[0]!=0) break;
        }
        return v;
    }
};

//双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1,sum;
        while(l<r){
            sum=numbers[l]+numbers[r];
            if(sum==target) break;
            else if(sum<target) l++;
            else r--;
        }
        return vector<int>{l+1,r+1};
    }
};

//二分查找
//已按照 升序排列 的整数数组 numbers!!!
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();i++){
            int low=i+1,high=numbers.size()-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(target-numbers[i]==numbers[mid]) return {i+1,mid+1};
                else if(target-numbers[i]<numbers[mid]) high=mid-1;
                else low=mid+1;
            }
        }
        return {-1,-1};
    }
};