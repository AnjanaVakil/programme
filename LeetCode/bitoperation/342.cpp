class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0;i<=sqrt(n);i++){
            if(pow(4,i)==n) return true;
        }
        return false;
    }
};
//
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        while(n%4==0) n/=4;
        return n==1;
    }
};
//
class Solution {
public:
    bool isPowerOfFour(int n) {
        vector<int> ans;
        int num=1;
        ans.push_back(num);
        for(int i=1;i<16;i++){
            num=num*4;
            ans.push_back(num);
        }
        if(find(ans.begin(),ans.end(),n)!=ans.end()) return true;
        return false;
    }
};
//
//如果 n & (n - 1) 为 0，那么这个数是 2 的次方。
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && !(n&(n-1)) && (n&1431655765);
    }
};
//
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && !(n&(n-1)) && (n%3==1);
    }
};

