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
    bool isPalindrome(ListNode* head) {
        // Insert first length / 2 elements into a stack
        size_t length = getListLength(head);
        std::stack<int> stack;
        
        for (size_t i = 0; i < length / 2; ++i) {
            stack.push(head->val);
            head = head->next;
        }
        
        // account for odd length lists
        if (length % 2 != 0) {
            head = head->next;
        }
        
        // compare to end
        for (size_t i = 0; i < length / 2; ++i) {
            int expected = stack.top();
            stack.pop();
            if (expected != head->val) {
                return false;
            }
            
            head = head->next;
        }
        
        return true;
    }
    
private:
    size_t getListLength(ListNode* head) {
        size_t length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        
        return length;
    }
};
