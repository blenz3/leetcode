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
    // Do a level order traversal to connect the pointers together
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        
        queue<pair<Node*, int /*level*/>> q;
        q.push(make_pair(root, 0));
        
        int currentLevel = 0;
        Node* levelNext = nullptr;
        while (!q.empty()) {
            auto top = q.front();
            if (top.second > currentLevel) {
                currentLevel++;
                levelNext = nullptr;
            }
            
            top.first->next = levelNext;
            levelNext = top.first;
            
            if (top.first->right != nullptr)
                q.push(make_pair(top.first->right, top.second + 1));
            
            if (top.first->left != nullptr)
                q.push(make_pair(top.first->left, top.second + 1));
            
            q.pop();
        }
        return root;
    }
#if 0
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
#endif
};
