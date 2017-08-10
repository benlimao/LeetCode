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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(NULL == head || 0 >= n || NULL == head->next)
            return NULL;
        
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        
        ListNode* left = newHead;
        ListNode* right = left;
        for(int i = 0; i < n; i++)
            right = right->next;
            
        while(right->next)
        {
            left = left->next;
            right = right->next;
        }
        ListNode* target = left->next;
        left->next = left->next->next;
        delete target;   
        return newHead->next;
    }
};
