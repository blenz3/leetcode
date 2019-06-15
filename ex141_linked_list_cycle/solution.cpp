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
    
    // Use a runner and a fast runner which steps ahead two places at a time. If they ever intersect then 
    // we know a cycle exists. If the fast runner reaches the end then there is obviously no cycle.
    // Runs in linear time and constant space.
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        
        ListNode* runner(head), *fast_runner(head);
        while (fast_runner->next != nullptr && fast_runner->next->next != nullptr)
        {
            runner = runner->next;
            fast_runner = fast_runner->next->next;
            
            if (runner == fast_runner)
                return true;
        }
        
        return false;
    }
};