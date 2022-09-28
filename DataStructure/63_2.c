#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}

/**
 * 打印链表
 */
void Print( List L ) {
    while(L) {
        printf("%d ", L->Data);
        L = L->Next;
    }
    printf("\n");
}

/**
 * 初始化开辟链表
 */
List Read() {
    int N;
    List a = (List)malloc(sizeof(struct LNode));    // 申请新节点
    List head = a;                                  // 设置头节点

    scanf("%d", &N);
    if(N == -1) head = NULL;     		// 如果是空链表
    while(N != -1) {        			// 当值不为-1时,不断向后面添加新节点
        a->Data = N;        			// 给新节点赋值
        scanf("%d", &N);
        if(N == -1) a->Next=NULL;       // 如果是-1，指针指空
        else {
            a->Next = (List)malloc(sizeof(struct LNode));   // 开辟新的节点
            a = a->Next;        		// 指针向后移动一位
        }
    }
    return head;
}

/* 你的代码将被嵌在这里 */
// int Length(List L)
// {
//     int length=0;
//     while(pNode!=NULL){
//         pNode=pNode->Next;
//         length++;
//     }
//     return length;
// }

int Length(List L)
{
    int len=0;
    while(L!=NULL){
        len++;
        L=L->Next;
    }
    return len;
}