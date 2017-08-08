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
    ListNode* reverseList(ListNode* head) {
        if(NULL == head || NULL == head->next)
            return head;
        
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* p3 = head->next->next;
        while(NULL != p3)
        {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p2->next;
        }
        p2->next = p1;
        head->next = NULL;
        head = p2;
        return head;
    }
};
