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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = getLength(head);
        if (length == 0 || length < k) {
            return head;
        }
        
        // We will need to reverse a k group length / k times. To do so 
        // we'll that entire group, reverse it, and then reinsert it
        ListNode* start = head, *end = head, *prevGroup = nullptr, *nextGroup = nullptr, *root = nullptr;
        for (int kGroup = 0; kGroup < length / k; ++kGroup) {
            for (int node = 0; node < k - 1; ++node) {
                end = end->next;
            }
            
            // Disconnect the last one
            nextGroup = end->next;
            end->next = nullptr;
            
            // Reverse the group and relink it 
            auto* reversed = reverse2(start);
            if (root == nullptr) {
                root = reversed;
                prevGroup = start;
                start->next = nextGroup;
                start = nextGroup;
                end = nextGroup;
            } else {
                prevGroup->next = reversed;
                start->next = nextGroup;
                prevGroup = start;
                start = nextGroup;
                end = nextGroup;
            }
        }
        
        return root;
        
    }
    
    void printList(ListNode* head) {
        printf("[");
        while (head != nullptr) {
            printf("%d, ", head->val);
            head = head->next;
        }
        
        printf("]\n");
    }
    
    ListNode* reverse2(ListNode* head) {
        ListNode* newHead = nullptr;
        ListNode* runner = head;
        while (runner != nullptr) {
            ListNode* tmp = runner->next;
            runner->next = newHead;
            newHead = runner;
            runner = tmp;
        }
        
        return newHead;
        
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* root = nullptr;
        stack<ListNode*> s;
        while (head != nullptr) {
            s.push(head);
            head = head->next;
        }
        
        ListNode* runner = nullptr;
        while (!s.empty()) {
            auto* top = s.top();
            if (root == nullptr) {
                root = top;
                runner = top;
            } else {
                runner->next = top;
                runner = runner->next;
                runner->next = nullptr;
            }
            s.pop();
        }
        return root;
        
//         if (head->next == nullptr)
//             return head;
        
//         auto* replacement = reverse(head->next);
//         printf("replacement %d, head %d\n", replacement->val, head->val);
//         replacement->next = head;
//         return replacement;
    }
    
     int getLength(ListNode* head) {
        int count(0);
        while (head != nullptr) {
            head = head->next;
            count++;
        }
        
        return count;
    }
    
#if 0
    // Strategy 
    //  - Brute force esque approach 
    //  - Index each of the nodes and then reorder pointers to the nodes and then reassemble
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) 
            return head;
        
        // Grab pointers to all the nodes in their original configuration
        std::vector<ListNode*> nodes;
        while (head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }
        
        // Iterate over each k group and reverse the pointers
        for (int i = 0; i < nodes.size() / k; ++i) {
            int start = i * k, end = ((i + 1) * k) - 1;
            while (start < end) {
                auto tmp = nodes[start];
                nodes[start] = nodes[end];
                nodes[end] = tmp;
                start++, end--;
            }
        }
        
        // Relink and return
        for (int i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->next = nodes[i + 1];
        }
        nodes[nodes.size() - 1]->next = nullptr;
        
        return nodes[0];
    }
#endif
};
