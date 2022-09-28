//回溯
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums,0,nums.size());
        return res;
    }
    void backtrack(vector<int>& output,int first,int len){
        if(first==len){
            res.emplace_back(output);
        } 
        for(int i=first;i<len;i++){
            swap(output[i],output[first]);
            backtrack(output,first+1,len);
            swap(output[i],output[first]);
        }
    }
};
//回溯
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums,0,res);
        return res;
    }
    void backtrack(vector<int>& nums,int level,vector<vector<int>>& res){
        if(level==nums.size()-1){
            res.push_back(nums);
        } 
        for(int i=level;i<nums.size();i++){
            swap(nums[i],nums[level]);
            backtrack(nums,level+1,res);
            swap(nums[i],nums[level]);
        }
    }
};
//
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backtrack(nums,track);
        return res;
    }
    void backtrack(vector<int>& nums,vector<int>& track){
        if(nums.size()==track.size()){
            res.emplace_back(track);
            return;
        }
        for(int i=0;i<nums.size();i++){
            //找到 continue
            if(find(track.begin(),track.end(),nums[i])!=track.end()) continue;
            track.push_back(nums[i]);
            backtrack(nums,track);
            track.pop_back();
        }
    }
};
//
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track,visited(nums.size(),0);
        backtrack(nums,track,visited);
        return res;
    }
    void backtrack(vector<int>& nums,vector<int>& track,vector<int>& visited){
        if(nums.size()==track.size()){
            res.emplace_back(track);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]==1) continue;
            visited[i]=1;
            track.push_back(nums[i]);
            backtrack(nums,track,visited);
            track.pop_back();
            visited[i]=0;
        }
    }
};