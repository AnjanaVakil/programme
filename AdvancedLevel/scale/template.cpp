//P进制数x-->十进制数y
int y=0,product=1;
while(x!=0){
    y=y+(x%10)*product;
    x/=10;
    product*=P;
}
//十进制数y-->Q进制数z
int z[40],num=0;
do{
    z[num++]=y%Q; //除基取余
    y/=Q;
}while(y!=0);
//从高位的num-1到低位的0即为Q进制z
for(int i=num-1;i>=0;i--){
    cout << z[i];
}
//使用do while循环是为了数字0，如果y是0，也应该输出0




