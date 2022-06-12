class Vector2D {
public:

    Vector2D(const vector<vector<int>>& vec) 
        : flat()
        , index(0)
    {
        for (auto& inner : vec) {
            for (auto val : inner) {
                flat.push_back(val);
            }
        }
    }
    
    int next() {
        return flat[index++];
    }
    
    bool hasNext() {
       return (index < flat.size());
    }
    
private:
    vector<int> flat;
    size_t index;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
