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
    
    // Copy and or the bits in
    int getDecimalValue(ListNode* head) {
        std::vector<bool> values;
        while (head != nullptr) {
            values.push_back(head->val);
            head = head->next;
        }
        
        int64_t value(0), num_bits(static_cast<int64_t>(values.size()));
        for (size_t i = 0; i < num_bits; ++i) {
            value |= (values[i] << (num_bits - i - 1));
        }
        
        return static_cast<int32_t>(value);
    }
    
#if 0
    // Just shift and add 
    int getDecimalValue(ListNode* head) {
        int64_t value(0);
        while (head != nullptr) {
            value = (value << 1) + head->val;
            head = head->next;
        }
        
        return static_cast<int32_t>(value);
    }
#endif
    
    
};
