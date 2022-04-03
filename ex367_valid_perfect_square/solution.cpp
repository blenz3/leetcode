class Solution {
public:
    bool isPerfectSquare(int num) {
        int root = static_cast<int>(::sqrt(num));
        return (root * root == num);
    }
};
