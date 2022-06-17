class Solution {
public:
    
    // Plan
    //   - Build a tree representing the filesystem path.
    //   - Once we have reached the end of the string then we 
    //     then walk from the root to the first node
    string simplifyPath(const string& path) {
        auto splitPath = split(path, '/');
        Node* root = new Node();
        Node* current = root;

        for (auto& directory : splitPath) {
            if (directory == ".") {
                // Nothing to do since we are just referring to ourself
                continue;
            } else if (directory == "..") {
                // Refer back up one level
                current = current->getParent();
            } else {
                // get or create a new child directory
                current = current->getChild(directory);
            }
        }
        
        // Go back to root from the current pointer 
        stack<Node*> directories;
        while (!current->isRoot()) {
            directories.push(current);
            current = current->getParent();
        }
        
        stringstream ss;
        if (directories.empty()) {
            ss << "/";
        }
        
        while (!directories.empty()) {
            auto top = directories.top();
            directories.pop();
            ss << "/" << top->val;
        }
        
        
        
        return ss.str();
    }
    
    
private:
    
    vector<string> split(const string& s, char delim) {
        vector<string> out;
        auto start = 0U;
        auto end = s.find(delim);
        while (end != std::string::npos)
        {
            auto substr = s.substr(start, end - start);
            if (!substr.empty()) {
                out.push_back(substr);    
            }
            start = end + 1;
            end = s.find(delim, start);
        }
        
        // Get the last group
        auto substr = s.substr(start, end - start - 1);
        if (!substr.empty())  {
            out.push_back(substr);
        }
        return out;
    }
    
    struct Node {
        string val;
        Node* parent;
        vector<Node*> children;
        
        Node() 
            : val("")
            , parent(nullptr)
            , children()
        {

        }
        
        Node(const string& s, Node* parent_) 
            : val(s)
            , parent(parent_)
            , children()
        {

        }
        
        bool isRoot() const {
            return parent == nullptr;
        }
        
        Node* getParent() const {
            if (parent == nullptr)
                return const_cast<Node*>(this);
            
            return parent;
        }
        
        Node* getChild(const std::string& directory) {
            auto findIt = std::find_if(
                children.begin(),
                children.end(),
                [directory](const Node* node) {
                    return (node->val == directory);
                }
            );
        
            // Nothing found create and return child
            Node* child = nullptr;
            if (findIt == children.end()) {
                children.push_back(new Node(directory, this));
                child = children.back();
            } else {
                child = *findIt;
            }
            
            return child;
        }
        
    };
};
