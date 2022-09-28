//求和法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        set<int> sett;
        long sumnum=0;
        long sumset=0;
        for(int num:nums){
            sumnum+=num;
            if(sett.find(num)!=sett.end()) continue;
            sumset+=num;
            sett.insert(num);
        }
        return (3*sumset-sumnum)/2;
    }
};
//哈希表
//自己写的
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mapp;
        for(int num:nums){
            mapp[num]+=1;
        }
        for(unordered_map<int,int>::iterator it=mapp.begin();it!=mapp.end();it++){
            if(it->second==1) return it->first;
        }
        return -1;
    }
};
//leetcode官方
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num:nums){
            ++freq[num];
        }
        int ans=0;
        for(auto [num,occ]:freq){
            if(occ==1){
                ans=num;
                break;
            }
        }
        return ans;
    }
};
//位运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //使用位运算 (x >> i) & 1 得到 x 的第 i 个二进制位
        //& 与运算符
        int ans=0;
        for(int i=0;i<32;i++){
            int total=0;
            for(int num:nums){
                total += ((num>>i) & 1);
            }
            if(total%3){
                ans |= (1<<i);
            }
        }
        return ans;
    }
};
