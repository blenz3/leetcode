/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<Node*> nexts;
        traverse(root, 0, nexts);
        return root;
    }
    
    void traverse(Node* root, int level, vector<Node*>& nexts) {
        if (root == nullptr) {
            return;
        }
        
        if (level + 1 > nexts.size()) {
            nexts.push_back(root);
            root->next = nullptr;
        } else {
            root->next = nexts[level];
            nexts[level] = root;
        }
        
        traverse(root->right, level + 1, nexts);
        traverse(root->left, level + 1, nexts);
    }
};
