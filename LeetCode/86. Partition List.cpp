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
    ListNode* partition(ListNode* head, int x) {
        ListNode* tmp1 = new ListNode(0);
        ListNode* tmp2 = new ListNode(0);
        ListNode* head1 = tmp1;
        ListNode* head2 = tmp2;
        int n;
        while(head)
        {
            if(head->val < x)
            {
                tmp1->next = head;
                tmp1 = tmp1->next;
            }
            else
            {
                tmp2->next = head;
                tmp2 = tmp2->next;
            }
            head = head->next;
        }
        tmp2->next = NULL;
        tmp1->next = head2->next;
        return head1->next;
    }
};
