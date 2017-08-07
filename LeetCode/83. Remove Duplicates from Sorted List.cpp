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
    ListNode* deleteDuplicates(ListNode* head) {
        if(NULL == head || NULL == head->next)
            return head;
        
        ListNode* left = head;
        ListNode* right = head;
        while (NULL != right->next)
		{
            while(NULL != left->next && left->next->val != left->val)
                left = left->next;
            right = left;
			while (NULL != right->next && right->next->val == left->val)
				right = right->next;
			left->next = right->next;
		}
        return head;
    }
};
