/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec 
{
public:
    
    void preOrderTraversal(TreeNode* root, std::vector<std::string>& vals)
    {
        if (root == nullptr)
        {
            vals.push_back("null");
            return;
        }
        
        vals.push_back(std::to_string(root->val));
        preOrderTraversal(root->left, vals);
        preOrderTraversal(root->right, vals);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        std::vector<std::string> vals;
        preOrderTraversal(root, vals);
        
        std::string serialized_string;
        for (auto val : vals)
        {
            serialized_string += val + " ";
        }
        
        return (serialized_string.empty()) ? serialized_string : serialized_string.substr(0, serialized_string.length() - 1);
        
    }
    
    void insertVals(TreeNode*& n, std::list<std::string>& vals)
    {
        auto current_val = vals.front();
        vals.pop_front();
        
        if (current_val == "null")
        {
            return; // we are done this was always going to be a leaf
        }
        
        n = new TreeNode(std::stoi(current_val));
        insertVals(n->left, vals);
        insertVals(n->right, vals);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        TreeNode* out(nullptr);
        
        std::stringstream ss(data);
        
        std::string next_val;
        std::list<std::string> vals;
        while (ss >> next_val)
        {
           vals.push_back(next_val);
        }
        
        insertVals(out, vals);
        
        return out;
    }
    
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));