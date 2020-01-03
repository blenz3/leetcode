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
    
    // Walk the list once (O(n) time, O(1) space)
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return head;
        
        ListNode* out = nullptr, *outRunner = nullptr, *headRunner = nullptr;
        while (head != nullptr) {
            bool dupeEncountered = false;
            headRunner = head->next;
            while (headRunner != nullptr && head->val == headRunner->val) {
                dupeEncountered = true;
                headRunner = headRunner->next;
            }
            
            // If we encountered a duplicate then we don't add this to our output list
            if (dupeEncountered) {
                head = headRunner;
                continue;
            }
            
            if (out == nullptr) {
                out = head;
                out->next = nullptr;
                outRunner = out;
                head = headRunner;
            } else {
                outRunner->next = head;
                outRunner = outRunner->next;
                outRunner->next = nullptr;
                head = headRunner;
            }
        }
        
        return out;
    }
    
#if 0
    // Use a hash table to count all the values and only return the values which
    // have only one occurrence (O(n) time, O(n) space)
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        std::unordered_map<int, size_t> counts;
        ListNode* runner = head;
        while (runner != nullptr) {
            counts[runner->val]++;
            runner = runner->next;
        }
        
        ListNode* dedupedList = nullptr, *dedupedListRunner = nullptr;
        while (head != nullptr) {
            if (counts[head->val] > 1) {
                head = head->next;
                continue;
            }
            
            if (dedupedList == nullptr) {
                dedupedList = head;
                dedupedListRunner = dedupedList;
                head = head->next;
                dedupedList->next = nullptr;
            } else {
                dedupedListRunner->next = head;
                head = head->next;
                dedupedListRunner = dedupedListRunner->next;
            }
        }
        
        if (dedupedListRunner != nullptr)
            dedupedListRunner->next = nullptr;
        
        return dedupedList;
        
    }  
#endif
        
};
