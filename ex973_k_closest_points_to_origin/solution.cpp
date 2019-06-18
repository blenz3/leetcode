struct Pt
{
    int x;
    int y;
    
    Pt(int x_, int y_)
        : x(x_)
        , y(y_)
    {
            
    }
    
    double distanceFromOrigin() const
    {
        return sqrt((x * x) + (y * y));
    }
};

struct PointCmp
{
    bool operator()(const Pt& lhs, const Pt& rhs) const
    {
        return lhs.distanceFromOrigin() > rhs.distanceFromOrigin();
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
    {
        std::priority_queue<Pt, std::vector<Pt>, PointCmp> q;
        for (auto& point : points)
        {
            q.push({ point[0], point[1] });
        }
        
        std::vector<vector<int>> out;
        while (!q.empty() && K != 0)
        {
            auto top = q.top();
            out.push_back({ top.x, top.y });
            q.pop();
            K--;
        }
        
        return out;
    }
};