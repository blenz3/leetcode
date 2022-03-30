/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Strategy
//   - Seek to first node
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        traverseLeft(root);
    }
    
    int next() {
        auto* current = nodes.top();
        nodes.pop();
        if (current->right != nullptr)
            traverseLeft(current->right);
        
        return current->val;
    }
    
    bool hasNext() {
        return !nodes.empty();
    }
    
private:
    void traverseLeft(TreeNode* root) {
        while (root != nullptr) {
            nodes.push(root);
            root = root->left;
        }
    }
    
    stack<TreeNode*> nodes;
};

#if 0
// Iterate on construction and cache the results
class BSTIterator {
public:
    BSTIterator(TreeNode* root) : current(-1) {
        traverse(root);
        size = values.size() - 1;
    }
    
    int next() {
        return values[++current];
    }
    
    bool hasNext() {
        return current < size;
    }
    
private:
    void traverse(TreeNode* root) {
        if (root == nullptr)
            return; 
        
        traverse(root->left);
        values.push_back(root->val);
        traverse(root->right);
    }
    
    int current;
    int size;
    vector<int> values;
};
#endif

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
