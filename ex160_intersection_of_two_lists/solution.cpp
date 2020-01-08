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
    // Find the length of each list and then equalize the length and walk to the end
    // (O(n) time, constant space)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) 
            return nullptr;
        
        // Find the length of each list
        int a_len = getListLength(headA);
        int b_len = getListLength(headB);
        
        ListNode*& longer_list = (a_len > b_len) ? headA : headB;
        ListNode*& shorter_list = (a_len > b_len) ? headB : headA;
        
        // Advance the longer list to the point where the list lengths are equal
        for (int i = 0; i < abs(a_len - b_len); ++i) {
            longer_list = longer_list->next;
        }
        
        // Advance until a common node is found or wereach the end of the list
        while (longer_list != nullptr && shorter_list != nullptr && longer_list != shorter_list) {
            longer_list = longer_list->next;
            shorter_list = shorter_list->next;
        }
        
        return (longer_list != nullptr) ? longer_list : nullptr;
    }
    
private:
    int getListLength(ListNode* head) {
        int len(0);
        while (head != nullptr) {
            len++;
            head = head->next;
        }
        
        return len;
    }
    
#if 0
    // Simple solution using an unordered set to cache all the nodes from A and then 
    // walking B to find the first one in A. (O(n) time, O(n) space)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        
        std::unordered_set<ListNode*> cachedNodes;
        while (headA != nullptr) {
            cachedNodes.insert(headA);
            headA = headA->next;
        }
        
        while (headB != nullptr) {
            if (cachedNodes.count(headB) != 0) 
                return headB;
            headB = headB->next;
        }
        
        return nullptr;
    }
#endif
};
