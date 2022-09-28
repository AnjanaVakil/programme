#include <stdio.h>
#include <stdlib.h>
typedef struct PolyNode *Polynomial; //声明一个结构体指针
struct PolyNode
{
    int coef;        //系数
    int expon;       //指数
    Polynomial link; //链
};
Polynomial ReadPoly();
void Attach(int c, int e, Polynomial *pRear);
void PrintPoly(Polynomial P);
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Mult(Polynomial P1, Polynomial P2);
void PrintPoly(Polynomial P);

/* 输入多项式
    乘法运算
    加法运算
    输入多项式*/
void Attach(int c, int e, Polynomial *pRear)
{ //不需要返回值，完成链表建立之后即可，注意Rear本身就是一个指针，需要把指针的指针传入
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    P->coef = c;
    P->expon = e;
    (*pRear)->link = P;
    *pRear = P; //尾插法
}
Polynomial ReadPoly()
{ //一定要返回结构体指针类型
    int n;
    int c, e;
    scanf("%d", &n);
    Polynomial P, Rear, t;
    P = (Polynomial)malloc(sizeof(struct PolyNode)); //给结点分配内存空间
    P->link = NULL;                                  //初始化头结点
    Rear = P;                                        //尾结点从头开始遍历
    while (n--)
    {
        scanf("%d %d", &c, &e);
        Attach(c, e, &Rear); //因为Rear的只需要改变，所以用引用
    }
    t = P;
    P = P->link;
    free(t);  //释放头结点空间
    return P; //返回第一个有值的结点
}
Polynomial Add(Polynomial P1, Polynomial P2)
{
    Polynomial t1, t2, Rear, P, t;
    t1 = P1, t2 = P2; //t1和t2用来遍历整个P1和P2链表
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P; //Add后新的链表的尾指针
    while (t1 && t2)
    {
        if (t1->expon == t2->expon)
        { //假如指数相同，则指数不变，系数相加
            if (t1->coef + t2->coef)
            {
                Attach(t1->coef + t2->coef, t1->expon, &Rear);
            }
            t1 = t1->link;
            t2 = t2->link;
        }
        else if (t1->expon > t2->expon)
        {
            Attach(t1->coef, t1->expon, &Rear);
            t1 = t1->link;
        }
        else
        {
            Attach(t2->coef, t2->expon, &Rear);
            t2 = t2->link;
        }
    }
    while (t1)
    {
        Attach(t1->coef, t1->expon, &Rear);
        t1 = t1->link;
    }
    while (t2)
    {
        Attach(t2->coef, t2->expon, &Rear);
        t2 = t2->link;
    }
    t = P;
    P = P->link;
    free(t);  //删除头结点
    return P; //返回第一个结点
}
Polynomial Mult(Polynomial P1, Polynomial P2)
{
    if (!P1 || !P2)
        return NULL;
    Polynomial t1, t2, P, t, Rear;
    t1 = P1;
    t2 = P2;
    int e, c; //记录当前要插入结点的指数和系数
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while (t2)
    { //先获得第一个结点的值
        Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
        t2 = t2->link; //仅对t2进行遍历
    }
    t1 = t1->link; //t1的第一个结点已经遍历结束，开始对第二个结点开始遍历
    while (t1)
    {
        t2 = P2;  //t2重新开始从头开始
        Rear = P; //Rear永远指向新链表P尾结点
        while (t2)
        {
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            while (Rear->link && Rear->link->expon > e)
            { //新的链表也要按照指数递减的顺序
                Rear = Rear->link;
            }
            if (Rear->link && Rear->link->expon == e)
            { //指数相同看系数
                if (Rear->link->coef + c)
                { //
                    Rear->link->coef += c;
                }
                else
                { //如果系数为0，则删除这个结点
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            }
            else
            { //指数不同的情况需要创建新的结点
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link; //本质上就是链表的插入过程
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t2 = P; //这里用t1和t2都行，因为指针已经遍历完了P1或者P2
    P = P->link;
    free(t2); //删除头结点
    return P; //返回第一个结点
}
void PrintPoly(Polynomial P)
{                 //链表遍历问题
    int flag = 0; //第一个前面没有空格，用来做标记
    if (!P)
    {
        printf("0 0\n");
        return;
    } //如果链表为空
    while (P)
    {
        if (!flag)
            flag = 1;
        else
            printf(" ");
        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n"); //输入完一行加法后后还需要输入再输入乘法
}
int main()
{
    Polynomial P1, P2, PP, PS;
    P1 = ReadPoly();   //读取第一个链表的第一个结点
    P2 = ReadPoly();   //读取第二个链表的第一个结点
    PP = Mult(P1, P2); //对P1和P2两个链表进行多项式乘法运算
    PrintPoly(PP);     //输出多项式乘法运算
    PS = Add(P1, P2);  //对P1和P2两个链表进行多项式的加法运算
    PrintPoly(PS);     //输出多项式加法运算
    return 0;
}
