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
    // Use more space to go faster/cleaner
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*> nodes;
        while (head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }
        // print(nodes);
        
        while (left < right) {
            auto tmp = nodes[left - 1];
            nodes[left - 1] = nodes[right - 1];
            nodes[right - 1] = tmp;
            left++, right--;
        }

        // print(nodes);
        for (int i = 0; i < nodes.size(); ++i) {
            if (i + 1 == nodes.size()) {
                nodes[i]->next = nullptr;
            } else {
                nodes[i]->next = nodes[i + 1];
            }
        }
        
        return nodes[0];
    }
    void print(const vector<ListNode*>& nodes) {
        printf("[");
        for (auto n : nodes) {
            printf("%d -> ", n->val);
        }
        printf("]\n");
    }
#if 0
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Get the node immediately before
        ListNode* beforeStart = (left != 1) ? seekTo(head, left - 1) : head;
        ListNode* start = (left != 1) ? beforeStart->next : head;
        
        
        // Get the next node after 
        ListNode* end = seekTo(head, right);
        ListNode* pastEnd = end->next;
        
        // Disconnect end from the list
        end->next = nullptr;
        
        if (left == 1) {
            head = reverse(start);
            start->next = pastEnd;
        } else {
            beforeStart->next = reverse(start);
            start->next = pastEnd;
        }
        
        return head;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* out = nullptr;
        while (head != nullptr) {
            auto next = head->next;
            if (out == nullptr) {
                out = head;
                head->next = nullptr;
            } else {
                head->next = out;
                out = head;
            }
            head = next;
        }
        return out;
    }
    
    ListNode* seekTo(ListNode* head, int index) {
        if (index == 1 || head == nullptr) 
            return head;
        
        return seekTo(head->next, index - 1);
    }
#endif
};
