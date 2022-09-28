// 输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
// 我们可以不考虑输出结果的顺序。
//哈希表
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return intersect(nums2,nums1);
        }
        unordered_map<int,int> m;
        for(int num:nums1){
            m[num]++;
        }
        vector<int> res;
        for(int num:nums2){
            if(m.count(num)){
                res.push_back(num);
                m[num]--;
                if(m[num]==0){
                    m.erase(num);
                }
            }
        }
        return res;
    }
};
//
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> res;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                res.push_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i]<nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        return res;
    }
};
//

