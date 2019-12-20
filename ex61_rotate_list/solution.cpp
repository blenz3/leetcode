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
    ListNode* rotateRight(ListNode* head, int k) {
        // Boundary cases for empty lists and no rotation
        if (head == nullptr || k == 0)
            return head;
        
        // Retrieve the length of the entire list
        std::size_t length = getLength(head);
        
        // Truncate the amount of shifts so we don't wrap around
        k = k % length;
        if (k == 0) {
            return head;
        }
        
        // Seek to the length - k - 1 element so we can cut it
        ListNode* runner = head;
        for (std::size_t i = 0; i < length - k - 1; ++i) {
            runner = runner->next;
        }
        
        // Copy the rest of the list into our new head
        ListNode* rotated_head = runner->next;
        runner->next = nullptr;
        
        // Get to the previous end and attach the old head to the end
        ListNode* end_of_rotation = rotated_head;
        while (end_of_rotation->next != nullptr) {
            end_of_rotation = end_of_rotation->next;
        }
        
        end_of_rotation->next = head;
        return rotated_head;
    }
    
    std::size_t getLength(ListNode* head) {
        std::size_t length(0);
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        
        return length;
    }  
};
