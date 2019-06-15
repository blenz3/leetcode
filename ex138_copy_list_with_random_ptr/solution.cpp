/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
     
        // Maintain a map of original pointers to their corresponding copy pointer
        std::unordered_map<Node*, Node*> new_pointer_map;
        
        auto root = new Node(head->val, head->next, head->random);
        Node* new_runner = root;
        
        new_pointer_map[head] = root;
        
        // Walk the original array copy the values over. We'll walk the list a second time to add other things
        auto n = head->next;
        while (n != nullptr)
        {
            // allocate the copied node and add the pointers to our hash table
            new_runner->next = new Node(n->val, n->next, n->random);
            new_pointer_map[n] = new_runner->next;
            
            n = n->next;
            new_runner = new_runner->next;
        }
        
        // Traverse the copied array and resolve the random pointers
        n = root;
        while (n != nullptr)
        {
            n->random = new_pointer_map[n->random];
            n = n->next;
        }
        
        return root;
    }
};