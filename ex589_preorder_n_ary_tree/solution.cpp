/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> values;
        traverse(root, values);
        return values;
    }
    
    
private:
    void traverse(Node*& root, vector<int>& values) {
        if (root == nullptr)
            return;
        
        values.push_back(root->val);
        for (auto& child : root->children) {
            traverse(child, values);
        }
    }
};
