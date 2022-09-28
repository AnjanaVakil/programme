//map
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mapp;
        for(int num:nums){
            mapp[num]+=1;
        }
        for(map<int,int>::iterator it=mapp.begin();it!=mapp.end();it++){
            if(it->second==1) return it->first;
        }
        return 0;
    }
};
//排序
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2){
            if(nums[i]==nums[i-1]){
                continue;
            }else{
                return nums[i-1];
            }
        }
        return nums[nums.size()-1];
    }
};
//set
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> sett;
        for(int num:nums){
            if(sett.find(num)==sett.end()){
                //没找到
                sett.insert(num);
            }else{
                sett.erase(num);
            }
        }
        return *sett.begin();
    }
};
//求和法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> sett;
        long sumnum=0;
        long sumset=0;
        int n=nums.size();
        for(int num:nums){
            sumnum+=num;
            if(sett.find(num)==sett.end()){
                sumset+=num;
            }
            sett.insert(num);
        }
        return 2*sumset-sumnum;
    }
};
//异或
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //时间复杂度：O(n)，其中 n 是数组长度。只需要对数组遍历一次。
        //空间复杂度：O(1)。
        int ret=0;
        for(int n:nums){
            ret ^=n;
        }
        return ret;
    }
};
