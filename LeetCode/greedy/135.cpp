class Solution {
public:
    int candy(vector<int>& ratings) {
        int length=ratings.size();
        vector<int> num(length,1);
        for(int i=1;i<length;i++){
            if(ratings[i]>ratings[i-1]) num[i]=num[i-1]+1;
        }
        for(int i=length-1;i>0;i--){
            if(ratings[i-1]>ratings[i]) num[i-1]=max(num[i-1],num[i]+1);
        }
        int res=0;
        for(int i=0;i<num.size();i++){
            res+=num[i];
        }
        return res;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size=ratings.size();
        if(size<2) return size;
        vector<int> num(size,1);
        for(int i=1;i<size;i++){
            if(ratings[i]>ratings[i-1]) num[i]=num[i-1]+1;
        }
        for(int i=size-1;i>0;i--){
            if(ratings[i-1]>ratings[i]) num[i-1]=max(num[i-1],num[i]+1);
        }
        return accumulate(num.begin(),num.end(),0);
        // std::accumulate 可以很方便地求和
    }
};

