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
    // Use constant space by reversing the second half of the linked list.
    // Mutates the input data though which isn't ideal.
    bool isPalindrome(ListNode* head) {
        size_t length = getListLength(head);
        
        ListNode* runner = head;
        for (size_t i = 0; i < length / 2; ++i) {
            runner = runner->next;
        }
        
        if (length % 2 != 0) {
            runner = runner->next;
        }
        
        runner = reverseList(runner);
        
        while (head != nullptr && runner != nullptr) {
            if (head->val != runner->val) {
                return false;
            }
            
            head = head->next;
            runner = runner->next;
        }
        
        return true;
    }
    
#if 0
    // Uses a O(n) space due to a stack
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
#endif
    
private:
    size_t getListLength(ListNode* head) {
        size_t length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        
        return length;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* newList = nullptr;
        while (head != nullptr) {
            if (newList == nullptr) {
                newList = head;
                head = head->next;
                newList->next = nullptr;
            } else {
                ListNode* tmp = head->next;
                head->next = newList;
                newList = head;
                head = tmp;
            }
        }
        
        return newList;
    }
};
