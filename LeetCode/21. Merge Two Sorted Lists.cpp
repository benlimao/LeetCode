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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(NULL == l1)
            return l2;
        if(NULL == l2)
            return l1;
        
        ListNode* head = NULL;
        if(l1->val < l2->val)
        {
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }
        return head;
    }
};

//1.递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(NULL == l1)
            return l2;
        if(NULL == l2)
            return l1;
        
        ListNode* head = NULL;
        if(l1->val < l2->val)
        {
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }
        return head;
    }
};

//遍历
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(NULL == l1) return l2;
        if(NULL == l2) return l1;
        //头节点
        ListNode* head = NULL;
        if(l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }
        ListNode* p = head;
        //连接
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        //将剩余的节点接到尾部
        if(l1)
            p->next = l1;
        else
            p->next = l2;
        return head;
    }
};
