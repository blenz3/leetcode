class Solution {
public:

    struct Rectangle
    {
        int x1;
        int y1;
        int x2;
        int y2;
        
        Rectangle(vector<int>& r)
            : x1(r[0])
            , y1(r[1])
            , x2(r[2])
            , y2(r[3])
        {
            
        }
        
        bool overlaps(const Rectangle& rhs)
        {
            return (x1 < rhs.x2 && x2 > rhs.x1 && y1 < rhs.y2 && y2 > rhs.y1);
        }
    };
    
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        Rectangle r1(rec1), r2(rec2);
        
        return r1.overlaps(r2);
    }
};