//哈希表 时间复杂度O(N) 空间复杂度O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int res;
        unordered_map <int,int> count;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
            if(count[nums[i]]>n/2) res=nums[i];
        }
        return res;
    }
};
//
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int res;
        unordered_map <int,int> count;
        for(int num:nums){
            count[num]++;
            if(count[num]>n/2) res=num;
        }
        return res;
    }
};
//排序 时间复杂度O(NlogN) 空间复杂度O(logN)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return nums[n/2];
    }
};
//摩尔投票法 时间复杂度O(N) 空间复杂度O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res,vote=0;
        for(int i=0;i<nums.size();i++){
            if(vote==0) res=nums[i];
            if(res==nums[i]) vote++;
            else vote--;
        }
        return res;
    }
};
//
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res,vote=0;
        for(int i=0;i<nums.size();i++){
            if(vote==0) res=nums[i];
            vote += (res==nums[i]? 1:-1);
        }
        return res;
    }
};
//
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res,vote=0;
        for(int num:nums){
            if(vote==0) res=num;
            vote += (res==num?1:-1);
        }
        return res;
    }
};
