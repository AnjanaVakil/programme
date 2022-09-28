//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *temp1=head,*temp2=head;
        int len=0;
        while(temp1){
            len+=1;
            temp1=temp1->next;
        }
        for(int i=0;i<len-k;i++){
            temp2=temp2->next;
        }
        return temp2;
    }
};
//双指针
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *former=head,*latter=head;
        for(int i=0;i<k;i++){
            former=former->next;
        }
        while(former){
            former=former->next;
            latter=latter->next;
        }
        return latter;
    }
};
