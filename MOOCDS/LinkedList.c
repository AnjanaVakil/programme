#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

//表长
int Length(List PtrL);
//按序号查找
List FindKth(List PtrL,int K);
//按值查找
Position Find(List PtrL,ElementType X);
//在第i-1个结点之后插入一个植为X的新结点
List Insert(List PtrL,ElementType X,int i);
//删除链表的第i个位置上的结点
List Delete(List PtrL,int i);

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
//表长
int Length(List PtrL)
{
    List p=PtrL;
    int j=0;
    while(p){
        p=p->Next;
        j++;
    }
    return j;
}
//按序号查找
List FindKth(List PtrL,int K)
{
    List p=PtrL;
    int i=1;
    while(p!=NULL && i<K){
        p=p->Next;
        i++;
    }
    if(i==K) return p;
    else return NULL;
}
//按值查找
Position Find(List PtrL,ElementType X)
{
    List p=PtrL;
    while(p!=NULL && p->Data!=X){
        p=p->Next;
    }
    return p;
}
//在第i-1个结点之后插入一个植为X的新结点
List Insert(List PtrL,ElementType X,int i)
{
    //p:要插入结点的前一个即第i-1个结点 s:插入的新结点
    List p,s;
    if(i==1){
        s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=PtrL;
        return s;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL){
        printf("Wrong Position for Insertion\n");
        return NULL;
    }else{
        s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=p->Next;
        p->Next=s;
        return PtrL;
    }
}
//删除链表的第i个位置上的结点
List Delete(List PtrL,int i)
{
    List p,s;
    if(i==1){
        s=PtrL;
        if(PtrL!=NULL) PtrL=PtrL->Next;
        else return NULL;
        free(s);
        return PtrL;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL){
        printf("第%d个结点不存在",i-1);
        return NULL;
    }else if(p->Next==NULL){
        printf("第%d个结点不存在",i);
        return NULL;
    }else{
        s=p->Next;
        p->Next=s->Next;
        free(s);
        return PtrL;
    }
}