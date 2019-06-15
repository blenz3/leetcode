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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* out(nullptr), *n(nullptr);
        while (l1 != nullptr || l2 != nullptr)
        {
            ListNode* smaller(nullptr);
            if (l1 == nullptr) 
            {
                smaller = l2;
                l2 = l2->next;
                smaller->next = nullptr;
            }
            else if (l2 == nullptr)
            {
                smaller = l1;
                l1 = l1->next;
                smaller->next = nullptr;
            }
            else if (l1->val > l2->val)
            {
                smaller = l2;
                l2 = l2->next;
                smaller->next = nullptr;
            }
            else
            {
                smaller = l1;
                l1 = l1->next;
                smaller->next = nullptr;
            }
            
            if (out == nullptr)
            {
                out = smaller;
                n = out;
            }
            else
            {
                n->next = smaller;
                n = n->next;
            }
        }
        
        return out;
    }
};