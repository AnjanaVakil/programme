//暴力解法：超出时间限制
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup=-1,missing=-1;
        for(int i=1;i<=nums.size();i++){
            int count=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]==i){
                    count++;
                }
            }
            if(count==2){
                dup=i;
            }else if(count==0){
                missing=i;
            }
        }
        return vector<int>{dup,missing};
    }
};
//优化的暴力解法：超出时间限制
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup=-1,missing=-1;
        for(int i=1;i<=nums.size();i++){
            int count=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]==i){
                    count++;
                }
            }
            if(count==2){
                dup=i;
            }else if(count==0){
                missing=i;
            }
            if(dup>0 && missing>0){
                break;
            }
        }
        return vector<int>{dup,missing};
    }
};
//排序:通过
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //dup=-1,missing=1 初值不同
        int dup=-1,missing=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                dup=nums[i];
            }else if(nums[i]>nums[i-1]+1){
                missing=nums[i-1]+1;
            }
        }
        return vector<int>{dup,nums[n-1]!=n?n:missing};
    }
};
//map:通过
//集合 s 包含从 1 到 n 的整数。
//自己做的时候完全忽略了这个条件，因此没独立写出来
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //时间复杂度 O(N) 空间复杂度 O(N)
        map<int,int> mapp;
        int dup=-1,missing=-1;
        for(int num:nums){
            mapp[num]++;
        }
        for(int i=1;i<=nums.size();i++){
            if(mapp.find(i)!=mapp.end()){
                if(mapp[i]==2){
                    dup=i;
                }
            }else{
                //没找到
                missing=i;
            }
        }
        return vector<int>{dup,missing};
    }
};
//使用额外数组
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n+1,0);
        int dup=-1,missing=1;
        for(int num:nums){
            v[num]++;
        }
        for(int i=1;i<=n;i++){
            if(v[i]==2){
                dup=i;
            }else if(v[i]==0){
                missing=i;
            }
        }
        return vector<int>{dup,missing};
    }
};

