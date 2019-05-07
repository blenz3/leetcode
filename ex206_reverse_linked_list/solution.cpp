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
    ListNode* reverseList(ListNode* head)
    {
        auto traversal = head;
        head = nullptr;
        while (traversal != nullptr)
        {
            
            auto tmp = traversal;
            traversal = traversal->next;
            tmp->next = head;
            head = tmp;
        }
        
        return head;
    }
};