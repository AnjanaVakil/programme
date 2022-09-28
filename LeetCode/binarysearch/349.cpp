//输出结果中的每个元素一定是唯一的。
//我们可以不考虑输出结果的顺序。
//使用set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1,set2;
        for(auto& num:nums1){
            set1.insert(num);
        }
        for(auto& num:nums2){
            set2.insert(num);
        }
        return getIntersection(set1,set2);
    }
    vector<int> getIntersection(unordered_set<int>& set1,unordered_set<int>& set2){
        if(set1.size()>set2.size()){
            return getIntersection(set2,set1);
        }
        vector<int> intersection;
        for(auto& num:set1){
            if(set2.count(num)){
                intersection.push_back(num);
            }
        }
        return intersection;
    }
};
//排序+双指针
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> res;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                if(res.size()==0 || nums1[i]!=res.back()){
                    res.push_back(nums1[i]);
                }
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
//binary search
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(),nums2.end());
        unordered_set<int> set;
        for(int num:nums1){
            if(binary_search(nums2,num)!=-1){
                set.insert(num);
            }
        }
        vector<int> res;
        for(auto& num:set){
            res.push_back(num);
        }
        return res;
    }
    int binary_search(vector<int>& nums,int target){
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(target==nums[mid]){
                return mid;
            }else if(target<nums[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return -1;
    }
};


