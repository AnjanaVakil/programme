#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct LNode *PtrToNode;
struct LNode{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;
List Read()
{
    List L,Rear,temp;
    ElementType data;
    L=(List)malloc(sizeof(struct LNode));
    L->Data=-1;
    L->Next=NULL;
    Rear=L;
    while(scanf("%d",&data) && data!=-1){
        temp=(List)malloc(sizeof(struct LNode));
        temp->Data=data;
        temp->Next=NULL;
        Rear->Next=temp;
        Rear=Rear->Next;
    }
    return L;/* 返回带头空结点的链表 */
}
List Merge(List a,List b)
{
    List L,Rear,pa,pb;
    L=(List)malloc(sizeof(struct LNode));
    L->Data=-1;
    L->Next=NULL;
    Rear=L;
    pa=a->Next;
    pb=b->Next;
    while(pa && pb){
        if(pa->Data==pb->Data){
            Rear->Next=pa;
            pa=pa->Next;
            pb=pb->Next;
            Rear=Rear->Next;
        }
        else if(pa->Data<pb->Data) pa=pa->Next;
        else pb=pb->Next;
    }
    Rear->Next=NULL;
    return L;
}
void print(List L)
{
    List p;
    p=L->Next;
    int flag=0;
    if(!p){
        printf("NULL");
    }else{
        while(p){
            if(flag) printf(" ");
            printf("%d",p->Data);
            p=p->Next;
            flag=1;
        }
    }
}
int main()
{
    List a,b,c;
    a=Read();
    b=Read();
    c=Merge(a,b);
    print(c);
    return 0;
}