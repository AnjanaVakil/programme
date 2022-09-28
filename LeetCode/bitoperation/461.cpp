class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt=0;
        while(x || y){
            if(x%2 ^ y%2 ==1){
                cnt++;
            }
            x/=2;
            y/=2;
        }
        return cnt;
    }
};
//
class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        int cnt=0;
        while(diff){
            //diff&1 相当于 diff%2
            // if(diff & 1){
            //     cnt++;
            // }
            cnt+=(diff & 1);
            //使用逻辑右移
            diff >>= 1;
        }
        return cnt;
    }
};
