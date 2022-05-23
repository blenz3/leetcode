/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Strategy 1
    //   - Count all nodes
    //   - Start from head again and go n / 2 spots and return
#if 0
    ListNode* middleNode(ListNode* head) {
        int nodeCount = countNodes(head);
        int moveCount = (nodeCount / 2);
        while (moveCount != 0) {
            head = head->next;
            moveCount--;
        }
        
        return head;
    }
    
    int countNodes(ListNode* head) {
        int count(0);
        while (head != nullptr) {
            head = head->next;
            count++;
        }
        return count;
    }
#endif
    
    // Strategy 2
    //   - Two pointers 
    //   - one goes two at a time and one goes one at a time
    //   - By the time the two at a time gets to the end we will be in the middle in the other
    ListNode* middleNode(ListNode* head) {
        ListNode* runner = head, *fastRunner = head;
        while (fastRunner != nullptr) {
            if (fastRunner->next == nullptr) {
                fastRunner = nullptr;
            } else {
                fastRunner = fastRunner->next->next;
                runner = runner->next;
            }
        }
        
        return runner;
    }
};
