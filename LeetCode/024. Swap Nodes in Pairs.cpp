/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//1.递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(NULL == head || NULL == head->next)
            return head;
        
        ListNode* tmp = head->next;
        head->next = swapPairs(tmp->next);
        tmp->next = head;
        return tmp;
    }
};

//2.迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(NULL == head || NULL == head->next)
            return head;
        
        ListNode newHead(0);
        newHead.next = head;
        ListNode* p = &newHead;
        ListNode* a;
        ListNode* b;
        head = p->next->next;
        while((a = p->next) && (b = p->next->next))
        {
            a->next = b->next;
            b->next = a;
            p->next = b;
            p = b->next;
        }
        return head;
    }
};
