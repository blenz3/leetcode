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
    
    void append(ListNode*& head, ListNode*& runner, ListNode*& new_node)
    {
        if (head == nullptr)
        {
            head = new_node;
            runner = new_node;
        }
        else
        {
            runner->next = new_node;
            runner = runner->next;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {        
        ListNode* head(nullptr), *runner(nullptr);
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 != nullptr && l2 != nullptr)
            {
                ListNode*& smaller = (l1->val < l2->val) ? l1 : l2;
                append(head, runner, smaller);
                smaller = smaller->next;
            }
            else if (l1 != nullptr)
            {
                append(head, runner, l1);
                l1 = l1->next;
            }
            else if (l2 != nullptr)
            {
                append(head, runner, l2);
                l2 = l2->next;
            }
        }
        
        if (runner != nullptr)
            runner->next = nullptr;
        
        return head;
    }
};