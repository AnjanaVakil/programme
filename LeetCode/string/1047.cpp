//std::string 类本身就提供了类似「入栈」和「出栈」的接口
class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for(char ch:s){
            if(!stk.empty() && stk.back()==ch){
                stk.pop_back();
            }else{
                stk.push_back(ch);
            }
        }
        return stk;
    }
};
//
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(char ch:s){
            if(!stk.empty() && ch==stk.top()){
                stk.pop();
            }else{
                stk.push(ch);
            }
        }
        string res="";
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
