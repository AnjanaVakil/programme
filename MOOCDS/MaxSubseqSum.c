int MaxSubseqSum1(int A[],int N)
{
    int ThisSum,MaxSum=0;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            ThisSum=0;
            for(int k=i;k<=j;k++){
                ThisSum+=A[k];
            }
            if(ThisSum>MaxSum){
                MaxSum=ThisSum;
            }
        }
    }
    return MaxSum;
}
int MaxSubseqSum2(int A[],int N)
{
    int ThisSum,MaxSum=0;
    for(int i=0;i<N;i++){
        ThisSum=0;
        for(int j=i;j<N;j++){
            ThisSum+=A[j];
            if(ThisSum>MaxSum){
                MaxSum=ThisSum;
            }
        }
    }
    return MaxSum;
}
//分而治之
int MaxSubseqSum3(int A[],int N)
{
    int ThisSum,MaxSum=0;
    for(int i=0;i<N;i++){
        ThisSum=0;
        for(int j=i;j<N;j++){
            ThisSum+=A[j];
            if(ThisSum>MaxSum){
                MaxSum=ThisSum;
            }
        }
    }
    return MaxSum;
}
//在线处理
int MaxSubseqSum4(int A[],int N)
{
    int ThisSum=0,MaxSum=0;
    for(int i=0;i<N;i++){
        ThisSum+=A[i];
        if(ThisSum>MaxSum){
            MaxSum=ThisSum;
        }else if(ThisSum<0){
            ThisSum=0;
        }
    }
    return MaxSum;
}