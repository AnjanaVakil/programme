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

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

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
//返回线性表中首次出现X的位置。若找不到则返回ERROR；
Position Find(List L,ElementType X)
{
    while(L){
        if(L->Data==X){
            return L;
        }
        L=L->Next;
    }
    return ERROR;
}
//将X插入在位置P指向的结点之前，返回链表的表头。
//如果参数P指向非法位置，则打印“Wrong Position for Insertion”，返回ERROR；
List Insert(List L,ElementType X,Position P)
{
    List pb=L;
    List s=(List)malloc(sizeof(struct LNode));
    s->Data=X;
    s->Next=NULL;
    //插入头结点之前(第一个元素之前)
    if(P==L){
        s->Next=pb;
        L=s;
        return L;
    }
    while(pb->Next!=P && pb->Next!=NULL){
        pb=pb->Next;
    }
    if(pb->Next==P){
        s->Next=P;
        pb->Next=s;
        return L;
    }else{
        printf("Wrong Position for Insertion\n");
        return ERROR;
    }
}
/*将位置P的元素删除并返回链表的表头。
若参数P指向非法位置，则打印“Wrong Position for Deletion”并返回ERROR。*/
List Delete(List L,Position P)
{
    List pb=L;
    //空结点
    if(!L){
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    //头结点
    if(L==P){
        L=L->Next;
        return L;
    }
    while(pb->Next!=P && pb->Next!=NULL){
        pb=pb->Next;
    }
    if(pb->Next==P){
        pb->Next=pb->Next->Next;
        return L;
    }else{
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
}