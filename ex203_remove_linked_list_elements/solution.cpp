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
    
    // Generic walk the list and copy elements which don't match the delete value
    // into a separate list (O(n) time, O(1) space)
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode* reducedListHead = nullptr, *reducedListRunner = nullptr;
        while (head != nullptr) {
            
            // If we are deleting this node just bypass it
            if (head->val == val) {
                head = head->next;
                continue;
            }
            
            if (reducedListHead == nullptr) {
                reducedListHead = reducedListRunner = head;
                head = head->next;
            } else {
                reducedListRunner->next = head;
                head = head->next;
                reducedListRunner = reducedListRunner->next;
            }
            reducedListRunner->next = nullptr;
        }
        
        return reducedListHead;
    }
};
