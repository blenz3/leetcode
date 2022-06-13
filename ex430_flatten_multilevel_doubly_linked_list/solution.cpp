/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* output = nullptr;
        flattenLevels(head, output);
        setPrevious(output);
        return output;
    }
    
private:
    
    void printList(Node* out) {
        while (out != nullptr) {
            printf("%d ->", out->val);
            out = out->next;
        }
        printf("\n");
    }
    
    // Traverse all the way to the end and then just start grabbing nodes
    void flattenLevels(Node* head, Node*& out) {
        if (head == nullptr) {
            return;
        }
        
        auto child = head->child;
        auto next = head->next;
        
        head->child = head->next = nullptr;
        
        // This one is next
        out = head;
        
        // printList(out);
        
        // Keep traversing first with the child
        if (child != nullptr) {
            flattenLevels(child, out->next);
        }
        
        // Seek to the end of the added nodes from the child
        Node* end = seekToEnd(out);
        
        // Continue traversing right on our current list
        if (next != nullptr) {
            flattenLevels(next, end->next);
        }
    }
    
    Node* seekToEnd(Node* head) {
        if (head == nullptr) {
            return head;
        }
        
        while (head->next != nullptr) {
            head = head->next;
        }
        
        return head;
    }
    
    void setPrevious(Node* head) {
        if (head == nullptr) {
            return;
        }
        
        Node* prev = head;
        head = head->next;
        while (head != nullptr) {
            head->prev = prev;
            head = head->next;
            prev = prev->next;
        }
    }
};
