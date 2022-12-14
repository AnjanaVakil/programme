#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {false, true} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}
/* 你的代码将被嵌在这里 */
//创建并返回一个空的线性表；
List MakeEmpty()
{
    List L=(List)malloc(sizeof(struct LNode));
    return L;
}

//返回线性表中X的位置。若找不到则返回ERROR；
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

//将X插入在位置P指向的结点之前，返回true。
//如果参数P指向非法位置，则打印“Wrong Position for Insertion”，返回false；
// bool Insert(List L,ElementType X,Position P)
// {
//     List pb=L;
//     List s=(List)malloc(sizeof(struct LNode));
//     s->Data=X;
//     s->Next=NULL;
//     if(P==L){
//         s->Next=pb;
//         L=s;
//         return true;
//     }
//     while(pb->Next!=P && pb->Next!=NULL){
//         pb=pb->Next;
//     }
//     if(pb->Next==P){
//         s->Next=P;
//         pb->Next=s;
//         return true;
//     }else{
//         printf("Wrong Position for Insertion\n");
//         return false;
//     }
// }
bool Insert(List L,ElementType X,Position P)
{
    List Head=L;
    while(Head){
        if(Head->Next==P){
            List Node=(List)malloc(sizeof(List));
            Node->Data=X;
            Node->Next=Head->Next;
            Head->Next=Node;
            return true;
        }
        Head=Head->Next;
    }
    printf("Wrong Position for Insertion\n");
    return false;
}
// //将位置P的元素删除并返回true。
// //若参数P指向非法位置，则打印“Wrong Position for Deletion”并返回false
// bool Delete(List L,Position P)
// {
//     List pb=L;
//     if(!L){
//         printf("Wrong Position for Deletion\n");
//         return false;
//     }
//     if(L==P){
//         L=L->Next;
//         return true;
//     }
//     while(pb->Next!=P && pb->Next!=NULL){
//         pb=pb->Next;
//     }
//     if(pb->Next==P){
//         pb->Next=pb->Next->Next;
//         return true;
//     }else{
//         printf("Wrong Position for Deletion\n");
//         return false;
//     }
// }
bool Delete(List L,Position P)
{
    List Head=L;
    while(Head){
        if(Head->Next==P){
            List T;
            T=Head->Next;
            Head->Next=Head->Next->Next;
            free(T);
            return true;
        }
        Head=Head->Next;
    }
    printf("Wrong Position for Deletion\n");
    return false;
}
