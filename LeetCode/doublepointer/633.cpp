//sqrt枚举
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a=0;a*a<=c;a++){
            double b=sqrt(c-a*a);
            if(b==(int)b){
                return true;
            }
        }
        return false;
    }
};
//双指针
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left=0,right=(int)sqrt(c);
        while(left<=right){
            int sum=left*left+right*right;
            if(sum==c){
                return true;
            }else if(sum<c){
                left++;
            }else{
                right--;
            }
        }
        return false;
    }
};
//数学:费马平方和

