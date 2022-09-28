//「袖珍计算器算法」是一种用指数函数 exp 和对数函数 ln 代替平方根函数的方法
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int ans=exp(0.5*log(x));
        //计算机无法存储浮点数的精确值
        return ((long long)(ans+1)*(ans+1)<=x?(ans+1):ans);
    }
};
//二分查找
class Solution {
public:
    int mySqrt(int x) {
        int left=0,right=x,ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if((long long)mid*mid<=x){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};
//二分查找
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int left=1,right=x;
        while(left<=right){
            int mid=left+(right-left)/2;
            int sqrt=x/mid;
            if(sqrt==mid){
                return mid;
            }else if(sqrt>mid){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return right;
    }
};


