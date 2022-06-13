/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// In order traversal for a BST will always result in the same structure when recreated so we'll just do that
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        
        vector<int> path;
        traverse(root, path);
        
        // Create a space delimited string of values
        stringstream ss;
        for (int i = 0; i < path.size() - 1; ++i) {
            ss << path[i] << " ";
        }
        
        ss << path.back();
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        
        // Parse the space delimited string of values
        stringstream ss(data);
        int val;
        vector<int> values;
        while (ss >> val) {
            values.push_back(val);
        }
        
        // Rebuild that bad boi
        return recreateTree(values);
    }
    
private:
    
    void traverse(TreeNode* root, vector<int>& path) {
        if (root == nullptr)
            return;
        
        path.push_back(root->val);
        traverse(root->left, path);
        traverse(root->right, path);
    }
    
    TreeNode* recreateTree(const vector<int>& path) {
        if (path.empty())
            return nullptr;
        
        TreeNode* root = new TreeNode(path[0]);
        for (int i = 1; i < path.size(); ++i) {
            insertNode(root, path[i]);
        }
        
        return root;
    }
    
    void insertNode(TreeNode* root, int val) {
        if (root == nullptr)
            return;
        
        if (root->val < val && root->right == nullptr) {
            root->right = new TreeNode(val);
        } else if (root->val > val && root->left == nullptr) {
            root->left = new TreeNode(val);
        } else if (root->val < val) {
            insertNode(root->right, val);
        } else {
            insertNode(root->left, val);
        }
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
