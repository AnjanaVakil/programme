#include<stdio.h>
#include<limits.h>
#include<float.h>
int main()
{
    printf("hello world\n");
    
    printf("int memory size:%lu \n",sizeof(int));
    
    printf("float memory size:%lu \n",sizeof(float));
    printf("float maximum value:%E \n",FLT_MAX);
    printf("float minimum value:%E \n",FLT_MIN);
    printf("float precision:%d \n",FLT_DIG);
    return 0;
}