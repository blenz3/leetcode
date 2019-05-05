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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
        auto head = new ListNode(0);
        ListNode* current_head = nullptr;
        
        int previous_rollover(0);
        while (l1 != nullptr || l2 != nullptr || previous_rollover != 0)
        {
            auto current_l1_value = (l1 == nullptr) ? 0 : l1->val;
            auto current_l2_value = (l2 == nullptr) ? 0 : l2->val;
            auto sum = current_l1_value + current_l2_value + previous_rollover;
            if (sum >= 10)
            {
                previous_rollover = sum / 10;
                sum %= 10;        
            }
            else
            {
                previous_rollover = 0;
            }

            // First one
            if (current_head == nullptr)
            {
                current_head = head;
                current_head->val = sum;
            }
            else
            {
                current_head->next = new ListNode(sum);
                current_head = current_head->next;
            }
            
            if (l1 != nullptr)
                l1 = l1->next;
            
            if (l2 != nullptr)
                l2 = l2->next;
        }
        
        return head;
    }        
};