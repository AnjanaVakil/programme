//双指针
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        int sorted[m+n];
        int cur;
        while(i<m || j<n){
            if(i==m){
                cur=nums2[j++];
            }else if(j==n){
                cur=nums1[i++];
            }else if(nums1[i]<nums2[j]){
                cur=nums1[i++];
            }else{
                cur=nums2[j++];
            }
            sorted[i+j-1]=cur;
        }
        for(int i=0;i!=m+n;i++){
            nums1[i]=sorted[i];
        }
    }
};
//直接合并后排序
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};
//逆向双指针
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos=(m--)+(n--)-1;
        while(m>=0 && n>=0){
            nums1[pos--]=nums1[m]>nums2[n]?nums1[m--]:nums2[n--];
        }
        while(n>=0){
            nums1[pos--]=nums2[n--];
        }
    }
};
//逆向双指针
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1,p2=n-1;
        int tail=m+n-1;
        int cur;
        while(p1>=0 || p2>=0){
            if(p1==-1){
                cur=nums2[p2--];
            }else if(p2==-1){
                cur=nums1[p1--];
            }else if(nums1[p1]>nums2[p2]){
                cur=nums1[p1--];
            }else{
                cur=nums2[p2--];
            }
            nums1[tail--]=cur;
        }
    }
};