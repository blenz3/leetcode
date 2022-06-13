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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        traverse(root, result, 0);
        return result;
    }
    
private:
    
    void traverse(Node* root, vector<vector<int>>& levels, size_t depth)  {
        if (root == nullptr) {
            return;
        }
        
        // Add new level
        if (depth == levels.size()) {
            levels.push_back(std::vector<int>{root->val});
        } else {
            levels[depth].push_back(root->val);
        }
        
        // Keep traversing
        for (auto child : root->children) {
            traverse(child, levels, depth + 1);
        }
    }
};
