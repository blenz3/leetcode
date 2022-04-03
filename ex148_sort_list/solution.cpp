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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return head;
        
        return mergeSort(head);
    }
    
    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        
        ListNode* mid = getMid(head);
        ListNode* n1 = mergeSort(head);
        ListNode* n2 = mergeSort(mid);
        
        ListNode* merged(nullptr), *runner(nullptr);
        
        while (n1 != nullptr || n2 != nullptr) {
            ListNode* next(nullptr);
            if (n1 == nullptr) {
                next = n2;
                n2 = n2->next;
            } else if (n2 == nullptr) {
                next = n1;
                n1 = n1->next;
            } else if (n2->val <= n1->val) {
                next = n2;
                n2 = n2->next;
            } else if (n1->val < n2->val) {
                next = n1;
                n1 = n1->next;
            } 
            
            if (merged == nullptr) {
                merged = next;
                runner = next;
            } else {
                runner->next = next;
                runner = runner->next;
            }
        }
        
        return merged;
    }
    
    int getLength(ListNode* n) {
        int count(0);
        while (n != nullptr) {
            n = n->next;
            count++;
        }
        
        return count;
    }
    
    ListNode* getMid(ListNode* n) {
        
        int length = getLength(n);
        int midpoint = (length / 2) - 1;
        for (int i = 0; i < midpoint; ++i) {
            n = n->next;
        }
        
        auto tmp = n;
        n = n->next;
        tmp->next = nullptr;
        return n;
    }
};
