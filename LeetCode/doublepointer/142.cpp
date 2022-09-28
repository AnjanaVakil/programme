/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//快慢指针（Floyd判圈法）
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        do{
            if(!fast || !fast->next) return nullptr;
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        fast=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};
//哈希表
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while(head){
            //count(key) 在容器中查找值为 key 的元素的个数
            if(visited.count(head)){
                return head;
            }
            visited.insert(head);
            head=head->next;
        }
        return nullptr;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr){
            slow=slow->next;
            if(fast->next==nullptr) return nullptr;
            fast=fast->next->next;
            if(fast==slow){
                ListNode *ptr=head;
                while(ptr!=slow){
                    slow=slow->next;
                    ptr=ptr->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};



