#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */
void InorderTraversal(BinTree BT)
{
    if(BT){
        InorderTraversal(BT->Left);
        printf(" %c",BT->Data);
        InorderTraversal(BT->Right);
    }
}
void PreorderTraversal(BinTree BT)
{
    if(BT){
        printf(" %c",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void PostorderTraversal(BinTree BT)
{
    if(BT){
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %c",BT->Data);
    }
}
void LevelorderTraversal(BinTree BT)
{
    if(!BT) return ;
    BinTree q[10010];
    int s,t;
    s=t=0;
    BinTree T;
    q[t++]=BT;
    while(s<t){
        T=q[s];
        printf(" %c",T->Data);
        if(T->Left) q[t++]=T->Left;
        if(T->Right) q[t++]=T->Right;
        s++;
    }
}
