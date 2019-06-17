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
    // Gameplan
    //  - Seek to end return final node
    //  - When node is returned (that is not nullptr) replace this node with that one
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr)
            return nullptr;
        
        return swapPairsRec(head, 1);
    }
    
    ListNode* swapPairsRec(ListNode* head, int current_length)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        
        if (head->next == nullptr)
        {
            return head;
        }
        
        auto new_head = swapPairsRec(head->next, current_length + 1);
        if (current_length % 2 != 0) // swap every other time
        {
            auto tmp = new_head->next;
            new_head->next = head;
            head->next = tmp;
            return new_head;
        }
        else
        {
            head->next = new_head;
            return head;
        }
    }
};