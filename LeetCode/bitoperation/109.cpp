class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<32;i++){
            //res左移
            res <<= 1;
            res+=(n & 1); //只有这个可以
            // res += (n ^ 0); 不行 
            //res += (n | 0); 不行
            //n右移
            n >>= 1;
        }
        return res;
    }
};
//
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<32;i++){
            res = (res<<1) | (n&1);
            n >>= 1;
        }
        return res;
    }
};

