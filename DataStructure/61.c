#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Reverse(List L)
{
    PtrToNode pReversedHead=NULL;
    PtrToNode pNode=L;
    PtrToNode pPrev=NULL;
    while(pNode!=NULL){
        PtrToNode pNext=pNode->Next;
        if(pNext==NULL){
            pReversedHead=pNode;
        }
        pNode->Next=pPrev;
        pPrev=pNode;
        pNode=pNext;
    }
    return pReversedHead;
}
