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
    
     ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        
        int offset = 0;
        unordered_map<ListNode*, int> positions;
        
        
        ListNode* runner = head, *fastRunner = head->next->next;
        while (runner != fastRunner && fastRunner != nullptr && fastRunner->next != nullptr) { 
            positions[runner] = offset++;
            runner = runner->next;
            fastRunner = fastRunner->next->next;
        }
        
        // No cycle detected
        if (fastRunner == nullptr || fastRunner->next == nullptr) {
            return nullptr;
        }
         
        if (positions.count(runner) == 0)
            positions[runner] = offset++;
         
        
        // Keep incrementing the runner until we complete the cycle
        ListNode* minPosNode = runner, *tmp = runner;
        while (tmp->next != runner) {
            if (positions.count(tmp) != 0 && positions[minPosNode] > positions[tmp]) {
                minPosNode = tmp;     
                break;
            } 
            tmp = tmp->next;
        }
        return minPosNode;
    }
    
#if 0
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr)
            return head;
        
        int offset = 0;
        unordered_map<ListNode*, int> positions;
        
        
        ListNode* runner = head;
        while (positions.count(runner) == 0 && runner != nullptr) { 
            positions[runner] = offset++;
            runner = runner->next;
        }
        
        // No cycle detected
        if (runner == nullptr) {
            return nullptr;
        }
        
        // Keep incrementing the runner until we complete the cycle
        ListNode* minPosNode = runner, *tmp = runner;
        while (tmp->next != runner) {
            if (positions[minPosNode] > positions[tmp]) {
                minPosNode = tmp;
                break;
            }
            tmp = tmp->next;
        }
        return minPosNode;
    }
#endif
};
