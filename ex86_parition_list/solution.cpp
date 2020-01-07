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
    // Delink each node into a lesser list and a greater list and then recombine them
    // to preserve the order (O(n) time, O(1) space)
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* lesser_head = nullptr, *lesser_runner = nullptr, *greater_head = nullptr, *greater_runner = nullptr;
        while (head != nullptr) {
            ListNode*& current_runner = (head->val >= x) ? greater_runner : lesser_runner;
            if (current_runner == nullptr) {
                ListNode*& current_head = (head->val >= x) ? greater_head : lesser_head;
                current_runner = current_head = head;            
            } else {
                current_runner->next = head;
                current_runner = current_runner->next;
            }
            
            head = head->next;
            current_runner->next = nullptr;
        }
        
        if (lesser_head == nullptr) {
            return greater_head;
        }
        
        lesser_runner->next = greater_head;
        return lesser_head;
    }
};
