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
