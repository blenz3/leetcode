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
    int maxDepth(Node* root) {
        if (root == nullptr) 
            return 0;
        return findMaxDepth(root, 1);
    }
    
private:
    int findMaxDepth(Node* root, int currentDepth) {
        if (root == nullptr) {
            return currentDepth;
        }
        
        int maxNodeDepth = currentDepth;
        for (auto node : root->children) {
            maxNodeDepth = std::max(findMaxDepth(node, currentDepth + 1), maxNodeDepth);
        }
        
        return maxNodeDepth;
        
    }
};
